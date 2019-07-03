#include "RectF.h"

RectF::RectF(float left_in, float right_in, float top_in, float bottom_in)
	:
	left(left_in),
	right(right_in),
	top(top_in),
	bottom(bottom_in)
{
}

RectF::RectF(const Vec2 & topLeft, const Vec2 & bottomRight) // this takes the individual corrdiantes of xy1 to xy 2 
	:
	RectF(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
	//     40,        100,			40,			60
{
}

RectF::RectF(const Vec2 & topLeft, float width, float height)// this takes in the topleft or first xy and just add width/height.
	:
	RectF(topLeft,topLeft +Vec2(width, height))

{
}

bool RectF::IsOverLappingWith(const RectF & other) const
{
	return right > other.left && left < other.right
		&& bottom >other.top && top < other.bottom;
}

RectF RectF::FromCenter(const Vec2 & center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(center - half, center + half);
}

RectF RectF::GetExpended(float offset) const
{
	return RectF(left , right  , top - offset , bottom + offset);;
}
