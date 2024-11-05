#pragma once

#include "Text.h"
#include "Entity.h"

#include <string>

class Score : public Text, public Entity
{
private:
	uint32_t m_score;
	const char* image;
	const std::string m_score_prefix;
public:
	Score(SDL_Renderer* renderer, const char* font, uint32_t x, uint32_t y, uint32_t size);
	~Score();
	void add_score();
	void reset_score();
	void render() override;
private:
	void update_score_text();
};
