#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "ArtCharacter.h"

class Character
{
public:
	Character() = default;
	Character(Vec2& loc );
public:
	struct ArtLoc
	{
		ArtCharacter ArtCh;

	};
	ArtLoc Loc;
	ArtCharacter charater;
	Vec2 loc;
	

};

