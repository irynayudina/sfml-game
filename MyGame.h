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

	//************************************************game logic///////////////////////////////////////////////////////
	//int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//***********************************************game objects////////////////////////////////////////////////
	std::vector<RectangleShape> enemies;
	RectangleShape enemy;






	//***********************************************environment objects
	std::vector<MyEnvironmentTriangle> environment_triangles;
	MyEnvironmentTriangle* tr;// (float, *this->background_color, *this->objects_color);
	std::vector<MyEnvironmentCircle> environment_circles;
	MyEnvironmentCircle* cir;
	//***********************************************menu and control objects
	std::vector<MyButton> color_buttons;
	MyButton* start_char;
	MyButton* stop_char;
	MyButton* restart_char;
	//***********************************************the main character objects
	MyCharacter* charecter;

	//***********************************************general variables
	int gap_between_environment_elements;//170
	int size_of_environment_elements;//80
	int padding;//85
	Color* background_color;//black
	Color* objects_color;//purple
	int rows_of_env_elem;//3



	//*************************************************************************functions*******************************
	//***************************************************************************************************************************


	//**********************************************private functions
	void InitVariables();
	void InitWindow();
	void initEnemies();////////////////////////////////////////////////////////////////////////////////////////////////////////
public:
	//*********************************************constructors and destructors
	MyGame();
	virtual ~MyGame();

	//*********************************************accessors
	const bool running() const;

	//********************************************functions 
	void pollEvents();
	void uppdateMousePositions();
	void spawnEnemy();////////////////////////////////////////////////////////////////////////////////////////////////////
	void uppdateEnemies();//////////
	void renderEnemies();/////////
	void uppdate();
	void render();

	void initTriangle();
	void initTriangles();//puts equal custom triangles to vector sets position in the screen of each element in the vector
	void draw_triangles();//draws to the screen renders
	void initCircle();
	void initCircles();// puts equal custom circles to vector sets position in the screen of each element in the vector
	void draw_circles();//draws to the screen renders


//***************************************************************************************button functions
	void change_color_onclick();
	void start_onclick();
	void stop_onclick();
	void restart_onclick();




//****************************************************************************************
	void move_main_char();

};

