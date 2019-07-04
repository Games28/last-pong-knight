#pragma once
#include "Graphics.h"
class ArtLaser
{
public:
	ArtLaser() = default;
	void DrawLaserUp(int x, int y, Graphics& gfx);
	void DrawLaserDown(int x, int y, Graphics& gfx);
	
};

