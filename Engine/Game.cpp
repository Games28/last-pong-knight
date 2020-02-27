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
using namespace std::chrono;
// this is most recent build
Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	player(Vec2(300, 470)),
	rng(std::random_device()()),
	title(Vec2(300, 80)),
	end(Vec2(100, 100)),
	BoltStart(L"Sounds\\blastershot.wav"),
	SaberStart(L"Sounds\\lighsaberOn.wav"),
	SaberDeflect(L"Sounds\\LightsaberClash.wav"),
	BoltDeflect(L"Sounds\\Blaster-Ricochet.wav"),
	//ObiWan(L"Sounds\\obiwan_theforce.wav"),
	//Vader(L"Sounds\\darthvader_powerofthedarkside.wav"),
	//R2d2(L"Sounds\\R2D2-SoundBible.com-460754772.wav"),
	TrooperStep(L"Sounds\\step3.wav"),
	TrooperHit(L"Sounds\\Grenade.wav")
	

{
	Gstate = gameState::TITLE;
	seed(&rng);
	
	TrooperInit();
		for (int i = 0; i < nStarsMax; i++)
		{
			animatedStars[i].Init(rng);
		}
		for (int i = 0; i < nStarsMax; i++)
		{
			RegularStars[i].Init(rng);
		}
	Vec2 BackBoxpos = Vec2(8, 8);
	Vec2 BackBoxsize = Vec2(780, 580);
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

//int Game::swap(int one, int two)
//{
//	int temp = one;
//	one = two;
//	two = temp;
//	return one, two;
//
//}
int Game::suffle(int one)
{
	std::uniform_int_distribution<int> Number(one, trooperMax / 2);
	int randompick = Number(rng);
	return randompick;
}



void Game::changeState(gameState state)
{
	Gstate = state;
}

void Game::StarFormation()
{
	
	if(AnimatedStarCounter < AnimatedStarreset)
	{
		for (int i = 0; i < nRegularStars; i++)
		{
			RegularStars[i].RegularStar(gfx);
		}
		for (int i = 0; i < nAnimatedStars; i++)
		{
			if (AnimatedStarCounter > 50)
			{
				animatedStars[i].DimStar(gfx);
			}
			else if (AnimatedStarCounter < 50)
			{
				animatedStars[i].BrightStar(gfx);

			}
		}
	}
	else {
		AnimatedStarCounter = 0;
	}
	AnimatedStarCounter++;
}

void Game::Randombolt()
{
	
	static int randomtrooper = -1;

	if (randomtrooper == -1)
	{
		do
		{
			randomtrooper = -1;
			randomtrooper = random(0, trooperMax - 1, rng);


		} while (troopers[randomtrooper].isVaporized == true);


		if (troopers[randomtrooper].Bolt.IsActive == false)
		{
			troopers[randomtrooper].Bolt.Spawn(troopers[randomtrooper].loc, rng);
			ActiveBolt = &troopers[randomtrooper].Bolt;
			BoltStart.Play();
		}
	}

	if (troopers[randomtrooper].Bolt.IsActive == false)
	{
		randomtrooper = -1;
	}
}
void Game::TrooperInit()
{
	
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
int Game::random(int start, int end, std::mt19937 gen)
{
	suffle(start);
	std::uniform_int_distribution<int> Number(start, end);
	return Number(gen);
}
void Game::UpdateModel()
{
	float dt = ft.Mark();
	switch (Gstate)
	{
	case gameState::TITLE:
		{
		HasWon = false;
		hasFailed = false;
	
			if (wnd.kbd.KeyIsPressed(VK_RETURN))
			{
				//R2d2.Play();
				changeState(gameState::SELECTION);
			}
			break;
		}
	case gameState::SELECTION: // game selection menu
		{
		
			MenuSaberSelecting(&wnd.kbd.ReadKey());
			SaberColorSelect();
			if (wnd.kbd.KeyIsPressed(VK_SHIFT) && wnd.kbd.KeyIsPressed(VK_RETURN))
			{
				changeState(gameState::GAMESTART);
			}
			break;
		}
	case gameState::GAMESTART: // main game
		{
		 //timeStart = steady_clock::now();
		 
			troopercounting++;
			for (int i = 0; i < trooperMax; i++)
			{
				if (troopercounting >= 20)
				{
					
					troopers[i].Move(troopermovement, dt);
					
				}
				

			}
			if (troopercounting > 20)
			{
				TrooperStep.Play();
				troopercounting = 0;
			}
		
			Randombolt();
			float movementspeed = 200.0f;
			Vec2 moveAmount = GetMoveDirection(movementspeed);
			player.Move(moveAmount, dt);
			Vec2 reflect = collidemanager.GetInnerReflection(player.collider, back.collider);
			if (reflect.GetLengthSq())
			{
				player.collision(reflect);
			}
			//player.GenderSelect();
			GenderSelect();
			player.Update(gfx, wnd.kbd);
			//player.collision(back.collider, dt);
			

			Vec2 reflection = collidemanager.GetInnerReflection(bolt.collider, back.collider);
			//bolt deflection and movement code
			for (int i = 0; i < trooperMax; i++)
			{

				troopers[i].Bolt.Update(dt);
				reflection = collidemanager.GetInnerReflection(troopers[i].Bolt.collider, back.collider);

				if (reflection.GetLengthSq())
				{


					//troopers[i].boltMove(reflection, dt);

					//troopers[i].Bolt.collider.Move(reflection, dt);
					if (reflection.x)
					{
						troopers[i].Bolt.vel.x = -troopers[i].Bolt.vel.x;
						BoltDeflect.Play();
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
					//SaberDeflect.Play();
					//troopers[i].Bolt.vel.x = -troopers[i].Bolt.vel.x;
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
								TrooperHit.Play();
						
									Troopercounter++;
							
								


							}

						}

					}

				}
			}



		}
		if (Troopercounter > 13)
		{
			HasWon = true;
			//ObiWan.Play();
		}
		for (int i = 0; i < trooperMax; i++)
		{
			bool troopervplayer = collidemanager.ReboundTestbool(troopers[i].collider, player.collider );
			if (troopervplayer)
			{
				hasFailed = true;
				//Vader.Play();
			}

		}
		if (HasWon == true || hasFailed == true)
		{
			
			changeState(gameState::GAMEOVER);
			
		}
       
		
		break;
	case gameState::GAMEOVER: // ending
		
		TrooperInit();
		
		
		Troopercounter = 0;
		
		for (int i = 0; i < trooperMax; i++)
		{
			troopers[i].isVaporized = false;

		
		}
		
		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			changeState(gameState::TITLE);
		}
		break;
		
	}
}


void Game::ComposeFrame()
{
	switch (Gstate)
	{
	case gameState::TITLE:
		{

			StarFormation();
			title.DrawTitle(gfx);
			title.DrawPrview(gfx);
			break;
		}
	case gameState::SELECTION:
		{
			StarFormation();
			title.DrawYoda(gfx);
			title.DrawYodaSpeaks(gfx);
			title.DrawSaberMenu(gfx);
			title.DrawJediMenu(gfx);
			//title.DrawSaberSelect0r1(gfx);
			DrawSelectionSaber();
			break;
		}

	case gameState::GAMESTART:
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
		break;
	case gameState::GAMEOVER:
		{
		StarFormation();
		if (HasWon == true)
		{
			end.Yoda(gfx);
			end.Won(gfx);
		}
		else if (hasFailed == true)
		{
			end.darkAnakin(gfx);
			end.Failed(gfx);
		}
			
		}
		break;
	}
}
