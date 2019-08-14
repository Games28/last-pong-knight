#pragma once
#include "Character.h"
#include "Saber.h"
#include"Keyboard.h"
#include "Arthead.h"
#include "PlayerSelect.h"
#include "Colors.h"
class Graphics;

class Jedi : public Character
{
public:
	Jedi() = default;
	Jedi(Vec2& loc);
	void Draw(Graphics& gfx);
	void Update(Graphics& gfx, Keyboard& kbd);
	void GenderSelect();
	void Move(Vec2& moveamount);
	void collision(Collider& collide);
public:
	Vec2 charactersize{ 160, 100 };
	void(Arthead::* DrawHead)(int, int, Graphics&);
	void(ArtCharacter::* DrawRobe)(int, int, Graphics&);
	void(Saber::* DrawSaber)(Graphics&);
	void(Collider::* SaberCol)(const Vec2&, const Vec2&);
	Saber saber;
	PlayerSelect headselect;
	Vec2 Sabersize{7, 50};
	Vec2 Sabersidesize{ 85, 7 };
	Vec2 Head;
	Vec2 headloc{ 25,0};
	Collider collider;
	CollisionManager collidemanage;
};

