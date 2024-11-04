#include "HPCounter.h"
#include <string>

HPCounter::HPCounter(SDL_Renderer* renderer, const char* font, SDL_Rect& rect)
	: Text(renderer, "", font, rect)
{
	
}

HPCounter::~HPCounter()
{
	Text::~Text();
}

void HPCounter::render(std::unique_ptr<Player>& player)
{
	std::string hp_str = "HEALTH: ";

	if (player->get_hp() <= 0) hp_str += std::to_string(0);
	else hp_str += std::to_string(player->get_hp());

	m_surface = TTF_RenderText_Solid(m_font, hp_str.c_str(), {255, 255, 255, 255});
	m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);
	SDL_FreeSurface(m_surface);

	Text::render();

	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;
}