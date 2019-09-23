#pragma once
#include "Graphics.h"
#include <random>
#include "Vec2.h"

class Stars
{
public:
	Stars() = default;
	void Init(std::mt19937& rng);
	void DimStar(Graphics& gfx);
	void BrightStar( Graphics& gfx);
	void RegularStar(Graphics& gfx);
	void Draw(Graphics& gfx);
public:
	Vec2 loc;
	
};

