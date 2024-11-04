#pragma once

#include "Entity.h"
#include "Timer.h"
#include "Bullet.h"

#include <vector>
#include <memory>

class Enemy : public Entity
{
	uint32_t m_speed, m_bx, m_by;
	bool m_swap;
public:
	Enemy(SDL_Renderer* renderer, const char* image, SDL_Rect& rect, int boundX, int boundY);
	void destroy() override;
	SDL_Rect* rect() override;
	void update(std::vector<Bullet>& bullets);
	void render() override;
private:
	void shoot(std::vector<Bullet>& bullets);
};
