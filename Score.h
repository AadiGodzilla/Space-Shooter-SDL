#pragma once

#include "Text.h"

class Score : public Text
{
private:
	uint32_t m_score;
public:
	Score(SDL_Renderer* renderer, const char* font, SDL_Rect& rect);
	~Score();
	void add_score();
	void reset_score();
	void render() override;
};
