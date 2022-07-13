#pragma once
#include "game.h"
class Map
{
public:
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:
	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* sky;
	SDL_Texture* water;

	int map[20][25];

};

