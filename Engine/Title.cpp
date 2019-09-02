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
	art.Drawtitlepreview(loc.x - 100, loc.y + 200, gfx);
}

void Title::DrawYoda(Graphics& gfx)
{
	art.YodaArt(loc.x - 180, loc.y, gfx);
}

void Title::DrawYodaSpeaks(Graphics& gfx)
{
	art.YodaSpeaks(loc.x, loc.y, gfx);
}

void Title::DrawJediMenu(Graphics& gfx)
{
	art.Jedichoice(loc.x - 280, loc.y + 200, gfx);
}

void Title::DrawSaberMenu(Graphics& gfx)
{
	art.Saberchoice(loc.x + 50, loc.y + 200 , gfx);
}

void Title::DrawSaberSelect0r1(Graphics& gfx)
{
	art.SelectingSaber1(loc.x, loc.y, gfx);
}


