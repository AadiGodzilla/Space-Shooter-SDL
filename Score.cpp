#include "Score.h"
#include <iostream>
#include <string>
#include <SDL2/SDL_image.h>

Score::Score(SDL_Renderer* renderer, const char* font, uint32_t x, uint32_t y, uint32_t size) :
	m_score(0), m_score_prefix(""), image("res/enemy.png"),
	Text(renderer, m_score_prefix.c_str(), font, x, y, size),
	Entity(renderer, "res/enemy.png", {static_cast<int>(x - (size + 10)), static_cast<int>(y), static_cast<int>(size), static_cast<int>(size)})
{
	update_score_text();
}

Score::~Score()
{
	Text::~Text();
	Entity::~Entity();
}

void Score::add_score()
{
	m_score++;
	update_score_text();
}

void Score::reset_score()
{
	m_score = 0;
	update_score_text();
}

void Score::update_score_text()
{
	SDL_DestroyTexture(Text::m_texture);
	Text::m_texture = nullptr;

	std::string m_score_str = std::to_string(m_score);

	TTF_SizeText(m_font, m_score_str.c_str(), &Text::m_rect.w, &Text::m_rect.h);

	Text::m_surface = TTF_RenderText_Solid(m_font, m_score_str.c_str(), {255, 255, 255, 255});
	Text::m_texture = SDL_CreateTextureFromSurface(Text::m_renderer, Text::m_surface);

	SDL_FreeSurface(Text::m_surface);
	Text::m_surface = nullptr;
}

void Score::render()
{
	Entity::render();
	Text::render();
}