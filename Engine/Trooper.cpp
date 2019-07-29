#include "Trooper.h"

Trooper::Trooper(Vec2& loc)
{
	this->loc = loc;
}

void Trooper::Draw(Graphics& gfx)
{
	for (int i = 0; i < trooperMax; i++)
	{

		
		Vec2 reflection = collidemanager.GetInnerReflection(troopers[i].Bolt.collider, back.collider);

		if (reflection.GetLengthSq())
		{
			//troopers[i].Bolt.vel = reflection;
			troopers[i].Bolt.Move(reflection);
			troopers[i].Bolt.collider.Move(reflection);
			if (reflection.x)
			{
				troopers[i].Bolt.vel.x = -troopers[i].Bolt.vel.x;
			}
			if (reflection.y)
			{
				troopers[i].Bolt.vel.y = -troopers[i].Bolt.vel.y;
			}
		}
	}
}
