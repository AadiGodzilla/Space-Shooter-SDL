#pragma once

#include "Text.h"
#include "Player.h"

#include <string>
#include <memory>

class HPCounter : public Text
{
private:
	std::string m_hp_prefix;
public:
	HPCounter(SDL_Renderer* renderer, const char* font, SDL_Rect& rect);
	~HPCounter();
	void update_hp_text(int32_t health);
	void render();
private:
};
