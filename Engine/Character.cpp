#include "Character.h"





Character::Character(Vec2& loc)
{
	Loc.Artcharacter - loc;
}

Character::Character(Vec2& loc, Vec2& saber, Vec2& head)
	:
	color{ { 0,0,0 },{ 0,0,0 } }
{
	Loc.Artcharacter = loc;
	Loc.ArtSaber = saber;
	Loc.Arthead = head;
	DrawHead = 0;
}

void Character::Draw(Graphics & gfx,Keyboard & kbd)
{
	
	
	if (kbd.KeyIsPressed('A'))
	{
		artcharacter.RobeLeft((int)Loc.Artcharacter.x -5, (int)Loc.Artcharacter.y -10, gfx);
		artsaber.SaberLeft((int)Loc.ArtSaber.x- 70, (int)Loc.ArtSaber.y+52, color, gfx);

	}
	else if (kbd.KeyIsPressed('D'))
	{
		artcharacter.RobeRight((int)Loc.Artcharacter.x -5, (int)Loc.Artcharacter.y -10, gfx);
		artsaber.SaberRight((int)Loc.ArtSaber.x, (int)Loc.ArtSaber.y + 52,color, gfx);
	}
	else {
		artsaber.SaberFront((int)Loc.ArtSaber.x, (int)Loc.ArtSaber.y,color, gfx);
		artcharacter.RobeFront((int)Loc.Artcharacter.x, (int)Loc.Artcharacter.y, gfx);
	}
	(gfx.head.*(DrawHead))((int)Loc.Arthead.x, (int)Loc.Arthead.y, gfx);

	collider.DrawBox(gfx, Colors::Blue);
}

void Character::DrawTrooper(Graphics& gfx)
{
	artcharacter.StormTrooper(loc.x, loc.y, gfx);
}

void Character::Move(Vec2 & MoveAmount)
{
	Loc.Artcharacter += MoveAmount;
	Loc.Arthead += MoveAmount;
	Loc.ArtSaber += MoveAmount;
	collider.Move(MoveAmount);
}

void Character::SaberBackColorChange()
{
	float Red = 1.0f / (255.0f / (1 + color[1].GetR()));
	float Blue = 1.0f / (255.0f / (1 + color[1].GetB()));
	float Green = 1.0f / (255.0f / (1 + color[1].GetG()));
	char increase = 3;
	char MAX = 127;
	if (ColorIncreasing)
	{

		if (color[0].GetR() >= MAX || color[0].GetB() >= MAX || color[0].GetG() >= MAX)
		{
			ColorIncreasing = false;
		}
		else
		{

			Color blend = color[0];
			color[0] = Color(blend.GetR() + Red * increase, blend.GetG() + Green * increase, blend.GetB() + Blue * increase);
		}

	}
	else
	{
		if (color[0].GetR() <= 0 && color[0].GetB() <= 0 && color[0].GetG() <= 0)
		{
			ColorIncreasing = true;
		}
		else
		{
			Color blend = color[0];
			color[0] = Color(blend.GetR() - Red * increase, blend.GetG() - Green * increase, blend.GetB() - Blue * increase);
		}

	}
}