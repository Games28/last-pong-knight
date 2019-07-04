#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "ArtCharacter.h"
#include "Arthead.h"
#include "ArtSaber.h"
#include "Keyboard.h"

class Character
{
public:
	Character() = default;
	Character(Vec2& loc,Vec2& saber, Vec2& head );
	void Draw(Graphics& gfx,Keyboard & kbd);
	void Move(Vec2& MoveAmount);
public:
	struct ArtLoc
	{
		Vec2 Artcharacter;
		Vec2 Arthead;
		Vec2  ArtSaber;

	};
	ArtCharacter character;
	Arthead arthead;
	ArtSaber artsaber;
	ArtLoc Loc;
	Vec2 loc;
	

};

