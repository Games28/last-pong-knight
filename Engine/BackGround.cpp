#include "BackGround.h"
#include "ArtCharacter.h"





void BackGround::Draw(Graphics & gfx)
{
	
	Vec2 StairTop(0, 500);
	gfx.DrawRectDim((int)StairTop.x, (int)StairTop.y, 800,
		100, Colors::MakeRGB(230, 200, 100)); //Colors::MakeRGB(190,50,0)
	Vec2 ArmLeft(0, 0);
	gfx.DrawRectDim((int)ArmLeft.x, (int)ArmLeft.y, 100, 490, Colors::MakeRGB(250, 180, 80));
	Vec2 ArmRight(700, 0);
	gfx.DrawRectDim((int)ArmRight.x, (int)ArmRight.y, 100, 490, Colors::MakeRGB(250, 180, 80));
	Vec2 shadow1(0, 150);
	gfx.DrawRectDim((int)shadow1.x, (int)shadow1.y, 100, 10, Colors::Black);
	Vec2 shadow2(0, 350);
	gfx.DrawRectDim((int)shadow2.x, (int)shadow2.y, 100, 10, Colors::Black);
	Vec2 shadow3(700, 150);
	gfx.DrawRectDim((int)shadow3.x, (int)shadow3.y, 100, 10, Colors::Black);
	Vec2 shadow4(700, 350);
	gfx.DrawRectDim((int)shadow4.x, (int)shadow4.y, 100, 10, Colors::Black);
	Vec2 Statue1(20, 30);
	jediStatue[0].Statue((int)Statue1.x, (int)Statue1.y, gfx);
	Vec2 Statue2(20, 230);
	jediStatue[1].Statue((int)Statue2.x, (int)Statue2.y, gfx);
	Vec2 Statue3(720, 30);
	jediStatue[2].Statue((int)Statue3.x, (int)Statue3.y, gfx);
	Vec2 Statue4(720, 230);
	jediStatue[3].Statue((int)Statue4.x, (int)Statue4.y, gfx);

	const Color colors[7] = { Colors::MakeRGB(180, 150, 70),
								Colors::MakeRGB(190,50,0) ,
								Colors::MakeRGB(180, 150, 70),
								Colors::MakeRGB(180, 150, 70),
								Colors::MakeRGB(180, 150, 70),
								Colors::MakeRGB(190,50,0) , 
								Colors::MakeRGB(180, 150, 70) };
	Vec2 Step(105.0f, 10.0f); //start location
	
	int i = 0;
	for (int y = 0; y < nstepsdown; y++)
	{
		
		for (int x = 0; x < nstepsAcross; x++)
		{
			const Color c = colors[x];
			steps[i] = Square(RectF(Step + Vec2(x * stepWidth, y * stepHeight),
				stepWidth, stepHeight), c);  // Colors::MakeRGB(180, 150, 70)
			i++;
		}
	}
	for (Square& S : steps)
	{
		S.Draw(gfx);
	}
	//collider.DrawBox(gfx, Colors::Green);
}
