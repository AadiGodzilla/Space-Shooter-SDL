#pragma once

#include "Entity.h"
#include "Text.h"
#include "Player.h"

#include <string>
#include <memory>

class HPCounter : public Text, public Entity
{
private:
	std::string m_hp_prefix;
public:
	HPCounter(SDL_Renderer* renderer, const char* font, uint32_t x, uint32_t y, uint32_t size);
	~HPCounter();
	void update_hp_text(int32_t health);
	void render();
private:
};
