#pragma once
#include "Character.h"
#include "Laser.h"
class Graphics;

class Trooper : public Character
{
public:
	Trooper() = default;
	Trooper(Vec2& loc);
	void Draw(Graphics& gfx);
	
	void Rebound();
	void Collision(Collider& collide);
public:
	
	
	static const int lasermax = 3;
	static constexpr float laserseparation = 70.0f;
	
	static constexpr float trooperwidth = 82.0f;
	static constexpr float trooperheight = 82.0f;
	static constexpr int numberAcrossMax = 7;
	static constexpr int numberDownMax = 2;
	static constexpr int amountMax = numberAcrossMax * numberDownMax;
	Laser Bolt;

	
};

