#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Text
{
protected:
	SDL_Rect m_rect;
	TTF_Font* m_font = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	SDL_Surface* m_surface = nullptr;
	SDL_Texture* m_texture = nullptr;
public:
	Text();
	Text(SDL_Renderer* renderer, const char* text, const char* font, SDL_Rect& rect);
	~Text();
	virtual void render();
};
