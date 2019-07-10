#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "ArtLaser.h"
#include <random>
#include <math.h>
#include "Collider.h"
#include "ArtCharacter.h"
class Laser
{
public:
	Laser() = default;
	
	Laser(Vec2& loc);
	Laser(Vec2& loc, std::mt19937& rng);
	void Draw(Graphics& gfx);
	void Init(Vec2& loc);
	void Respawn(Vec2& loc, std::mt19937& rng);
	void Move(Vec2& MoveAmount);
	void Update();
public:
	struct ArtLoc
	{
		Vec2 troper;
	};
	ArtLoc artloc;
	void (ArtLaser::* DrawLaser)(int, int, Graphics&);
	Vec2 loc;
	Vec2 vel;
	Collider collider;
	ArtCharacter artch;
	ArtLaser Alaser;
};

