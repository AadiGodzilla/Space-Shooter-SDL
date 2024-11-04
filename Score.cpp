#include "Score.h"
#include <iostream>
#include <string>

Score::Score(SDL_Renderer* renderer, const char* font, SDL_Rect& rect) :
	m_score(0), m_score_prefix("SCORE: "), Text(renderer, m_score_prefix.c_str(), font, rect)
{
	update_score_text();
}

Score::~Score()
{
	Text::~Text();
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
	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;

	std::string m_score_str = m_score_prefix;
	m_score_str += std::to_string(m_score);

	m_surface = TTF_RenderText_Solid(m_font, m_score_str.c_str(), {255, 255, 255, 255});
	m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);

	SDL_FreeSurface(m_surface);
	m_surface = nullptr;
}

void Score::render()
{
	Text::render();
}