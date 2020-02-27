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
#include "Stars.h"
#include "EndScrene.h"
#include "Sound.h"
#include "FrameTimer.h"
#include <chrono>
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
	enum gameState
	{
		TITLE,
		SELECTION,
		GAMESTART,
		GAMEOVER
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
	//int swap(int one, int two);
	int suffle(int one);
	void changeState(gameState state);
	void StarFormation();
	void Randombolt();
	void TrooperInit();
	int random(int start, int end, std::mt19937 gen);
	void frameTime();
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
	Sound SaberStart;
	Sound SaberDeflect;
	Sound BoltStart;
	Sound BoltDeflect;
	//Sound ObiWan;
	//Sound Vader;
	//Sound R2d2;
	Sound TrooperStep;
	Sound TrooperHit;

	CollisionManager collidemanager;
	static const int lasermax = 3;
	static constexpr float laserseparation = 70.0f;
	//Laser laser[lasermax];
	static constexpr float trooperwidth = 82.0f;
	static constexpr float trooperheight = 82.0f;
	static constexpr int nTrooperAcross = 7;
	static constexpr int nTrooperDown = 2;
	static constexpr int trooperMax = nTrooperAcross * nTrooperDown;
	gameState Gstate;
	Vec2 SetLocation{ 70, 358 };
	Laser* ActiveBolt;
	Trooper troopers[trooperMax];
	Laser bolt;
	EndScrene end;
	Title title;
	FrameTimer ft;
	MenuSelection selectSaber;
	MenuSelection selectCharacter;
	int AnimatedStarCounter = 0;
	int AnimatedStarreset = 100;
	int Troopercounter = 0;
	bool gameOver = false;
	bool gameStarted = false;
	bool SelectingScreen = false;
	bool hasFailed = false;
	bool HasWon = false;
	static constexpr int nAnimatedStars = 50;
	static constexpr int nRegularStars = 50;
	static constexpr int nStarsMax = 100;
	Stars animatedStars[nStarsMax];
	Stars RegularStars[nStarsMax];
	Vec2 troopermovement{0, 35};
	int troopercounting = 0;
	std::chrono::steady_clock::time_point timeStart;
	/********************************/
	/*  User Variables              */
	/********************************/
};