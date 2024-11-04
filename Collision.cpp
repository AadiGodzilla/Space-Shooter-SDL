#include "Collision.h"

#include <iostream>
#include <vector>

#include "Game.h"
#include "Score.h"

void Collision::enemy_bullet_collision(
	std::vector<Enemy>& enemies, 
	std::vector<Bullet>& bullets, 
	std::vector<Entity>& explosions,
	std::unique_ptr<Score>& score
)
{
	std::vector<int> enemies_to_remove, bullets_to_remove;

	if (!enemies.empty() && !bullets.empty())
	{
		for (int i = bullets.size() - 1; i >= 0; --i) 
		{
			for (int j = enemies.size() - 1; j >= 0; --j)
			{
				if (SDL_HasIntersection(enemies[j].rect(), bullets[i].rect()) && bullets[i].get_dir())
				{
					explosions.emplace_back(Entity(Game::get_renderer(), "res/explosion.png", *enemies[j].rect()));
					enemies_to_remove.emplace_back(j);
					bullets_to_remove.emplace_back(i);
					score->add_score();
					break;
				}
			}
		}
	}

	for (int i = bullets_to_remove.size() - 1; i >= 0; --i)
		bullets.erase(bullets.begin() + bullets_to_remove[i]);

	for (int i = enemies_to_remove.size() - 1; i >= 0; --i)
		enemies.erase(enemies.begin() + enemies_to_remove[i]);
}

void Collision::player_bullet_collision(
	std::unique_ptr<Player>& player, 
	std::vector<Bullet>& bullets, 
	std::vector<Entity>& explosions
)
{
	std::vector<int> bullets_to_remove;

	if (!bullets.empty())
	{
		for (int i = bullets.size() - 1; i >= 0; --i)
		{
			if (SDL_HasIntersection(bullets[i].rect(), player->rect()) && !bullets[i].get_dir())
			{
				bullets_to_remove.emplace_back(i);
				player->hit();
				if (player->get_hp() == 0)
				{
					explosions.emplace_back(Entity(Game::get_renderer(), "res/explosion.png", *player->rect()));
					player.reset();
					break;
				}
			}
		}
	}

	for (int i = bullets_to_remove.size() - 1; i >= 0; --i)
		bullets.erase(bullets.begin() + bullets_to_remove[i]);
}
