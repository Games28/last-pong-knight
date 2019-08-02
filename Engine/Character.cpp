#include "Character.h"

#include "Collider.h"





Character::Character(Vec2& loc)
{
	this->loc = loc;
	
}

/*Character::Character(Vec2& loc, Vec2& saber, Vec2& head)
	:
	color{ { 0,0,0 },{ 0,0,0 } }
{
	Loc.Artcharacter = loc;
	Loc.ArtSaber = saber;
	Loc.Arthead = head;
	
}*/



//void Character::DrawTrooper(Graphics& gfx)
//{
//	artcharacter.StormTrooper(loc.x, loc.y, gfx);
//	Bolt.Draw(gfx); 
//}

//void Character::Move(Vec2 & MoveAmount)
//{
//	ArtPosiition.Artcharacter += MoveAmount;
//	ArtPosiition.Arthead += MoveAmount;
//	ArtPosiition.ArtSaber += MoveAmount;
//	collider.Move(MoveAmount);
//	SaberCollider.Move(MoveAmount);
//	
//}

