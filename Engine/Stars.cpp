#include "Stars.h"

void Stars::Init(std::mt19937& rng)
{
	std::uniform_real_distribution<float> xdist(5, Graphics::ScreenWidth - 5);
	std::uniform_real_distribution<float> ydist(5, Graphics::ScreenHeight - 5);
	loc.x = xdist(rng);
	loc.y = ydist(rng);
	
}

void Stars::DimStar( Graphics& gfx)
{
	int x = (int)loc.x;
	int y = (int)loc.y;
	gfx.PutPixel(x + 2, y + 2, 255, 255, 255);

}

void Stars::BrightStar(Graphics& gfx)
{
	int x = (int)loc.x;
	int y = (int)loc.y;
	gfx.PutPixel(x + 2, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 2, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 3, y + 2, 255, 255, 255);
}

void Stars::RegularStar(Graphics& gfx)
{
	int x = (int)loc.x;
	int y = (int)loc.y;
	gfx.PutPixel(x, y, 255, 255, 255);
	gfx.PutPixel(x + 1, y, 255, 255, 255);
	gfx.PutPixel(x, y + 1, 255, 255, 255);
	gfx.PutPixel(x + 1, y + 1, 255, 255, 255);
}
