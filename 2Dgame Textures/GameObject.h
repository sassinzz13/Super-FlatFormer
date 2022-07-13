#pragma once
#include "game.h"
class GameObject
{
public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int xpos;
	int ypos;

	//the draw init 
	SDL_Texture* objectTexture;
	//to display the textures we need a rectangle
	SDL_Rect srcRect, destRect;
	//SDL_Renderer* renderer;

};

