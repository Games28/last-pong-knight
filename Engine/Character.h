#pragma once
#include "Vec2.h"
#include "ArtCharacter.h"
#include "Arthead.h"
#include "ArtSaber.h"
#include "Keyboard.h"
class collider;
#include "Colors.h"
#include "Laser.h"
#include "PlayerSelect.h"
#include "Graphics.h"

class Character
{
public:
	Character() = default;
	Character(Vec2& loc);
	//Character(Vec2& loc, Vec2& saber, Vec2& head);

	
	void DrawTrooper(Graphics& gfx);
	void Move(Vec2& MoveAmount);
	void SaberBackColorChange();
public:
	Vec2 charactersize{ 180, 100 };
	
	struct ArtLoc
	{
		Vec2 Artcharacter;
		Vec2 Arthead;
		Vec2  ArtSaber;
		Vec2 collider;
	};
	
	Collider collider;
	ArtCharacter artcharacter;
	Arthead arthead;
	ArtSaber artsaber;
	ArtLoc Loc;
	Vec2 loc;
	Color color[2];
	Laser Bolt;

	bool ColorIncreasing = false;
};

