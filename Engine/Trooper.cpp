#include "Trooper.h"
#include "Graphics.h"

Trooper::Trooper(Vec2& loc)
	:
	Character(loc)
{
	
	
	for (int y = 0; y < numberDownMax; y++)
	{

		for (int x = 0; x < numberAcrossMax; x++)
		{
			bolts[arraytracker].loc = troopers[arraytracker].loc + Vec2(trooperwidth, trooperheight) * 0.5f;

			arraytracker++;
		}

	}
	DrawBolt = 0;
}

void Trooper::Draw(Graphics& gfx)
{	
	//for (int i = 0; i < trooperMax; i++)
	//{
	//	troopers[i].artcharacter.StormTrooper(loc.x, loc.y, gfx);
	//}
	

	for (int y = 0; y < numberDownMax; y++)
	{

		for (int x = 0; x < numberAcrossMax; x++)
		{
			troopers[arraytracker].artcharacter.StormTrooper(loc.x + (x * trooperwidth), loc.y + (y * trooperheight), gfx);
			(bolts[arraytracker].*(DrawBolt))(gfx);
			arraytracker++;
		}

	}
	(laserBolt.*(DrawBolt))(gfx);
	
}

void Trooper::Update()
{
	
}

void Trooper::Rebound()
{
	
			if (bolts[arraytracker].vel.y < 0.0f)
			{
				DrawBolt = &Laser::DrawLaserUp;
			}
			else {
				DrawBolt = &Laser::DrawLaserDown;
			}
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
