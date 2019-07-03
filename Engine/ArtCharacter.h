#pragma once
#include "graphics.h"
#include "Vec2.h"
class ArtCharacter
{
public:
	ArtCharacter() = default;
	void Statue(int x, int y, Graphics& gfx);
	void RobeLeft(int x, int y, Graphics& gfx);
	void RobeRight(int x, int y, Graphics& gfx);
	void RobeFront(int x, int y, Graphics& gfx);
	void StormTrooper(int x, int y, Graphics& gfx);
	
public:
	Color c[2] = { Colors::MakeRGB(250, 180, 80), Colors::MakeRGB(190,50,0) };
	
};

