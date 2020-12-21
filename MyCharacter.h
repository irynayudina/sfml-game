#pragma once
#include "MyCircle.h"
#include "MyRectangle.h"
class MyCharacter
{
private:
	//*********************************************variables
	float x;
	float y;
	float width;
	float height;
	Color color;
	//*********************************************body parts
	MyRectangle* left;
	MyRectangle* centre;
	MyRectangle* right;
	
public:
	MyCircle* central_circle;
	//*********************************************constructors
	MyCharacter(float width, float height, Color color);
	~MyCharacter();
	//*********************************************public functions
	void changeColor(Color color);
	void SetPosition(float x, float y);//here
	void Move(float x, float y);
	void deform();//here///////////////////////////////////////////////////////////////////////////
	void GetGlobalBounds();
	void DRAW(RenderWindow* WINDOW);
};

