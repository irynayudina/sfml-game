#pragma once
#include "MyTriangle.h"
class MyEnvironmentTriangle
{
private:
	MyTriangle* outer_triangle;
	MyTriangle* inner_triangle;
	float radius;
	Color color_inner;
	Color color_outer;
	float x;
	float y;
public:
	MyEnvironmentTriangle(float radius, Color color_inner, Color color_outer);
	MyEnvironmentTriangle();
	~MyEnvironmentTriangle();
	void SetPosition(float x, float y);
	int getX();
	void changeColor(Color color);
	void DRAW(RenderWindow* WINDOW);
};

