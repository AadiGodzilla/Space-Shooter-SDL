#include "Player.h"

#include <iostream>

Player::Player(SDL_Renderer* renderer, const char* image, SDL_Rect& rect, int boundX, int boundY) :
	m_speed(15.0f), m_bx(boundX), m_by(boundY), Entity(renderer, image, rect), m_hp(5)
{
}

Player::~Player()
{
	Entity::destroy();
}

SDL_Rect* Player::rect()
{
	return Entity::rect();
}

int32_t Player::get_hp()
{
	return m_hp;
}

void Player::hit()
{
	m_hp--;
}

void Player::update(const Uint8* keyboard, std::vector<Bullet>& bullets)
{
	if (keyboard[SDL_SCANCODE_A]) m_rect.x -= static_cast<int>(m_speed);
	if (keyboard[SDL_SCANCODE_D]) m_rect.x += static_cast<int>(m_speed);
	if (keyboard[SDL_SCANCODE_SPACE]) shoot(bullets);

	if (m_rect.x > 800 - m_rect.w) m_rect.x = m_bx - m_rect.w;
	if (m_rect.x < 0) m_rect.x = 0;
}

void Player::shoot(std::vector<Bullet>& bullets)
{
	SDL_Rect rect = { m_rect.x + (m_rect.w / 2) - 8, m_rect.y - 30, 16, 20 };
	if (m_timer.interval(250.0f))
		bullets.emplace_back(Bullet(m_renderer, "res/bullet1.png", rect, true));
}

void Player::render()
{
	Entity::render();
}