#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Square.h"
#include "Character.h"
#include "Collider.h"

class BackGround
{
 public:
	BackGround() = default;
	void Draw(Graphics& gfx);
public:
	static constexpr float stepWidth = 84.0f;
	static constexpr float stepHeight = 35.0f;
	static constexpr int nstepsAcross = 7;
	static constexpr int nstepsdown = 14;
	static constexpr int stepMax = nstepsAcross * nstepsdown;
	Square steps[stepMax];
	Vec2 loc;
	ArtCharacter jediStatue[4];
	Collider collider;
};