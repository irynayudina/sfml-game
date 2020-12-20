#pragma once
#include "MyShape.h"
using namespace sf;
class MyTriangle : public MyShape	
{
private:
	//***********************************variables
	CircleShape* triangle;
	float radius;
	Color color;
	float x;
	float y;
public:
	//***********************************constructors
	MyTriangle(float radius, Color color);
	~MyTriangle();
	//***********************************public function
	void SetPosition(float x, float y);
	void DRAW(RenderWindow* WINDOW) override;
};

