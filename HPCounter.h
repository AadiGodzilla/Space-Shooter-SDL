#pragma once

#include "Text.h"
#include "Player.h"

#include <memory>

class HPCounter : public Text
{

public:
	HPCounter(SDL_Renderer* renderer, const char* font, SDL_Rect& rect);
	~HPCounter();
	void render(std::unique_ptr<Player>& player);
};
