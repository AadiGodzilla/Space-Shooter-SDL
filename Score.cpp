#include "Score.h"
#include <iostream>
#include <string>

Score::Score(SDL_Renderer* renderer, const char* font, SDL_Rect& rect) :
	m_score(0), Text(renderer, "", font, rect)
{
	SDL_FreeSurface(m_surface);
	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;
	m_surface = nullptr;
}

Score::~Score()
{
	Text::~Text();
}

void Score::add_score()
{
	m_score++;
}

void Score::reset_score()
{
	m_score = 0;
}

void Score::render()
{
	std::string score_str = "SCORE: ";
	score_str += std::to_string(m_score);

	m_surface = TTF_RenderText_Solid(m_font, score_str.c_str(), {255, 255, 255, 255});
	m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);

	SDL_FreeSurface(m_surface);
	m_surface = nullptr;

	Text::render();

	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;
}