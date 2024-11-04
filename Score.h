#pragma once

#include "Text.h"
#include <string>

class Score : public Text
{
private:
	uint32_t m_score;
	const std::string m_score_prefix;
public:
	Score(SDL_Renderer* renderer, const char* font, SDL_Rect& rect);
	~Score();
	void add_score();
	void reset_score();
	void render() override;
private:
	void update_score_text();
};
