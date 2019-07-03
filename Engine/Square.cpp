#include "Square.h"



Square::Square(const RectF& Rect,Color Col)
{
	rect = Rect;
	col = Col;
}

void Square::Draw(Graphics & gfx)
{
	gfx.DrawRect(rect.GetExpended(- separate), col);
}


