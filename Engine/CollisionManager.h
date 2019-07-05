#pragma once
#include "Collider.h"

class CollisionManager
{
public:
	CollisionManager() = default;
	bool Contains(Collider& inner, Collider& outer);
	Vec2 GetInnerReflection(Collider& collider, Collider& other);
	//void Rebound(Collider& object1, Collider& object2);
	bool ReboundX(Collider& object1, Collider& object2);
	bool ReboundY(Collider& object1, Collider& object2);
};

