#include "game.h"
#include <stdio.h>
#include "TextureManager.h"
//#include "GameObject.h"
#include "Map.h"
#include "Components.h"
//#include "ECS.h"
//#include "Components.h"
//game class for textures
/* removable replace it with the gameobject
SDL_Texture* playerTex;//initialize this in the init func
SDL_Rect srcR, destR;//for scaling
*/


/*GameObject* player;
GameObject* enemy;
*/
Map* map;


SDL_Renderer* Game::renderer = nullptr;

//create a new manager
Manager manager;
auto& player(manager.addEntity());//creates player

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

	/* can be removed now and replace it with playerTex
	//make a surface
	SDL_Surface* tmpSurface = IMG_Load("assets/player1.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	
	//clean cause we dont need surface
	SDL_FreeSurface(tmpSurface);
	*/

	//player = new GameObject("assets/player1.png", 0, 0);
	//enemy = new GameObject("assets/enemy1.png", 50, 50);
	map = new Map();//skybox

	//newPlayer.addComponent<PositionComponent>();

	//start position
	player.addComponent<PositionComponent>(0, 0);
	player.addComponent<SpriteComponent>("assets/player1.png");
	
	
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
	/* remove all this now since we have a more optimized way to code it
	cnt++;
	destR.h = 64;
	destR.w = 64;
	destR.x = cnt;

	std::cout << cnt << std::endl;
	*/

	manager.refresh();
	manager.update();

	//swap texture logic
	if (player.getComponent<PositionComponent>().x() > 100)
	{
		player.getComponent<SpriteComponent>().setTex("assets/enemy1.png");
	}
	
	/*player->Update();
	enemy->Update();
	
	std::cout << newPlayer.getComponent<PositionComponent>().x() << "," <<
		newPlayer.getComponent<PositionComponent>().y() << std::endl;*/
	
}

void Game::render()
{
	//render are objects in the screen
	SDL_RenderClear(renderer);

	map->DrawMap();
	//All our textures will be renderered here
	//SDL_RenderCopy(renderer, playerTex, NULL, &destR);//make a rect to scale it
	/*player->Render();
	enemy->Render();*/
	manager.draw();

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
