#include "HPCounter.h"

#include <string>

HPCounter::HPCounter(SDL_Renderer* renderer, const char* font, SDL_Rect& rect)
	:m_hp_prefix("HEALTH: "), Text(renderer, m_hp_prefix.c_str(), font, rect)
{
	update_hp_text(5);
}

HPCounter::~HPCounter()
{
	Text::~Text();
}

void HPCounter::update_hp_text(int32_t health)
{
	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;

	std::string hp_str = m_hp_prefix;
	hp_str += std::to_string(health);

	m_surface = TTF_RenderText_Solid(m_font, hp_str.c_str(), {255, 255, 255, 255});
	m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);

	SDL_FreeSurface(m_surface);
	m_surface = nullptr;
}

void HPCounter::render()
{
	Text::render();
}