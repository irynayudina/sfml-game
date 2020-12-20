#pragma once
/*
The game engine class
*/
#include <ctime>
#include <vector>
#include <iostream>
#include "MyCharacter.h"
#include "MyEnvironmentCircle.h"
#include "MyEnvironmentTriangle.h"
#include "MyButton.h"
class MyGame
{
private:
	//*************************************************************variables********************
	//*****************************************************************************************************


	//*************************************************window 
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;

	//*************************************************mouse positions
	Vector2i mousePosWindow;
	Vector2f mousePosView;

	//************************************************game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//***********************************************game objects
	std::vector<RectangleShape> enemies;
	RectangleShape enemy;


	//*************************************************************************functions*******************************
	//***************************************************************************************************************************


	//**********************************************private functions
	void InitVariables();
	void InitWindow();
	void initEnemies();
public:
	//*********************************************constructors and destructors
	MyGame();
	virtual ~MyGame();

	//*********************************************accessors
	const bool running() const;

	//********************************************functions 
	void pollEvents();
	void uppdateMousePositions();
	void spawnEnemy();
	void uppdateEnemies();
	void renderEnemies();
	void uppdate();
	void render();
};

