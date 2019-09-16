/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "BackGround.h"
#include "Vec2.h"
#include "Jedi.h"
#include "Trooper.h"
#include "CollisionManager.h"
#include "PlayerSelect.h"
#include "Laser.h"
#include <random>
#include "Collider.h"
#include "Title.h"
#include <list>
class Game
{
	
public:
	enum MenuSelection
	{
		PlayerchoiceMale,
		PlayerchoiceFemale,
		Saberchoiceblue,
		Saberchoicegreen,
		Saberchoicepurple,
		Saberchoicered
	};
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	Vec2 GetMoveDirection(float moveAmount);
	void SaberColorSelect();
	void GenderSelect();
	void MenuSaberSelecting(Keyboard::Event* E);
	void DrawSelectionSaber();
	void seed(std::mt19937* gen);
	int random(int start, int end, std::mt19937& gen);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	std::mt19937 rng;
	BackGround back;
	PlayerSelect headselect;
	Jedi player;


	CollisionManager collidemanager;
	static const int lasermax = 3;
	static constexpr float laserseparation = 70.0f;
	//Laser laser[lasermax];
	static constexpr float trooperwidth = 82.0f;
	static constexpr float trooperheight = 82.0f;
	static constexpr int nTrooperAcross = 7;
	static constexpr int nTrooperDown = 2;
	static constexpr int trooperMax = nTrooperAcross * nTrooperDown;
	static constexpr int nAnimatedStars = 50;
	static constexpr int nRegularStars = 50;
	static constexpr int nStarsMax = 100;
	Vec2 SetLocation{ 70, 358};
	Laser *ActiveBolt;
	Trooper troopers[trooperMax];
	Laser bolt;
	Title animatedStars[nStarsMax];
	Title RegularStars[nStarsMax];
	Title title;
	MenuSelection selectSaber;
	MenuSelection selectCharacter;
	int AnimatedStarCounter = 0;
	int AnimatedStarreset = 100;
	bool gameStarted = false;
	bool SelectingScreen = false;
	
	/********************************/
	/*  User Variables              */
	/********************************/
};