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
	title(Vec2(300,200))

{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> Boltrandomized(1, trooperMax);
	Vec2 Trooper(105, 40);
	//int randombolt = random;
	int i = 0;
	//inits the troopers
	for (int y = 0; y < nTrooperDown; y++)
	{
		
		for (int x = 0; x < nTrooperAcross; x++)
		{
			troopers[i].loc = Vec2(Trooper.x + (x * trooperwidth), Trooper.y + (y * trooperheight));
			troopers[i].collider.Init(Vec2(Trooper.x,Trooper.y), Vec2(x* trooperwidth, y*trooperheight));
			troopers[i].Bolt.loc = troopers[i].loc + Vec2(trooperwidth * 0.4f, trooperheight) * 0.5f;
			troopers[i].Bolt.Init(troopers[i].Bolt.loc, rng);
			//if (i == Boltrandomized(gen))
			//{
			//	
			//	
			//}
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

void Game::UpdateModel()
{
	float movementspeed = 10.0f;
	Vec2 moveAmount = GetMoveDirection(movementspeed);
	player.Move(moveAmount);

	player.GenderSelect();
	player.Update(gfx, wnd.kbd);
	player.collision(back.collider);

	AnimatedStarCounter++;
	if (AnimatedStarCounter >= AnimatedStarreset)
	{
		AnimatedStarCounter = 0;
	}



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
				troopers[i].Bolt.vel.y = -troopers[i].Bolt.vel.y;
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
			//	Vec2 Redirection = collidemanager.Rebound(troopers[i].Bolt.collider,player.saber.collider);
			//	if (Redirection.GetLengthSq())
			//	{
			//	
			//		troopers[i].Move(reflection);
			//	
			//		troopers[i].Bolt.collider.Move(reflection);
			//		
			//		if (Redirection.y)
			//		{
			//			troopers[i].Bolt.vel.y = -troopers[i].Bolt.vel.y;
			//		}
			//	}
			//
		
			
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
	if (wnd.kbd.KeyIsPressed('1'))
	{
		player.saber.color[0] = Color{ 0,0,0 };
		player.saber.color[1] = Color{ 0,0,ColorValue };
	}
	if (wnd.kbd.KeyIsPressed('2'))
	{
		player.saber.color[0] = Color{ 0,0,0 };
		player.saber.color[1] = Color{ 0,ColorValue,0 };
		
	}
	if (wnd.kbd.KeyIsPressed('3'))
	{
		player.saber.color[0] = Color{ 0,0,0 };
		player.saber.color[1] = Color{ ColorValue,0,0 };
		
	}
	if (wnd.kbd.KeyIsPressed('4'))
	{
		player.saber.color[0] = Color{ 0,0,0 };
		player.saber.color[1] = Color{ ColorValue,0,ColorValue };
		
	}
}

void Game::GenderSelect()
{
	if (wnd.kbd.KeyIsPressed('F'))
	{
		headselect = PlayerSelect::FEMALE;
	}
	if (wnd.kbd.KeyIsPressed('M'))
	{
		headselect = PlayerSelect::MALE;
	}
}

void Game::Boltrebound()
{
	

}
void Game::ComposeFrame()
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
		
	
	SaberColorSelect();
	player.saber.saberColorChange();
	

	

}
