#include "MyRectangle.h"
//***************************************************************constructors
MyRectangle::MyRectangle(float width, float height, Color color)
{
	this->color = color;
	this->height = height;
	this->width = width;
	this->rectangle = new RectangleShape(Vector2f(this->width, this->height));
	this->rectangle->setFillColor(this->color);

}

MyRectangle::~MyRectangle()
{
	delete this->rectangle;
}
//***************************************************************accessors
float MyRectangle::getWidth()
{
	return this->width;
}

float MyRectangle::getHeight()
{
	return this->height;
}
//***************************************************************public functions
void MyRectangle::changeColor(Color color)
{
	this->color = color;
	this->rectangle->setFillColor(this->color);
}

void MyRectangle::changeSize(float width, float height)
{
	this->rectangle->setSize(Vector2f(width, height));
	this->height = height;
	this->width = width;
}

void MyRectangle::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
	this->rectangle->setPosition(this->x, this->y);
}

void MyRectangle::Move(float x, float y)
{
	this->rectangle->move(x, y);
	this->x += x;
	this->y += y;
}

void MyRectangle::Rotate(int d)
{
	this->rectangle->rotate(d);
}

void MyRectangle::DRAW(RenderWindow* WINDOW)
{
	WINDOW->draw(*rectangle);
}
