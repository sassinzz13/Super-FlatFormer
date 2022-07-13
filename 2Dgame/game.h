#pragma once
#include "SDL.h"
#include <iostream>

class Game
{
	//gameclass
public: 
	//constructor for constructing the game
	Game();
	//deconstructor for when we close it
	~Game();

	//initialization
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	
	//will update all our game objects
	void update();
	void render();

	//memory management
	void clean();

	//letting the system know that the game is still running
	bool running() { return isRunning;  }

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

