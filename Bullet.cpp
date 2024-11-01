#include "Bullet.h"
#include <iostream>

Bullet::Bullet(SDL_Renderer* renderer, const char* image, SDL_Rect& rect, bool dir) : 
	m_speed(20.0f), m_dir(dir), Entity(renderer, image, rect)
{}

void Bullet::destroy()
{
	Entity::~Entity();
}

SDL_Rect* Bullet::rect()
{
	return Entity::rect();
}

bool Bullet::get_dir()
{
	return m_dir;
}

void Bullet::update()
{
	if (m_dir) m_rect.y -= static_cast<int>(m_speed);
	else m_rect.y += static_cast<int>(m_speed);
}

void Bullet::render()
{
	Entity::render();
}