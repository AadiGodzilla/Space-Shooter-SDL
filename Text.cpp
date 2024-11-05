#include "Text.h"

Text::Text() :
	m_renderer(nullptr), m_rect(), m_font(nullptr), m_surface(nullptr), m_texture(nullptr)
{

}

Text::Text(SDL_Renderer* renderer, const char* text, const char* font, uint32_t x, uint32_t y, uint32_t size) :
	m_renderer(renderer), 
	m_rect({static_cast<int>(x), static_cast<int>(y), static_cast<int>(size), static_cast<int>(size)}), 
	m_font(TTF_OpenFont(font, static_cast<int>(size))),
	m_surface(TTF_RenderText_Solid(m_font, text, { 255,255,255,255 })),
	m_texture(SDL_CreateTextureFromSurface(renderer, m_surface))
{
	TTF_SizeText(m_font, text, &m_rect.w, &m_rect.h);
	SDL_FreeSurface(m_surface);
	m_surface = nullptr;
}

Text::~Text()
{
	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;
}

void Text::render()
{
	if (this != nullptr)
		SDL_RenderCopy(m_renderer, m_texture, NULL, &m_rect);
}