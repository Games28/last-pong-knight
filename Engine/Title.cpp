#include "Title.h"
#include "Graphics.h"

Title::Title(Vec2& loc)
	:
	loc(loc)
{
}

void Title::Init(std::mt19937& rng)
{
	std::uniform_real_distribution<float> xdist(5, Graphics::ScreenWidth - 5);
	std::uniform_real_distribution<float> ydist(5, Graphics::ScreenHeight - 5);
	loc.x = xdist(rng);
	loc.y = ydist(rng);
}


void Title::DrawRegularStar(Graphics& gfx)
{
	art.Regularstar(loc.x, loc.y, gfx);
}

void Title::DrawDimStar(Graphics& gfx)
{
	art.DimStar(loc.x, loc.y, gfx);
}

void Title::DrawBrightStar(Graphics& gfx)
{
	art.BrightStar(loc.x, loc.y, gfx);
}

void Title::DrawTitle(Graphics& gfx)
{
	art.DrawTitle(loc.x, loc.y, gfx);
}

void Title::DrawPrview(Graphics& gfx)
{
	art.Drawtitlepreview(loc.x, loc.y, gfx);
}
