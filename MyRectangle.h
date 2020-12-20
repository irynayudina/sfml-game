#pragma once
#include "MyShape.h"
class MyRectangle : public MyShape
{
private:
	//****************************************varibles
	RectangleShape* rectangle;
	float x;
	float y;
	float width;
	float height;
	Color color;
public:
	//****************************************constructors
	MyRectangle(float width, float height, Color color);
	~MyRectangle();
	//***********************************accessors
	float getWidth();
	float getHeight();
	//****************************************public functions
	void changeColor(Color color);
	void changeSize(float width, float height);
	void SetPosition(float x, float y);
	void Move(float x, float y);
	void DRAW(RenderWindow* WINDOW) override;
};

