#include "HPCounter.h"

#include <string>

HPCounter::HPCounter(SDL_Renderer* renderer, const char* font, uint32_t x, uint32_t y, uint32_t size)
	:m_hp_prefix("HEALTH: "),
	Text(renderer, m_hp_prefix.c_str(), font, x, y, size),
	Entity(renderer, "res/player.png", { static_cast<int>(x - (size + 10)), static_cast<int>(y), static_cast<int>(size), static_cast<int>(size)})
{
	update_hp_text(5);
}

HPCounter::~HPCounter()
{
	Text::~Text();
	Entity::~Entity();
}

void HPCounter::update_hp_text(int32_t health)
{
	SDL_DestroyTexture(Text::m_texture);
	Text::m_texture = nullptr;

	std::string hp_str = std::to_string(health);

	TTF_SizeText(m_font, hp_str.c_str(), &Text::m_rect.w, &Text::m_rect.h);

	Text::m_surface = TTF_RenderText_Solid(m_font, hp_str.c_str(), {255, 255, 255, 255});
	Text::m_texture = SDL_CreateTextureFromSurface(Text::m_renderer, Text::m_surface);

	SDL_FreeSurface(Text::m_surface);
	Text::m_surface = nullptr;
}

void HPCounter::render()
{
	Entity::render();
	Text::render();
}