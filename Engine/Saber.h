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
	void Move(Vec2& moveamount);
	void saberColorChange();

public:
	Vec2 saberLeft{ -75,45 };
	Vec2 saberRight{ 0,45 };
	Vec2 saberFront;
	Vec2 loc;
	ArtSaber art;
	Color color[2];
	Collider collider;
	bool ColorIncreasing = false;
};

