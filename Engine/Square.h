#pragma once
#include "Square.h"
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"


class Square
{
public:
	Square() = default;
	Square(const RectF& Rect,Color Col);
	void Draw(Graphics& gfx);
public:
	static constexpr float separate = 5.0f;
	RectF rect;
	Color col;
	
};

