#include "Trooper.h"
#include "Graphics.h"

Trooper::Trooper(Vec2& loc)
	:
	Character(loc)
{
	
	
}

void Trooper::Draw(Graphics& gfx)
{	
	trooperCounter++;
	//artcharacter.StormTrooper(loc.x, loc.y, gfx);
	artcharacter.TrooperRightFootFront(loc.x, loc.y, gfx);
	if (trooperCounter >= trooperCounterReset)
	{
		trooperCounter = 0;
	}
	if (trooperCounter > 20)
	{
		artcharacter.TrooperLeftFootFront(loc.x, loc.y, gfx);
	}
	else if (trooperCounter < 20)
	{
		artcharacter.TrooperRightFootFront(loc.x, loc.y, gfx);
	}
		
		Bolt.Draw(gfx);
		collider.DrawBox(gfx, Colors::Red);
	
	

	
	
	
}

void Trooper::Move(Vec2& moveamount)
{
	Bolt.loc += moveamount;
}



void Trooper::Rebound()
{
	
			//if (bolts[arraytracker].vel.y < 0.0f)
			//{
			//	DrawBolt = &Laser::DrawLaserUp;
			//}
			//else {
			//	DrawBolt = &Laser::DrawLaserDown;
			//}
			//bolts[arraytracker].collider.loc = loc;
			
}

void Trooper::Collision(Collider& collide)
{
	//for (int i = 0; i < trooperMax; i++)
	//{
	//
	//
	//	Vec2 reflection = collidemanager.GetInnerReflection(troopers[i].Bolt.collider, back.collider);
	//
	//	if (reflection.GetLengthSq())
	//	{
	//		//troopers[i].Bolt.vel = reflection;
	//		troopers[i].Bolt.Move(reflection);
	//		troopers[i].Bolt.collider.Move(reflection);
	//		if (reflection.x)
	//		{
	//			troopers[i].Bolt.vel.x = -troopers[i].Bolt.vel.x;
	//		}
	//		if (reflection.y)
	//		{
	//			troopers[i].Bolt.vel.y = -troopers[i].Bolt.vel.y;
	//		}
	//	}
	//}
}
