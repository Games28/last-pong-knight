#pragma once
class Graphics;
#include <random>

class titleart
{
public:
	void StarSet(std::mt19937& rng);
	void DimStar(int x, int y,Graphics& gfx);
	void BrightStar(int x, int y, Graphics& gfx);
	void Regularstar(int x, int y, Graphics& gfx);
	void DrawTitle(int x, int y, Graphics& gfx);
	void Drawtitlepreview(int x, int y, Graphics& gfx);
private:
	
};