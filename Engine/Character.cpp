#include "Character.h"




Character::Character(Vec2& loc, Vec2& saber, Vec2& head)
{
	Loc.Artcharacter = loc;
	Loc.ArtSaber = saber;
	Loc.Arthead = head;
}

void Character::Draw(Graphics & gfx,Keyboard & kbd)
{
	
	
	if (kbd.KeyIsPressed('A'))
	{
		character.RobeLeft((int)Loc.Artcharacter.x, (int)Loc.Artcharacter.y, gfx);
		artsaber.SaberLeft((int)Loc.ArtSaber.x- 70, (int)Loc.ArtSaber.y+52, gfx);

	}
	else if (kbd.KeyIsPressed('D'))
	{
		character.RobeRight((int)Loc.Artcharacter.x, (int)Loc.Artcharacter.y, gfx);
		artsaber.SaberRight((int)Loc.ArtSaber.x, (int)Loc.ArtSaber.y + 52, gfx);
	}
	else {
		artsaber.SaberFront((int)Loc.ArtSaber.x, (int)Loc.ArtSaber.y, gfx);
		character.RobeFront((int)Loc.Artcharacter.x, (int)Loc.Artcharacter.y, gfx);
	}
}

void Character::Move(Vec2 & MoveAmount)
{
	Loc.Artcharacter += MoveAmount;
	Loc.Arthead += MoveAmount;
	Loc.ArtSaber += MoveAmount;
}
