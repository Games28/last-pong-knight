#include "Jedi.h"
#include "Graphics.h"

         
Jedi::Jedi(Vec2& loc)
	:
	Character(loc),
	saber(loc),
	collider(loc, charactersize)
{
	
	DrawHead = 0;
	DrawSaber = 0;
	DrawRobe = 0;
	SaberCol = 0;
	
	
}

void Jedi::Draw(Graphics& gfx)
{

	(gfx.character.*(DrawRobe))((int)loc.x, (int)loc.y, gfx);

	if (DrawHead != NULL)
	{
		(gfx.head.*(DrawHead))((int)loc.x + (int)headloc.x, (int)loc.y + (int)headloc.y, gfx);
	}
	(saber.*(DrawSaber))(gfx);
	//collider.DrawBox(gfx, Colors::Blue);
	//SaberCollider.DrawBox(gfx, Colors::Magenta);
}

void Jedi::Update(Graphics& gfx, Keyboard& kbd)
{
	
	if (kbd.KeyIsPressed('A'))
	{
		if (DrawRobe != &ArtCharacter::RobeLeft)
		{
			DrawRobe = &ArtCharacter::RobeLeft;
			DrawSaber = &Saber::DrawLeft;
		}

	}
	else if (kbd.KeyIsPressed('D') )
	{
		if (DrawRobe != &ArtCharacter::RobeRight)
		{
			DrawRobe = &ArtCharacter::RobeRight;
			DrawSaber = &Saber::DrawRight;
		}
	}
	else if (DrawRobe != &ArtCharacter::RobeFront){
		DrawRobe = &ArtCharacter::RobeFront;
		DrawSaber = &Saber::DrawFront;
		
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

void Jedi::Move(Vec2& moveamount)
{
	loc += moveamount;
	Head += moveamount;
	saber.loc += moveamount;
	//collider.Move(moveamount);
}

void Jedi::collision(Collider& collide)
{

}
