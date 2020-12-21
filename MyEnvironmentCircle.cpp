#include "MyEnvironmentCircle.h"

MyEnvironmentCircle::MyEnvironmentCircle(float radius, Color color_inner, Color color_outer)
{
	this->radius = radius;
	this->color_inner = color_inner;
	this->color_outer = color_outer;
	this->outer_circle = new MyCircle(this->radius, this->color_outer);
	this->inner_circle = new MyCircle((this->radius) - (this->radius) / 10, this->color_inner);
}

MyEnvironmentCircle::MyEnvironmentCircle()
{
}

MyEnvironmentCircle::~MyEnvironmentCircle()
{
	delete this->inner_circle;
	delete this->outer_circle;
}

void MyEnvironmentCircle::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
	this->outer_circle->SetPosition(this->x, this->y);
	this->inner_circle->SetPosition(this->x + (this->radius) / 10, this->y + (this->radius) / 10);
}

void MyEnvironmentCircle::changeColor(Color color)
{
	this->color_outer = color;
	this->outer_circle->changeColor(this->color_outer);
}

void MyEnvironmentCircle::DRAW(RenderWindow* WINDOW)
{
	this->outer_circle->DRAW(WINDOW);
	this->inner_circle->DRAW(WINDOW);
}
