#include "GameObject.h"
#include "TextureManager.h"
//game objects
GameObject::GameObject(const char* texturesheet, int x, int y)
{
	//we wanna assign our renderer
	//renderer = ren;
	objectTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void GameObject::Update()
{
	//movement code and behaviours
	
	/* move it on the top just some random c# optimizer shit
	xpos = 0;
	ypos = 0;
	*/

	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.w * 2;
}

void GameObject::Render()
{
	//draws our texture
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}