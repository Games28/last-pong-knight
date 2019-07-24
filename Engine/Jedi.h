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
	void(ArtSaber::* DrawSaber)(int, int, Color*, Graphics&);
	void(Collider::* SaberCol)(const Vec2&, const Vec2&);
	PlayerSelect headselect;
	Vec2 Sabersize{7, 50};
	Vec2 Sabersidesize{ 85, 7 };
	//tried this to allow for overriding when doing the different saber positions but do not seem to get the values?
	Vec2 SaberLocation = ArtPosiition.ArtSaber;
	
	
};

