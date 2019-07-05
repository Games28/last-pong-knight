#include "CollisionManager.h"

bool CollisionManager::Contains(Collider& inner, Collider& outer)
{

	bool IsInside = false;
	if (inner.loc.x					> outer.loc.x && 
		inner.loc.x + inner.size.x	< outer.loc.x + outer.size.x && 
		inner.loc.y					> outer.loc.y && 
		inner.loc.y + inner.size.y	< outer.loc.y + outer.size.y)
	{
		IsInside = true;
	}
	return IsInside;
}
Vec2 CollisionManager::GetInnerReflection(Collider& inner, Collider& outer)
{

	Vec2 reflection = Vec2(0.0f, 0.0f);
	//LEFT
	if (inner.loc.x < outer.loc.x)		
	{
		reflection += Vec2(outer.loc.x - inner.loc.x, 0.0f);
	}
	//RIGHT
	if (inner.loc.x + inner.size.x > outer.loc.x + outer.size.x)
	{
		reflection += Vec2((outer.loc.x + outer.size.x) - (inner.loc.x + inner.size.x), 0.0f);
	}
	//TOP
	if (inner.loc.y < outer.loc.y)
	{
		reflection += Vec2(0.0f, outer.loc.y - inner.loc.y);
	}
	//BOT
	if(inner.loc.y + inner.size.y > outer.loc.y + outer.size.y)
	{
		reflection += Vec2(0.0f, (outer.loc.y + outer.size.y) - (inner.loc.y + inner.size.y));
	}
	return reflection;
}

bool CollisionManager::ReboundX(Collider& object1, Collider& object2)
{
	bool isColliding = false;
	if (object1.loc.x + object1.size.x > object2.loc.x)
	{
		isColliding = true;
	}
	else if (object1.loc.x < object2.loc.x + object2.size.x)
	{
		isColliding = true;
	}
	return isColliding;
}

bool CollisionManager::ReboundY(Collider& object1, Collider& object2)
{
	bool isCollding = false;
	if (object1.loc.y + object1.size.y > object2.loc.y)
	{
		isCollding = true;
	}
	else if (object1.loc.y < object2.loc.y + object2.size.y)
	{
		isCollding = true;
	}
	return isCollding;
}

/*void CollisionManager::Rebound(Collider& object1, Collider& object2)
{
	//object 1 bolt //object 2 rebound target
	
	
	
	
}
*/

