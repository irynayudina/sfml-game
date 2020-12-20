#include "MyButton.h"
 

 MyButton::MyButton(float width, float height, Color color_outer, Color color_inner)
 {
	 this->width = width;
	 this->height = height;
	 this->color_outer = color_outer;
	 this->color_inner = color_inner;
	 this->outer_rectangle = new MyRectangle(this->width, this->height, this->color_outer);
	 this->inner_rectangle = new MyRectangle((this->width) - (this->width) / 10, (this->height) - (this->width) / 10, this->color_inner);
 }

 MyButton::~ MyButton()
{
	 delete this->inner_rectangle;
	 delete this->outer_rectangle;
}

 void MyButton::SetPosition(float x, float y)
 {
	 this->x = x;
	 this->y = y;
	 this->inner_rectangle->SetPosition((this->x) + (this->height) / 20, (this->y) + (this->height) / 20); 
	 this->outer_rectangle->SetPosition(this->x, this->y);
 }

 void MyButton::DRAW(RenderWindow* WINDOW)
 {
	 this->outer_rectangle->DRAW(WINDOW);
	 this->inner_rectangle->DRAW(WINDOW);
 }
