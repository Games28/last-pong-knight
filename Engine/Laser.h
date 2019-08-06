#pragma once
class Graphics;
class ArtLaser;
#include <random>
#include <math.h>
#include "Collider.h"
#include "Trooper.h"
class Laser  : public Trooper
{
public:
	Laser() = default;
	
	Laser(Vec2& loc);
	Laser(Vec2& loc, std::mt19937& rng);
	void Draw(Graphics& gfx);
	void Init(Vec2& loc, std::mt19937& rng);
	void Respawn(Vec2& loc, std::mt19937& rng);
	
	void Update();
public:
	
	void (ArtLaser::* DrawLaser)(int, int, Graphics&);
	
	Vec2 vel;
	Collider collider;
	//ArtLaser Art;
};

