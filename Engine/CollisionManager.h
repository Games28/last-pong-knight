#pragma once
#include "Collider.h"

class CollisionManager
{
public:
	CollisionManager() = default;
	bool Contains(Collider& inner, Collider& outer);
	Vec2 GetInnerReflection(Collider& collider, Collider& other);
	//Vec2 Rebound(Collider& object1, Collider& object2);
	bool ReboundTestbool(Collider& object1, Collider& object2);
	Vec2 ReboundY(Collider& object1, Collider& object2);
};

