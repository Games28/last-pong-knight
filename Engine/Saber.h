#pragma once
#include "ArtSaber.h"
#include "Vec2.h"
#include "Colors.h"
#include "Collider.h"
class Jedi;
class Graphics;


class Saber : public Jedi
{
public: 
	Saber() = default;
	Saber(Vec2& loc);
	void DrawLeft(Graphics& gfx);
	void DrawRight(Graphics& gfx);
	void DrawFront(Graphics& gfx);
	void Move(Vec2& moveamount);
	void saberColorChange();

public:
	
	ArtSaber art;
	Color color[2];
	Collider collider;
	bool ColorIncreasing = false;
};

