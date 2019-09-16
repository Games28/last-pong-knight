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
	art.Regularstar((int)loc.x, (int)loc.y, gfx);
}

void Title::DrawDimStar(Graphics& gfx)
{
	art.DimStar((int)loc.x, (int)loc.y, gfx);
}

void Title::DrawBrightStar(Graphics& gfx)
{
	art.BrightStar((int)loc.x, (int)loc.y, gfx);
}

void Title::DrawTitle(Graphics& gfx)
{
	art.DrawTitle((int)loc.x, (int)loc.y, gfx);
}

void Title::DrawPrview(Graphics& gfx)
{
	art.Drawtitlepreview((int)loc.x - 100, (int)loc.y + 200, gfx);
}

void Title::DrawYoda(Graphics& gfx)
{
	art.YodaArt((int)loc.x - 180, (int)loc.y, gfx);
}

void Title::DrawYodaSpeaks(Graphics& gfx)
{
	art.YodaSpeaks((int)loc.x, (int)loc.y, gfx);
}

void Title::DrawJediMenu(Graphics& gfx)
{
	art.Jedichoice((int)loc.x - 280, (int)loc.y + 200, gfx);
}

void Title::DrawSaberMenu(Graphics& gfx)
{
	art.Saberchoice((int)loc.x + 50, (int)loc.y + 200 , gfx);
}

void Title::DrawSaberSelect0r1(Graphics& gfx)
{
	art.SelectingSaber1((int)loc.x, (int)loc.y, gfx);
}


