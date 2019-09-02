#include "Jedi.h"
#include "Graphics.h"

         
Jedi::Jedi(Vec2& loc)
	:
	Character(loc),
	saber(loc),
	collider(loc + Vec2(-35, 0), charactersize)
	
{
	
	DrawHead = 0;
	DrawSaber = 0;
	DrawRobe = 0;
	
	
	
}

void Jedi::Draw(Graphics& gfx)
{

	(gfx.character.*(DrawRobe))((int)loc.x, (int)loc.y, gfx);

	if (DrawHead != NULL)
	{
		(gfx.head.*(DrawHead))((int)loc.x + (int)headloc.x, (int)loc.y + (int)headloc.y, gfx);
	}
	(saber.*(DrawSaber))(gfx);
	collider.DrawBox(gfx, Colors::Blue);
	saber.collider.DrawBox(gfx, Colors::Magenta);
	
}

void Jedi::Update(Graphics& gfx, Keyboard& kbd)
{
	
	if (kbd.KeyIsPressed('A'))
	{
		if (DrawRobe != &ArtCharacter::RobeLeft)
		{
			DrawRobe = &ArtCharacter::RobeLeft;
			DrawSaber = &Saber::DrawLeft;
			saber.collider.Init(saber.loc + Vec2(-20,-5), saber.SaberhorizontalSize);
		}

	}
	else if (kbd.KeyIsPressed('D') )
	{
		if (DrawRobe != &ArtCharacter::RobeRight)
		{
			DrawRobe = &ArtCharacter::RobeRight;
			DrawSaber = &Saber::DrawRight;
			saber.collider.Init(saber.loc + Vec2(30,-5), saber.SaberhorizontalSize);
		}
	}
	else if(DrawRobe != &ArtCharacter::RobeFront){
		DrawRobe = &ArtCharacter::RobeFront;
		DrawSaber = &Saber::DrawFront;
		saber.collider.Init(saber.loc + Vec2(40, -50), saber.SaberVerticalSize);
	}

	if (kbd.KeyIsPressed('F'))
	{
		headselect = PlayerSelect::FEMALE;
	}
	if (kbd.KeyIsPressed('M'))
	{
		headselect = PlayerSelect::MALE;
	}
	
}

void Jedi::GenderSelect()
{
	if (headselect == PlayerSelect::FEMALE)
	{
		DrawHead = &Arthead::FemaleHead;
	}
	if (headselect == PlayerSelect::MALE)
	{
		DrawHead = &Arthead::MaleHead;
	}
}

void Jedi::FemaleJedi(Graphics& gfx)
{
	headart.FemaleHead((int)loc.x + (int)headloc.x, (int)loc.y + (int)headloc.y, gfx);
}

void Jedi::MaleJedi(Graphics& gfx)
{
	headart.MaleHead((int)loc.x + (int)headloc.x, (int)loc.y + (int)headloc.y, gfx);
}

void Jedi::Move(Vec2& moveamount)
{
	loc += moveamount;
	Head += moveamount;
	saber.loc += moveamount;
	collider.Move(moveamount);
	saber.collider.Move(moveamount);
}

void Jedi::collision(Collider& collide)
{
	Vec2 reflection = collidemanage.GetInnerReflection(collider, collide);
	if (reflection.GetLengthSq())
	{
		Move(reflection);
	}
}
