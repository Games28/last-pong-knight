#pragma once
#include "Vec2.h"
class Graphics;
#include "Colors.h"


class Collider
{
public:
	Collider() = default;
	Collider(const Vec2& loc, const Vec2& size);
	void Box();
	void DrawBox(Graphics& gfx, Color c);
	void Move(Vec2& Amount);
	void Init(const Vec2& loc, const Vec2& sixe);
public:
	Vec2 loc;
	Vec2 size;
	
};


