#pragma once
#include "MyShape.h"
using namespace sf;
class MyCircle : public MyShape
{
private:
	//***********************************variables
	
	float radius;
	Color color;
	float x;
	float y;
public:
	CircleShape* circle;
	//***********************************constructors
	MyCircle(float radius, Color color);
	~MyCircle();
	//***********************************accessors
	float getRadius();
	//***********************************public functions
	void changeColor(Color color);
	void SetPosition(float x, float y);
	void Move(float x, float y);
	void DRAW(RenderWindow* WINDOW) override;
};

