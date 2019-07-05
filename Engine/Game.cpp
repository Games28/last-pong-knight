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

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	player(Vec2(300, 470), Vec2(345, 420), Vec2(328, 470))//Character(Vec2& loc,Vec2& saber, Vec2& head );

{
	
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
			
			Vec2 Playerboxpos = player.Loc.Artcharacter - Vec2( 40,  10 );
			Vec2 Playerboxsize = player.charactersize;
			player.collider.Init(Playerboxpos, Playerboxsize);
			Vec2 BackBoxpos = Vec2(1, 1);
			Vec2 BackBoxsize = Vec2((int)Graphics::ScreenWidth - 5, (int)Graphics::ScreenHeight - 5);
			back.collider.Init(BackBoxpos, BackBoxsize);
			Vec2 reflection = collidemanager.GetInnerReflection(player.collider, back.collider);
			if (reflection.GetLengthSq())
			{
				player.Move(reflection);
			}
			if (wnd.kbd.KeyIsPressed('F'))
			{
				headselect = PlayerSelect::FEMALE;
		     }
			if (wnd.kbd.KeyIsPressed('M'))
			{
				headselect = PlayerSelect::MALE;
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
	if (wnd.kbd.KeyIsPressed('1'))
	{
		player.color[0] = Color{ 0,0,0 };
		player.color[1] = Color{ 0,0,ColorValue };
	}
	if (wnd.kbd.KeyIsPressed('2'))
	{
		player.color[0] = Color{ 0,0,0 };
		player.color[1] = Color{ 0,ColorValue,0 };
		
	}
	if (wnd.kbd.KeyIsPressed('3'))
	{
		player.color[0] = Color{ 0,0,0 };
		player.color[1] = Color{ ColorValue,0,0 };
		
	}
	if (wnd.kbd.KeyIsPressed('4'))
	{
		player.color[0] = Color{ 0,0,0 };
		player.color[1] = Color{ ColorValue,0,ColorValue };
		
	}
}

void Game::ComposeFrame()
{
	back.Draw(gfx);
	if (player.DrawHead != NULL)
	{
		player.Draw(gfx, wnd.kbd);
	}

	Vec2 trooper(105, 20);
	int i = 0;
	for (int y = 0; y < nTrooperDown; y++)
	{
		for (int x = 0; x < nTrooperAcross; x++)
		{
			troopers[i].artcharacter.StormTrooper(trooper.x +(x  * trooperwidth),trooper.y + (y* trooperheight), gfx);
		}
		i++;
	}
	SaberColorSelect();
	player.SaberBackColorChange();
	if (headselect == PlayerSelect::FEMALE)
	{
		player.DrawHead = &Arthead::FemaleHead;
	}
	if (headselect == PlayerSelect::MALE)
	{
		player.DrawHead = &Arthead::MaleHead;
	}

}
