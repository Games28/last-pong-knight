#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "ArtLaser.h"
class Laser
{
public:
	Laser(Vec2& loc, Vec2& vel);
	void Draw(Graphics& gfx);
public:
	Vec2 loc;
	Vec2 vel;
	
};

