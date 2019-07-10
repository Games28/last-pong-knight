#pragma once
class Graphics;
class ArtLaser
{
public:
	ArtLaser() = default;
	void DrawLaserUp(int x, int y, Graphics& gfx);
	void DrawLaserDown(int x, int y, Graphics& gfx);
	
};

