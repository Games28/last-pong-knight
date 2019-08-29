#pragma once
#include "Vec2.h"
#include "titleart.h"
#include <random>
class Graphics;
class Title
{
public:
	Title() = default;
	Title(Vec2& loc);
	void Init(std::mt19937& rng);
	void DrawRegularStar(Graphics& gfx);
	void DrawDimStar(Graphics& gfx);
	void DrawBrightStar(Graphics& gfx);
	void DrawTitle(Graphics& gfx);
	void DrawPrview(Graphics& gfx);
public:
	Vec2 loc;
	titleart art;
};

