#include "Character.h"




Character::Character(Vec2& loc, Vec2& saber, Vec2& head)
{
	Loc.Artcharacter = loc;
	Loc.ArtSaber = saber;
	Loc.Arthead = head;
}

void Character::Draw(Graphics & gfx)
{

}

void Character::Move(Vec2 & MoveAmount)
{
	Loc.Artcharacter += MoveAmount;
	Loc.Arthead += MoveAmount;
	Loc.ArtSaber += MoveAmount;
}
