#pragma once
#include "Graphics.h"
#include "Vec2.h"

class EndScrene
{
public:
	EndScrene(Vec2& loc);
	void darkAnakin(Graphics& gfx);
	void Failed(Graphics& gfx);
	void Yoda(Graphics& gfx);
	void Won(Graphics& gfx);
public:
	Vec2 loc;
};

