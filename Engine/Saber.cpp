#include "Saber.h"
#include "Graphics.h"
#include "Jedi.h"

Saber::Saber(Vec2& loc)
{
	this->loc = loc;
}

void Saber::DrawLeft(Graphics& gfx)
{
	art.SaberLeft(loc.x, loc.y, color, gfx);
}

void Saber::DrawRight(Graphics& gfx)
{
	art.SaberRight(loc.x, loc.y, color, gfx);
}

void Saber::DrawFront(Graphics& gfx)
{
	art.SaberFront(loc.x, loc.y, color, gfx);
}

void Saber::Move(Vec2& moveamount)
{
	loc += moveamount;
}

void Saber::saberColorChange()
{
	float Red = 1.0f / (255.0f / (1 + color[1].GetR()));
	float Blue = 1.0f / (255.0f / (1 + color[1].GetB()));
	float Green = 1.0f / (255.0f / (1 + color[1].GetG()));
	char increase = 3;
	char MAX = 127;
	if (ColorIncreasing)
	{

		if (color[0].GetR() >= MAX || color[0].GetB() >= MAX || color[0].GetG() >= MAX)
		{
			ColorIncreasing = false;
		}
		else
		{

			Color blend = color[0];
			color[0] = Color(blend.GetR() + Red * increase, blend.GetG() + Green * increase, blend.GetB() + Blue * increase);
		}

	}
	else
	{
		if (color[0].GetR() <= 0 && color[0].GetB() <= 0 && color[0].GetG() <= 0)
		{
			ColorIncreasing = true;
		}
		else
		{
			Color blend = color[0];
			color[0] = Color(blend.GetR() - Red * increase, blend.GetG() - Green * increase, blend.GetB() - Blue * increase);
		}

	}
}
