#pragma once
#include "MyShape.h"
using namespace sf;
class MyTriangle : public MyShape	
{
private:
	//***********************************variables
	
	float radius;
	Color color;
	float x;
	float y;
public:
	CircleShape* triangle;
	//***********************************constructors
	MyTriangle(float radius, Color color);
	~MyTriangle();
	//***********************************public function
	void SetPosition(float x, float y);
	void changeColor(Color color);
	void DRAW(RenderWindow* WINDOW) override;
};

