#pragma once

#include <SDL2/SDL.h>
#include <memory>

#include "Timer.h"

class Entity
{
protected:
	SDL_Rect m_rect;
	SDL_Renderer* m_renderer;
	SDL_Surface* m_surface;
	SDL_Texture* m_texture;
	Timer m_timer;

public:
	Entity();
	Entity(SDL_Renderer* renderer, const char* image, SDL_Rect& rect);
	virtual void destroy();
	virtual SDL_Rect* rect();
	virtual Timer& get_timer();
	virtual void render();
};
