/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <iostream>

// this is most recent build
Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	player(Vec2(300, 470)),
	rng(std::random_device()()),
	title(Vec2(300,80))
	

{
	seed(&rng);
	Vec2 Trooper(105, 40);
	//int randombolt = random;
	int i = 0;
	//inits the troopers
	
		for (int y = 0; y < nTrooperDown; y++)
		{

			for (int x = 0; x < nTrooperAcross; x++)
			{

				
				
					troopers[i].loc = Vec2(Trooper.x + (x * trooperwidth), Trooper.y + (y * trooperheight));
					troopers[i].collider.Init(troopers[i].loc, Vec2(trooperwidth, trooperheight));
					troopers[i].Bolt.loc = troopers[i].loc + Vec2(trooperwidth * 0.4f, trooperheight) * 0.5f;
					troopers[i].Bolt.Init(troopers[i].Bolt.loc);

					i++;
				
			}

		}
	
	for (int i = 0; i < nStarsMax; i++)
	{
		animatedStars[i].Init(rng);
	}
	for (int i = 0; i < nStarsMax; i++)
	{
		RegularStars[i].Init(rng);
	}
	Vec2 BackBoxpos = Vec2(1, 1);
	Vec2 BackBoxsize = Vec2((int)Graphics::ScreenWidth - 5, (int)Graphics::ScreenHeight - 5);
	back.collider.Init(BackBoxpos, BackBoxsize);
	
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::seed(std::mt19937* gen)
{
	std::random_device rd;
	gen->seed(rd());
	
}
int Game::random(int start, int end, std::mt19937 gen)
{
	
	std::uniform_int_distribution<int> Number(start, end);
	return Number(gen);
}
void Game::UpdateModel()
{
	//wnd.kbd.ReadChar();
	static int randomtrooper = -1;
	//for (int i = 0; i < trooperMax; i++)
	//{
	if (randomtrooper == -1)
	{
		do
		{
			randomtrooper = random(0, trooperMax - 1, rng);


		} while (troopers[randomtrooper].isVaporized == true);
		if (troopers[randomtrooper].Bolt.IsActive == false)
		{
			troopers[randomtrooper].Bolt.Spawn(troopers[randomtrooper].loc, rng);
			ActiveBolt = &troopers[randomtrooper].Bolt;
		}
	}
	//}
	if (troopers[randomtrooper].Bolt.IsActive == false)
	{
		randomtrooper = -1;
	}
	if (!SelectingScreen)
	{
		AnimatedStarCounter++;
		if (AnimatedStarCounter >= AnimatedStarreset)
		{
			AnimatedStarCounter = 0;
		}
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			SelectingScreen = true;
		}
	}
	else if (!gameStarted) // selection menu
	{
		AnimatedStarCounter++;
		if (AnimatedStarCounter >= AnimatedStarreset)
		{
			AnimatedStarCounter = 0;
		}
		if (wnd.kbd.KeyIsPressed(VK_SHIFT))
		{
			if (wnd.kbd.KeyIsPressed(VK_RETURN))
			{
				gameStarted = true;
			}
		}
		MenuSaberSelecting(&wnd.kbd.ReadKey());
		SaberColorSelect();
	}
	if (gameStarted && SelectingScreen)
	{
		float movementspeed = 10.0f;
		Vec2 moveAmount = GetMoveDirection(movementspeed);
		player.Move(moveAmount);

		//player.GenderSelect();
		GenderSelect();
		player.Update(gfx, wnd.kbd);
		player.collision(back.collider);

	
		Vec2 reflection = collidemanager.GetInnerReflection(bolt.collider, back.collider);
		//bolt deflection and movement code
		for (int i = 0; i < trooperMax; i++)
		{

			troopers[i].Bolt.Update();
			reflection = collidemanager.GetInnerReflection(troopers[i].Bolt.collider, back.collider);

			if (reflection.GetLengthSq())
			{
				
				
				troopers[i].Move(reflection);
				
				troopers[i].Bolt.collider.Move(reflection);
				if (reflection.x)
				{
					troopers[i].Bolt.vel.x = -troopers[i].Bolt.vel.x;
				}
				if (reflection.y)
				{
					troopers[i].Bolt.loc = troopers[i].loc;
					troopers[i].Bolt.IsActive = false;
				}
			}

		}
		//lightsaber and bolt deflection

		for (int i = 0; i < trooperMax; i++)
		{

			bool Redirection = collidemanager.ReboundTestbool(troopers[i].Bolt.collider, player.saber.collider);
			if (Redirection)
			{
				troopers[i].Bolt.vel.y = -troopers[i].Bolt.vel.y;
				troopers[i].Bolt.vel.x = -troopers[i].Bolt.vel.x;
			}
		}
		
		// trooper and bolt collision
		if (ActiveBolt->IsActive == true)
		{
			
			for (int i = 0; i < trooperMax; i++)
			{
				bool TrooperCollision = collidemanager.ReboundTestbool(ActiveBolt->collider, troopers[i].collider);
				if (troopers[i].isVaporized == false)
				{
					if (TrooperCollision)
					{
						if (ActiveBolt->vel.y < 0.0f)
						{
							ActiveBolt->IsActive = false;
							troopers[i].isVaporized = true;
						}
						
					}
					
				}
			}
		}
		
		
		
	}
			
}

