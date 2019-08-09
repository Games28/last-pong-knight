#include "Trooper.h"
#include "Graphics.h"

Trooper::Trooper(Vec2& loc)
	:
	Character(loc)
{
	
}

void Trooper::Draw(Graphics& gfx)
{	
	//for (int i = 0; i < trooperMax; i++)
	//{
	//	troopers[i].artcharacter.StormTrooper(loc.x, loc.y, gfx);
	//}
	int i = 0;
	//inits the troopers
	for (int y = 0; y < nTrooperDown; y++)
	{

		for (int x = 0; x < nTrooperAcross; x++)
		{
			troopers[i].artcharacter.StormTrooper(loc.x + (x * trooperwidth), loc.y + (y * trooperheight), gfx);
			//troopers[i].Bolt.loc = troopers[i].loc + Vec2(trooperwidth, trooperheight) * 0.5f;
			//troopers[i].Bolt.Init(troopers[i].loc, rng);
			i++;
		}

	}
}

void Trooper::Update()
{
	
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
