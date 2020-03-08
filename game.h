#pragma once
#ifndef game_hpp
#define game_hpp

#include <SDL.h>
#include <iostream>
#include<SDL_image.h>


class game
{
public:
	game();
	~game();
	
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

#endif