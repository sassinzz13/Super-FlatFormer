//pokemon like game?
//zelda?
//to the moon?

//Main function where we call everything
#include <iostream>
#include "game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();
	//initialize sdl so gameIsrunning can go true : D

	game->init("PokeMoonZel", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 600, false);

	//game loop

	while (game->running())
	{
		//we run our statements
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}