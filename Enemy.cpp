#include "Enemy.h"

#include <cstdlib>
#include <iostream>

Enemy::Enemy(SDL_Renderer* renderer, const char* image, SDL_Rect& rect, int boundX, int boundY) :
	m_bx(boundX), m_by(boundY), m_speed(10.0f), m_swap(rand() % 2), Entity(renderer, image, rect)
{}

void Enemy::destroy()
{
	Entity::~Entity();
}

SDL_Rect* Enemy::rect()
{
	return Entity::rect();
}

void Enemy::update(std::vector<Bullet>& bullets)
{
	if (m_swap)
		m_rect.x += static_cast<int>(m_speed);
	else
		m_rect.x -= static_cast<int>(m_speed);

	if (m_rect.x + m_rect.w > m_bx || m_rect.x < 0)
	{
		m_rect.y += m_rect.w + 10;
		m_swap = !m_swap;
	}

	shoot(bullets);
}
void Enemy::shoot(std::vector<Bullet>& bullets)
{
	if (b_timer.interval(0.75f))
	{
		SDL_Rect b_rect = { m_rect.x + (m_rect.w / 2) - 8, m_rect.y + 30, 16, 20 };
		bullets.emplace_back(Bullet(m_renderer, "res/bullet2.png", b_rect, false));
	}
}

void Enemy::render()
{
	Entity::render();
}