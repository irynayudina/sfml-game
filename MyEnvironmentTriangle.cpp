#include "MyEnvironmentTriangle.h"

MyEnvironmentTriangle::MyEnvironmentTriangle(float radius, Color color_inner, Color color_outer)
{
	this->radius = radius;
	this->color_inner = color_inner;
	this->color_outer = color_outer;
	this->outer_triangle = new MyTriangle(this->radius, this->color_outer);
	this->inner_triangle = new MyTriangle((this->radius)- (this->radius)/10, this->color_inner);
}

MyEnvironmentTriangle::~MyEnvironmentTriangle()
{
	delete this->inner_triangle;
	delete this->outer_triangle;
}

void MyEnvironmentTriangle::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
	this->outer_triangle->SetPosition(this->x, this->y);
	this->inner_triangle->SetPosition(this->x, this->y);
}

void MyEnvironmentTriangle::changeColor(Color color)
{
	this->color_outer = color;
	this->outer_triangle->changeColor(this->color_outer);
}

void MyEnvironmentTriangle::DRAW(RenderWindow* WINDOW)
{
	this->outer_triangle->DRAW(WINDOW);
	this->inner_triangle->DRAW(WINDOW);
}
