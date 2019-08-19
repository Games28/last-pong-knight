#pragma once
#include "ArtLaser.h"
class Graphics;
#include <random>
#include <math.h>
#include "Collider.h"
#include "Vec2.h"
class Laser 
{
public:
	Laser() = default;
	Laser(Vec2& loc);
	Laser(Vec2& loc, std::mt19937& rng);
	void Draw(Graphics& gfx);
	void Init(Vec2& loc, std::mt19937& rng);
	void Respawn(Vec2& loc, std::mt19937& rng);
	void DrawLaserUp(Graphics& gfx);
	void DrawLaserDown(Graphics& gfx);
	void Update();
public:
	
	void (ArtLaser::* DrawLaser)(int, int, Graphics&);
	Vec2 loc;
	Vec2 vel;
	Collider collider;
	ArtLaser Art;
};

