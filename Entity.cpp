#include "Entity.h"
#include <SDL2/SDL_image.h>

Entity::Entity() :
	m_renderer(nullptr), m_rect(), m_surface(nullptr), m_texture(nullptr)
{}

Entity::Entity(SDL_Renderer* renderer, const char* image, SDL_Rect& rect) : 
	m_renderer(renderer), m_rect(rect), m_surface(IMG_Load(image)), 
	m_texture(SDL_CreateTextureFromSurface(m_renderer, m_surface))
{
	SDL_FreeSurface(m_surface);
	m_surface = nullptr;
}

void Entity::destroy()
{
	SDL_DestroyTexture(m_texture);
	m_texture = nullptr;
}

SDL_Rect* Entity::rect() 
{
	return &m_rect;
}

void Entity::render()
{
	if (this != nullptr)
		SDL_RenderCopy(m_renderer, m_texture, NULL, &m_rect);
}
