#include "Jedi.h"
#include "Saber.h"
         // body       saber        head
Jedi::Jedi(Vec2& loc, Vec2& saber, Vec2& head)
	:
	saber(saber)
{
	//ArtPosiition.Artcharacter = loc;
	//ArtPosiition.ArtSaber = saber;
	//ArtPosiition.Arthead = head;
	this->loc = loc;
	DrawHead = 0;
	DrawSaber = 0;
	DrawRobe = 0;
	SaberCol = 0;
	Head = head;
	
}

void Jedi::Draw(Graphics& gfx)
{
	
		(gfx.character.*(DrawRobe))((int)loc.x, (int)loc.y, gfx);
		(gfx.saber.*(DrawSaber))((int)saber.x, (int)saber.y, color, gfx);
		if (DrawHead != NULL)
		{
			(gfx.head.*(DrawHead))((int)Head.x, (int)Head.y, gfx);
		}

	collider.DrawBox(gfx, Colors::Blue);
	SaberCollider.DrawBox(gfx, Colors::Magenta);
}

void Jedi::Update(Graphics& gfx, Keyboard& kbd)
{
	
	if (kbd.KeyIsPressed('A'))
	{
		if (DrawRobe != &ArtCharacter::RobeLeft)
		{
			DrawRobe = &ArtCharacter::RobeLeft;
			DrawSaber = &ArtSaber::SaberLeft;
			//collider init pointer for left pointing saber.

			SaberCollider.Init(saber + Vec2{ -75,45 }, Sabersidesize);
		}
		

	}
	else if (kbd.KeyIsPressed('D') )
	{
		if (DrawRobe != &ArtCharacter::RobeRight)
		{
			DrawRobe = &ArtCharacter::RobeRight;
			DrawSaber = &ArtSaber::SaberRight;
			//collider init pointer for right pointing saber
			SaberCollider.Init(saber + Vec2{ 0,45 }, Sabersidesize);
		}
	}
	else if (DrawRobe != &ArtCharacter::RobeFront){
		DrawRobe = &ArtCharacter::RobeFront;
		DrawSaber = &ArtSaber::SaberFront;
		SaberCollider.Init(saber, Sabersize);
		//pointer for defualt saber position.
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
	saber += moveamount;
}
