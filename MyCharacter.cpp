#include "MyCharacter.h"

//********************************************************************constructors
MyCharacter::MyCharacter(float width, float height, Color color)
{
	this->x = 0;
	this->y = 0;
	this->width = width;
	this->height = height;
	this->color = color;
	this->left = new MyRectangle(this->width/4, (this->height) * 5, this->color);
	this->centre = new MyRectangle(this->width / 4, (this->height) * 5, this->color);
	this->right = new MyRectangle(this->width / 4, (this->height) * 5, this->color);
	this->central_circle = new MyCircle(this->height, this->color);
}

MyCharacter::~MyCharacter()
{
	delete this->left;
	delete this->centre;
	delete this->right;
	delete this->central_circle;
}
//********************************************************************public functions
void MyCharacter::changeColor(Color color)
{
	this->color = color;
	this->central_circle->changeColor(this->color);
	this->left->changeColor(this->color);
	this->centre->changeColor(this->color);
	this->right->changeColor(this->color);
}

void MyCharacter::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
	this->left->SetPosition(this->x, this->y - 1.5 * this->width);
	//this->left->Rotate(-45);
	this->centre->SetPosition((this->x) + 1 * this->width - this->width/4, (this->y) - 1.5 * this->width);
	//this->centre->Rotate(90);
	this->right->SetPosition(this->x + 1* this->width*2 - this->width / 4, this->y - 1.5 * this->width);
	//this->right->Rotate(-45);
	this->central_circle->SetPosition((this->x), (this->y));
}

void MyCharacter::Move(float x, float y)
{
	this->left->Move(x, y);
	this->centre->Move(x, y);
	this->right->Move(x, y);
	this->central_circle->Move(x, y);
	this->x += x;
	this->y += y;
}

void MyCharacter::deform()
{
	this->left->Rotate(-45);
}

void MyCharacter::DRAW(RenderWindow* WINDOW)
{
	left->DRAW(WINDOW);
	centre->DRAW(WINDOW);
	right->DRAW(WINDOW);
	central_circle->DRAW(WINDOW);
}