Vec2 Game::GetMoveDirection(float moveAmount)
{
	Vec2 finalMoveAmount = Vec2(0.0f, 0.0f);

	
	if (wnd.kbd.KeyIsPressed('A'))
	{
		finalMoveAmount += Vec2(-moveAmount, 0);
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		finalMoveAmount += Vec2(moveAmount, 0);
	}
	return finalMoveAmount;
}

void Game::SaberColorSelect()
{
	unsigned char ColorValue = 127;
	switch (selectSaber)
	{
	case MenuSelection::Saberchoiceblue:
	{
		player.saber.color[0] = Color{ 0,0,0 };
		player.saber.color[1] = Color{ 0,0,ColorValue };
		break;
	}

	case MenuSelection::Saberchoicegreen:
	{
		player.saber.color[0] = Color{ 0,0,0 };
		player.saber.color[1] = Color{ 0,ColorValue,0 };
		break;

	}
	case MenuSelection::Saberchoicered:
	{
		player.saber.color[0] = Color{ 0,0,0 };
		player.saber.color[1] = Color{ ColorValue,0,0 };
		break;

	}
	case MenuSelection::Saberchoicepurple:
	{
		player.saber.color[0] = Color{ 0,0,0 };
		player.saber.color[1] = Color{ ColorValue,0,ColorValue };
		break;

	}
	default:
	{
		break;
	}
	}
}

void Game::GenderSelect()
{
	switch (selectCharacter)
	{
	case MenuSelection::PlayerchoiceFemale:
		{
			headselect = PlayerSelect::FEMALE;
			break;
		}
		
	case MenuSelection::PlayerchoiceMale:
		{
			headselect = PlayerSelect::MALE;
			break;
		}
	default:
		{
			break;
		}
	}
}

void Game::MenuSaberSelecting(Keyboard::Event* E)
{
	char C = E->GetCode();
	if (E->IsPress())
	{
		switch (C)
		{
		case '1':
		{
			selectSaber = MenuSelection::Saberchoiceblue;
			break;
		}
		case '2':
		{
			selectSaber = MenuSelection::Saberchoicegreen;
			break;
		}
		case '3':
		{
			selectSaber = MenuSelection::Saberchoicered;
			break;
		}
		case '4':
		{
			selectSaber = MenuSelection::Saberchoicepurple;
			break;
		}

		case 'F':
		{
			selectCharacter = MenuSelection::PlayerchoiceFemale;
			break;
		}
		case 'M':
		{
			selectCharacter = MenuSelection::PlayerchoiceMale;
			break;
		}
		default:
		{
			break;
		}

		}
	}
}
void Game::DrawSelectionSaber()
{
	if (selectSaber == MenuSelection::Saberchoiceblue)
	{
		title.art.SelectingSaber1(400, 335, gfx);
	}
	if (selectSaber == MenuSelection::Saberchoicegreen)
	{
		title.art.SelectingSaber1(400, 385, gfx);
	}
	if (selectSaber == MenuSelection::Saberchoicered)
	{
		title.art.SelectingSaber1(400, 435, gfx);
	}
	if (selectSaber == MenuSelection::Saberchoicepurple)
	{
		title.art.SelectingSaber1(400, 500, gfx);
	}
	if (selectCharacter == MenuSelection::PlayerchoiceFemale)
	{
		title.art.SelectingSaber1(100, 430, gfx);
	}
	if (selectCharacter == MenuSelection::PlayerchoiceMale)
	{
		title.art.SelectingSaber1(100, 360, gfx);
	}
}
void Game::ComposeFrame()
{
	if (!SelectingScreen)
	{
		
		for (int i = 0; i < nRegularStars; i++)
		{
			RegularStars[i].DrawRegularStar(gfx);
		}
		for (int i = 0; i < nAnimatedStars; i++)
		{
			if (AnimatedStarCounter > 50)
			{
				animatedStars[i].DrawDimStar(gfx);
			}
			else if (AnimatedStarCounter < 50)
			{
				animatedStars[i].DrawBrightStar(gfx);

			}
		}
		title.DrawTitle(gfx);
		title.DrawPrview(gfx);
	}
	else if (!gameStarted)
	{
		for (int i = 0; i < nRegularStars; i++)
		{
			RegularStars[i].DrawRegularStar(gfx);
		}
		for (int i = 0; i < nAnimatedStars; i++)
		{
			if (AnimatedStarCounter > 50)
			{
				animatedStars[i].DrawDimStar(gfx);
			}
			else if (AnimatedStarCounter < 50)
			{
				animatedStars[i].DrawBrightStar(gfx);

			}
		}
		title.DrawYoda(gfx);
		title.DrawYodaSpeaks(gfx);
		title.DrawSaberMenu(gfx);
		title.DrawJediMenu(gfx);
	    //title.DrawSaberSelect0r1(gfx);
		DrawSelectionSaber();
	}
	if (gameStarted && SelectingScreen)
	{
		back.Draw(gfx);
		//Draws player character
		player.Update(gfx, wnd.kbd);
		player.Draw(gfx);

		//Draws array of troopers
		for (int i = 0; i < trooperMax; i++)
		{
			troopers[i].Draw(gfx);

		}
		for (int i = 0; i < trooperMax; i++) {
			if (troopers[i].Bolt.IsActive)
			{
				troopers[i].Bolt.Draw(gfx);
			}
		}

		
		player.saber.saberColorChange();
		if (headselect == PlayerSelect::FEMALE)
		{
			player.FemaleJedi(gfx);
		}
		else if (headselect == PlayerSelect::MALE)
		{
			player.MaleJedi(gfx);
		}
	}
	

}
