#include "Text.h"

Text::Text() :
	m_renderer(nullptr), m_rect(), m_font(nullptr), m_surface(nullptr), m_texture(nullptr)
{

}

Text::Text(SDL_Renderer* renderer, const char* text, const char* font, SDL_Rect& rect) :
	m_renderer(renderer), m_rect(rect), m_font(TTF_OpenFont(font, 128)),
	m_surface(TTF_RenderText_Solid(m_font, text, { 255,255,255,255 })),
	m_texture(SDL_CreateTextureFromSurface(renderer, m_surface))
{
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