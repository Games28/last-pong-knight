#include "Collider.h"

Collider::Collider(const Vec2& loc, const Vec2& size)
{
	this->loc = loc;
	this->size = size;
}
void Collider::DrawBox(Graphics& gfx, Color c)
{
	
	gfx.DrawBox(loc, size, c);

}

void Collider::Move(Vec2& Amount)
{
	loc += Amount;
}

void Collider::Init(const Vec2& loc, const Vec2& size)
{
	this->loc = loc;
	this->size = size;
}

void Collider::Box()
{
	Vec2 Rightbottom = loc + size;

	if (loc.x - 10 < 500)
	{
		loc.x = 500;
	}
	else if (Rightbottom.x >= int(Graphics::ScreenWidth - 100))
	{
		loc.x = int(Graphics::ScreenWidth - 100) - size.x;
	}
	if (loc.y < 100)
	{
		loc.y = 100;
	}
	else if (Rightbottom.y >= int(Graphics::ScreenHeight - 50))
	{
		loc.y = int(Graphics::ScreenWidth - 50) - size.y;
	}
}
