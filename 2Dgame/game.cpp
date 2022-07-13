#include "game.h"
#include <stdio.h>


Game::Game()
{}
Game::~Game()
{}

//declare init
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	//if you want fullscreen just paste in true or false to the arguement
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	//initialize sdl
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "initializing?" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		//check if windows been done properly
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}

		//renderer
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}

		//if it works
		isRunning = true;

	}
	//if sdl doesnt initialize correctly we have a boolean thatll set to false
	//so when we check for it on the main loop if it sees that its false and it wont run the game
	else {
		isRunning = false;
	}
}

void Game::handleEvents()
{
	//sdl quit?
	//stops the game from running on its next loop
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
			break;

	default:
		break;	
	}
}

//update function for positions
void Game::update()
{
	cnt++;
	std::cout << cnt << std::endl;
}

void Game::render()
{
	//render are objects in the screen
	SDL_RenderClear(renderer);
	//this is where we would add stuffs to render
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	//when we quit the game we wanna clean up
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "game cleaned" << std::endl;
}
