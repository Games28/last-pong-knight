#include "Laser.h"
#include "Graphics.h"




Laser::Laser(Vec2& loc)
	:
	loc(loc)
{
	
}

//Laser::Laser(Vec2& loc, std::mt19937& rng)
//	:
//	collider(loc, Vec2(15,40))
//{
//	Spawn(loc, rng);
//	DrawLaser = 0;
//}

void Laser::Draw(Graphics & gfx)
{
	//Art.DrawLaserDown(loc.x, loc.y, gfx);
	(gfx.laser.*(DrawLaser))((int)loc.x, (int)loc.y, gfx);
	collider.DrawBox(gfx, Colors::Magenta);
}

void Laser::Init(Vec2& loc)	
{
	collider.loc = loc; 
	collider.size = Vec2(14, 37);
	//Spawn(loc, rng);
	DrawLaser = 0;
	
}

void Laser::Spawn(Vec2& loc, std::mt19937& rng)
{
	IsActive = true;
	
		float Pi = 3.14159;
		float LeftDown = Pi * 5.0f * 0.25f;
		float RightDown = Pi * 7.0f * 0.25f;

		this->loc = loc;

		std::uniform_real_distribution<float> Angle;
		Angle = std::uniform_real_distribution<float>(LeftDown, RightDown);
		float angle = Angle(rng);
		Vec2 newVel;
		newVel.x = cos(angle);
		newVel.y = -sin(angle);

		vel = newVel;
		loc += vel;

	
}

void Laser::DrawLaserUp(Graphics& gfx)
{
	Art.DrawLaserUp(loc.x, loc.y, gfx);
}

void Laser::DrawLaserDown(Graphics& gfx)
{
	Art.DrawLaserDown(loc.x, loc.y, gfx);
}



void Laser::Update()
{
	if (IsActive)
	{
		loc += vel * speed;
		if (vel.y < 0.0f)
		{
			DrawLaser = &ArtLaser::DrawLaserUp;
		}
		else {
			DrawLaser = &ArtLaser::DrawLaserDown;
		}
		collider.loc = loc;
	}
}

//void Laser::Dispersed()
//{
//	IsActive = false;
//}


