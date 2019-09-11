#pragma once
class Graphics;
class Color;

#include "Vec2.h"

class ArtCharacter
{
public:
	
	ArtCharacter();
	void Statue(int x, int y, Graphics& gfx);
	void RobeLeft(int x, int y, Graphics& gfx);
	void RobeRight(int x, int y, Graphics& gfx);
	void RobeFront(int x, int y, Graphics& gfx);
	void RobeReady(int x, int y, Graphics& gfx);
	void StormTrooper(int x, int y, Graphics& gfx);
	void TrooperLeftFootFront(int x, int y, Graphics& gfx);
	void TrooperRightFootFront(int x, int y, Graphics& gfx);
	
public:
	
	Color *c;
};

