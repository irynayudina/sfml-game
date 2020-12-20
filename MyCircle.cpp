#include "MyCircle.h"


//***********************************constructors
MyCircle::MyCircle(float radius, Color color)
{
	this->x = 0;
	this->y = 0;
	this->radius = radius;
	this->color = color;
	this->circle = new CircleShape(this->radius);
	this->circle->setFillColor(this->color);
}

MyCircle::~MyCircle()
{
	delete this->circle;
}
//***********************************accessors
float MyCircle::getRadius()
{
	return this->radius;
}
//***********************************public functions
void MyCircle::changeColor(Color color)
{
	this->color = color;
	this->circle->setFillColor(this->color);
}

void MyCircle::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
	this->circle->setPosition(this->x, this->y);
}

void MyCircle::Move(float x, float y)
{
	this->circle->move(x, y);
	this->x += x;
	this->y += y;
}

void MyCircle::DRAW(RenderWindow* WINDOW)
{
	WINDOW->draw(*this->circle);
}
