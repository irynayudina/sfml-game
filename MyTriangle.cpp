#include "MyTriangle.h"
//********************************************************constructors
MyTriangle::MyTriangle(float radius, Color color)
{
	this->radius = radius;
	this->color = color;
	this->triangle = new CircleShape(this->radius, 3);
	this->triangle->setFillColor(this->color);
}

MyTriangle::~MyTriangle()
{
	delete this->triangle;
}
//********************************************************public functions
void MyTriangle::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
	this->triangle->setPosition(this->x, this->y);
}

void MyTriangle::DRAW(RenderWindow* WINDOW)
{
	WINDOW->draw(*triangle);
}
