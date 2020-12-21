#pragma once
#include "MyRectangle.h"
class MyButton
{
private:
	MyRectangle* inner_rectangle;
	MyRectangle* outer_rectangle;
	float x;
	float y;
	float width;
	float height;
	Color color_inner;
	Color color_outer;
public:
	MyButton(float width, float height, Color color_outer, Color color_inner);
	MyButton();
	~MyButton();
	void SetPosition(float x, float y);
	float getY();
	void ChangeColor(Color color);
	Color getColor();
	void DRAW(RenderWindow* WINDOW);
	std::function<bool(int, int)> fcn;
	//(void) (*onclick)(MyCharacter* _char);
};

