//pokemon like game?
//zelda?
//to the moon?
//assets
//https://kenney.nl/assets?q=2d


//Main function where we call everything
#include <iostream>
#include "game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	//frame limiters
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	//how long to run
	Uint32 frameStart;
	int frameTime;

	game = new Game();
	//initialize sdl so gameIsrunning can go true : D

	game->init("PokeMoonZel", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 640, false);

	//game loop

	while (game->running())
	{
		//frame running
		frameStart = SDL_GetTicks();


		//we run our statements
		game->handleEvents();
		game->update();
		game->render();

		//frametime
		//updating our objects and rendering it 
		frameTime = SDL_GetTicks() - frameStart;

		//delays our frame
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}


	}

	game->clean();
	return 0;
}