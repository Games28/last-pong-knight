#include "Jedi.h"

Jedi::Jedi(Vec2& loc, Vec2& saber, Vec2& head) : Character(loc)
{
	ArtPosiition.Artcharacter = loc;
	ArtPosiition.ArtSaber = saber;
	ArtPosiition.Arthead = head;
	DrawHead = 0;
	DrawSaber = 0;
	DrawRobe = 0;
	SaberCol = 0;
}

void Jedi::Draw(Graphics& gfx)
{
	
		(gfx.character.*(DrawRobe))((int)ArtPosiition.Artcharacter.x, (int)ArtPosiition.Artcharacter.y, gfx);
		(gfx.saber.*(DrawSaber))((int)ArtPosiition.ArtSaber.x, (int)ArtPosiition.ArtSaber.y, color, gfx);
		if (DrawHead != NULL)
		{
			(gfx.head.*(DrawHead))((int)ArtPosiition.Arthead.x, (int)ArtPosiition.Arthead.y, gfx);
		}

	collider.DrawBox(gfx, Colors::Blue);
	SaberCollider.DrawBox(gfx, Colors::Magenta);
}

void Jedi::Update(Graphics& gfx, Keyboard& kbd)
{
	
	if (kbd.KeyIsPressed('A'))
	{
		DrawRobe = &ArtCharacter::RobeLeft;
		DrawSaber = &ArtSaber::SaberLeft;
		
		SaberCollider.Init(ArtPosiition.ArtSaber + Vec2{ -75,45 }, Sabersidesize);
		//artcharacter.RobeLeft((int)Loc.Artcharacter.x - 5, (int)Loc.Artcharacter.y - 10, gfx);
		//artsaber.SaberLeft((int)Loc.ArtSaber.x - 70, (int)Loc.ArtSaber.y + 52, color, gfx);

	}
	else if (kbd.KeyIsPressed('D'))
	{
		DrawRobe = &ArtCharacter::RobeRight;
		DrawSaber = &ArtSaber::SaberRight;
		
		SaberCollider.Init(ArtPosiition.ArtSaber + Vec2{ 0,45 }, Sabersidesize);
	}
	else {
		DrawRobe = &ArtCharacter::RobeFront;
		DrawSaber = &ArtSaber::SaberFront;
		SaberCollider.Init(ArtPosiition.ArtSaber, Sabersize);
		
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
