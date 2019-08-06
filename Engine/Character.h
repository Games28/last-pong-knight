#pragma once
#include "Vec2.h"
#include "ArtCharacter.h"
#include "Collider.h"
#include "CollisionManager.h"


class Character
{
public:
	Character() = default;
	Character(Vec2& loc);
	
public:
	

	ArtCharacter artcharacter;
	Vec2 loc;
	

	
};

