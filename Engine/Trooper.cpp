#include "Trooper.h"
#include "Graphics.h"

Trooper::Trooper(Vec2& loc)
	:
	Character(loc)
{
	
	
}

void Trooper::Draw(Graphics& gfx)
{	
	if (isVaporized == false)
	{
		trooperCounter++;
		
		artcharacter.TrooperRightFootFront((int)loc.x, (int)loc.y, gfx);
		if (trooperCounter >= trooperCounterReset)
		{
			trooperCounter = 0;
		}
		if (trooperCounter > 20)
		{
			artcharacter.TrooperLeftFootFront((int)loc.x, (int)loc.y, gfx);
		}
		else if (trooperCounter < 20)
		{
			artcharacter.TrooperRightFootFront((int)loc.x, (int)loc.y, gfx);
		}

		collider.DrawBox(gfx, Colors::Red);

	}
	
	
	
	
}

void Trooper::Move(Vec2& moveamount)
{
	Bolt.loc += moveamount;
}






