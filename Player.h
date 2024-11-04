#pragma once

#include "Entity.h"
#include "Timer.h"
#include "Bullet.h"

#include <memory>
#include <vector>

class Player : public Entity
{
private:
	uint32_t m_bx, m_by, m_speed;
	int32_t m_hp;
public:
	Player(SDL_Renderer* renderer, const char* image, SDL_Rect& rect, int boundX, int boundY);
	~Player();
	SDL_Rect* rect() override;
	int32_t get_hp();
	void hit();
	void update(const Uint8* keyboard, std::vector<Bullet>& bullets);
	void shoot(std::vector<Bullet>& bullets);
	void render() override;
};
