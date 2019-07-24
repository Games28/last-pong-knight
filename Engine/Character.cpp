#include "Character.h"

#include "Collider.h"





Character::Character(Vec2& loc)
{
	ArtPosiition.Artcharacter - loc;
}

/*Character::Character(Vec2& loc, Vec2& saber, Vec2& head)
	:
	color{ { 0,0,0 },{ 0,0,0 } }
{
	Loc.Artcharacter = loc;
	Loc.ArtSaber = saber;
	Loc.Arthead = head;
	
}*/



void Character::DrawTrooper(Graphics& gfx)
{
	artcharacter.StormTrooper(loc.x, loc.y, gfx);
	Bolt.Draw(gfx); 
}

void Character::Move(Vec2 & MoveAmount)
{
	ArtPosiition.Artcharacter += MoveAmount;
	ArtPosiition.Arthead += MoveAmount;
	ArtPosiition.ArtSaber += MoveAmount;
	collider.Move(MoveAmount);
	SaberCollider.Move(MoveAmount);
	
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