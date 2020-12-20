#include "MyCharacter.h"

//********************************************************************constructors
MyCharacter::MyCharacter(float width, float height, Color color)
{
	this->width = width;
	this->height = height;
	this->color = color;
	this->outer_rectangle = new MyRectangle(this->width, this->height, this->color);
	this->inner_rectangle = new MyRectangle((this->width) - ((this->width) / 5), (this->height) - ((this->height) / 5), this->color);
	this->horizontal_line = new MyRectangle(this->width, (this->height) / 10, this->color);
	this->vertical_line = new MyRectangle((this->width) / 10, this->height, this->color);
	this->central_circle = new MyCircle(this->height, this->color);
}

MyCharacter::~MyCharacter()
{
	delete this->outer_rectangle;
	delete this->inner_rectangle;
	delete this->horizontal_line;
	delete this->vertical_line;
	delete this->central_circle;
}
//********************************************************************public functions
void MyCharacter::changeColor(Color color)
{
	this->color = color;
	this->central_circle->changeColor(this->color);
	this->vertical_line->changeColor(this->color);
	this->horizontal_line->changeColor(this->color);
	this->inner_rectangle->changeColor(this->color);
	this->outer_rectangle->changeColor(this->color);
}

void MyCharacter::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
	this->outer_rectangle->SetPosition(this->x, this->y);
	this->inner_rectangle->SetPosition((this->x)+((this->width)/10), (this->y) + ((this->height) / 10));
	this->horizontal_line->SetPosition((this->x) + ((this->width) / 2.2222222222222222), (this->y));
	this->vertical_line->SetPosition((this->x), (this->y) + ((this->height) / 2.2222222222222222));
	this->central_circle->SetPosition((this->x) + ((this->width) / 2), (this->y) + ((this->height) / 2));
}

void MyCharacter::Move(float x, float y)
{
	this->outer_rectangle->Move(x, y);
	this->inner_rectangle->Move(x, y);
	this->horizontal_line->Move(x, y);
	this->vertical_line->Move(x, y);
	this->central_circle->Move(x, y);
	this->x += x;
	this->y += y;
}

void MyCharacter::deform()
{

}

void MyCharacter::DRAW(RenderWindow* WINDOW)
{
	outer_rectangle->DRAW(WINDOW);
	inner_rectangle->DRAW(WINDOW);
	horizontal_line->DRAW(WINDOW);
	vertical_line->DRAW(WINDOW);
	central_circle->DRAW(WINDOW);
}
