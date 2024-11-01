#include "Game.h"

#include <memory>
#include <vector>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Player.h"
#include "Bullet.h"
#include "Timer.h"
#include "Enemy.h"
#include "Collision.h"
#include "Score.h"
#include "Text.h"
#include "HPCounter.h"

Timer m_timer, e_timer;
std::shared_ptr<Player> player;
std::shared_ptr<Score> score;
std::unique_ptr<Text> go_text, pa_text;
std::unique_ptr<HPCounter> hp_text;
std::vector<Bullet> bullets;
std::vector<Enemy> enemies;

Game::Game() :
	m_title("Game"), m_screenwidth(800), m_screenheight(600), m_running(true), m_pause(false), m_gameover(false), m_event(),
	m_window(SDL_CreateWindow(m_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screenwidth, m_screenheight, NULL)),
	m_renderer(SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED))
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();

	SDL_Rect p_rect = { static_cast<int>(m_screenwidth / 2), 500, 50, 50 };
	SDL_Rect go_rect = { static_cast<int>(m_screenwidth / 2) - 125, static_cast<int>(m_screenheight / 2) - 25, 250, 50 };
	SDL_Rect pa_rect = { static_cast<int>(m_screenwidth / 2) - 90, static_cast<int>(m_screenheight / 2) - 25, 180, 50 };
	SDL_Rect sc_rect = { 10, static_cast<int>(m_screenheight - 50), 150, 40 };
	SDL_Rect hp_rect = { static_cast<int>(m_screenwidth - 160), static_cast<int>(m_screenheight - 50), 150, 40 };

	player = std::make_shared<Player>(m_renderer, "res/player.png", p_rect, 
		static_cast<int>(m_screenwidth), static_cast<int>(m_screenheight));
	go_text = std::make_unique<Text>(m_renderer, "GAME OVER", "res/arial.ttf", go_rect);
	pa_text = std::make_unique<Text>(m_renderer, "PAUSE", "res/Arial.ttf", pa_rect);
	score = std::make_shared<Score>(m_renderer, "res/Arial.ttf", sc_rect);
	hp_text = std::make_unique<HPCounter>(m_renderer, "res/Arial.ttf", hp_rect);
}

void Game::update()
{
	while (SDL_PollEvent(&m_event))
	{
		switch (m_event.type)
		{
		case SDL_QUIT:
			m_running = false;
		case SDL_KEYDOWN:
			switch (m_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				m_pause = !m_pause;
			default:
				if (m_gameover)
				{
					enemies.clear();
					bullets.clear();
					SDL_Rect p_rect = { m_screenwidth / 2, 500, 50, 50 };
					player = std::make_shared<Player>(m_renderer, "res/player.png", p_rect, 
						static_cast<int>(m_screenwidth), static_cast<int>(m_screenheight));
					m_gameover = false;
				}
			}
		}
	}

	if (!m_pause && !m_gameover)
	{
		const Uint8* keyboard = SDL_GetKeyboardState(NULL);

		player->update(keyboard, bullets);

		if (e_timer.interval(1 + ((double)(rand() % 3))))
		{
			SDL_Rect e_rect = { rand() % (m_screenwidth - 50), 0, 50, 50 };
			enemies.push_back(Enemy(m_renderer, "res/enemy.png", e_rect, 
				static_cast<int>(m_screenwidth), static_cast<int>(m_screenheight)));
		}

		if (!enemies.empty())
		{
			for (auto& enemy : enemies)
				enemy.update(bullets);

			enemies.erase(std::remove_if(enemies.begin(), enemies.end(), 
				[&](Enemy& enemy) {
					return enemy.rect()->y > m_screenheight || enemy.rect()->y < 0;
				}), enemies.end());
		}

		if (!bullets.empty())
		{	
			for (auto& bullet : bullets)
				bullet.update();

			bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
				[&](Bullet& bullet) {
					return bullet.rect()->y > m_screenheight || bullet.rect()->y < 0;
				}), bullets.end());
		}

		Collision::enemy_bullet_collision(enemies, bullets, score);
		Collision::player_bullet_collision(player, bullets, score);
	}
	if (player == nullptr) m_gameover = true;
}

void Game::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);

	if (player != nullptr) player->render();

	for (auto& enemy : enemies) enemy.render();
	for (auto &bullet : bullets) bullet.render();

	if (m_gameover) go_text->render();
	else if (m_pause) pa_text->render();

	score->render();
	hp_text->render(player);

	SDL_RenderPresent(m_renderer);
}

void Game::run()
{
	while (m_running)
	{
		if (m_timer.interval(1.0f / 60.0f))
		{
			update();
			render();
		}
	}
}
