#pragma once
#include "Character.h"
#include "Collider.h"
#include "CollisionManager.h"
class Trooper : public Character
{
public:
	Trooper() = default;
	Trooper(Vec2& loc);
	void Draw(Graphics& gfx);
public:
	CollisionManager collidemanager;
	Collider collider;
	static const int lasermax = 3;
	static constexpr float laserseparation = 70.0f;
	
	static constexpr float trooperwidth = 82.0f;
	static constexpr float trooperheight = 82.0f;
	static constexpr int nTrooperAcross = 7;
	static constexpr int nTrooperDown = 2;
	static constexpr int trooperMax = nTrooperAcross * nTrooperDown;
	int troopers[trooperMax];
	//Laser bolt;
	
	
};

