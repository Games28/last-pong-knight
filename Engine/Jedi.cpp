#include "Jedi.h"

Jedi::Jedi(Vec2& loc, Vec2& saber, Vec2& head) : Character(loc)
{
	Loc.Artcharacter = loc;
	Loc.ArtSaber = saber;
	Loc.Arthead = head;
	DrawHead = 0;
	DrawSaber = 0;
	DrawRobe = 0;

}

void Jedi::Draw(Graphics& gfx)
{
	
	(gfx.head.*(DrawHead))((int)Loc.Arthead.x, (int)Loc.Arthead.y, gfx);
	(gfx.character.*(DrawRobe))((int)Loc.Artcharacter.x, (int)Loc.Artcharacter.y, gfx);
	(gfx.saber.*(DrawSaber))((int)Loc.ArtSaber.x, (int)Loc.ArtSaber.y,color, gfx);

	collider.DrawBox(gfx, Colors::Blue);
}

void Jedi::Update(Graphics& gfx, Keyboard& kbd)
{
	
	if (kbd.KeyIsPressed('A'))
	{
		DrawRobe = &ArtCharacter::RobeLeft;
		DrawSaber = &ArtSaber::SaberLeft;
		//artcharacter.RobeLeft((int)Loc.Artcharacter.x - 5, (int)Loc.Artcharacter.y - 10, gfx);
		//artsaber.SaberLeft((int)Loc.ArtSaber.x - 70, (int)Loc.ArtSaber.y + 52, color, gfx);

	}
	else if (kbd.KeyIsPressed('D'))
	{
		DrawRobe = &ArtCharacter::RobeRight;
		DrawSaber = &ArtSaber::SaberRight;
		//artcharacter.RobeRight((int)Loc.Artcharacter.x - 5, (int)Loc.Artcharacter.y - 10, gfx);
		//artsaber.SaberRight((int)Loc.ArtSaber.x, (int)Loc.ArtSaber.y + 52, color, gfx);
	
	}
	else {
		DrawRobe = &ArtCharacter::RobeFront;
		DrawSaber = &ArtSaber::SaberFront;
		//artsaber.SaberFront((int)Loc.ArtSaber.x, (int)Loc.ArtSaber.y, color, gfx);
		//artcharacter.RobeFront((int)Loc.Artcharacter.x, (int)Loc.Artcharacter.y, gfx);
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
