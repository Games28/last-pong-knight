#pragma once
#include "Vec2.h"
#include "ArtCharacter.h"
#include "Collider.h"


class Character
{
public:
	Character() = default;
	Character(Vec2& loc);
	
public:
	
	Collider collider;
	ArtCharacter artcharacter;
	Vec2 loc;
	
	
	
};

