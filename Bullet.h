#pragma once

#include "Entity.h"

class Bullet : public Entity
{
	uint32_t m_speed;
	bool m_dir;
public:
	Bullet(SDL_Renderer* renderer, const char* image, SDL_Rect& rect, bool dir);
	void destroy() override;
	bool get_dir();
	void update();
	SDL_Rect* rect() override;
	void render() override;
};
