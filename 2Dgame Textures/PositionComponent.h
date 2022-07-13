#pragma once
#include "Components.h"

class PositionComponent : public Component
{
private:
	int xpos = 0;
	int ypos = 0;

public:
	//spawn pos? 
	PositionComponent()
	{
		xpos = 0;
		ypos = 0;
	}
	//sprite position
	PositionComponent(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	/*
int x() { return xpos; }
int y() { return ypos; }



void init() override
{
	xpos = 0;
	ypos = 0;
}
*/

void update() override
{
	xpos++;
	ypos++;
}

int x() { return xpos; }
void x(int x) { xpos = x; }
int y() { return ypos; }
void y(int y) { ypos = y; }
void setPos(int x, int y) { xpos = x; ypos = y; }

/*
void setPos(int x, int y)
{
	xpos = x;
	ypos = y;
}
*/
};