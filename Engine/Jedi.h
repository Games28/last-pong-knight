#pragma once
#include "Character.h"
class Jedi : public Character
{
public:
	Jedi(Vec2& loc, Vec2& saber, Vec2& head);
	void Draw(Graphics& gfx);
	void Update(Graphics& gfx, Keyboard& kbd);
	void GenderSelect();
public:
	void(Arthead::* DrawHead)(int, int, Graphics&);
	void(ArtCharacter::* DrawRobe)(int, int, Graphics&);
	void(ArtSaber::* DrawSaber)(int, int,Color*, Graphics&);
	PlayerSelect headselect;
};

