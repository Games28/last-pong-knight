#include "Laser.h"



Laser::Laser(Vec2& loc)
{
	artloc.troper = loc;
}

Laser::Laser(Vec2& loc, std::mt19937& rng)
	:
	collider(loc, Vec2(15,40))
{
	Respawn(loc, rng);
	DrawLaser = 0;
}

void Laser::Draw(Graphics & gfx)
{
	(gfx.laser.*(DrawLaser))((int)loc.x, (int)loc.y, gfx);
	collider.DrawBox(gfx, Colors::Magenta);
}

void Laser::Init(Vec2& loc, std::mt19937& rng)	
{
	collider.loc = loc; 
	collider.size = Vec2(15, 40);
	Respawn(loc, rng);
	DrawLaser = 0;
}

void Laser::Respawn(Vec2& loc, std::mt19937& rng)
{
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

void Laser::Move(Vec2& MoveAmount)
{
	loc += MoveAmount;
	artloc.troper += MoveAmount;
}

void Laser::Update()
{
	
	loc += vel * 3.0f;
	if (vel.y < 0.0f)
	{
		DrawLaser = &ArtLaser::DrawLaserUp;
	}
	else {
		DrawLaser = &ArtLaser::DrawLaserDown;
	}
	collider.loc = loc;
}


