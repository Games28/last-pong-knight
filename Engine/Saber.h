#pragma once
#include "ArtSaber.h"
#include "Vec2.h"
#include "Colors.h"
#include "Collider.h"

class Graphics;


class Saber
{
public:
	//Saber() = default;
	Saber(Vec2& loc);
	void DrawLeft(Graphics& gfx);
	void DrawRight(Graphics& gfx);
	void DrawFront(Graphics& gfx);
	void DrawUp(Graphics& gfx);
	void Move(Vec2& moveamount);
	void saberColorChange();

public:
	Vec2 saberLeft{ 45,-50 };
	Vec2 saberRight{ 35,-50 };
	Vec2 saberFront{ 42,-55 };
	Vec2 SaberUp{ 35,-40 };
	Vec2 SaberhorizontalSize{ 87,7 };
	Vec2 SaberVerticalSize{ 7,50 };
	Vec2 SaberVecticalSize2{ 20, 40 };
	Vec2 loc;
	ArtSaber art;
	Color color[2];
	Collider collider;
	bool ColorIncreasing = false;
};

