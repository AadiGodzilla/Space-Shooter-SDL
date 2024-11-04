#pragma once

#include <SDL2/SDL.h>

class Game
{
	const char* m_title;
	uint32_t m_screenwidth, m_screenheight;
	bool m_running, m_pause, m_gameover;
	SDL_Window* m_window;
	static SDL_Renderer* m_renderer;
	SDL_Event m_event;

	void update();
	void render();
	void reset();
public:
	Game();
	~Game();
	static SDL_Renderer* get_renderer();
	void run();
};
