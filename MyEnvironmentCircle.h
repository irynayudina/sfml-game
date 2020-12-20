#pragma once
#include "MyCircle.h"
class MyEnvironmentCircle
{
private:
	MyCircle* outer_circle;
	MyCircle* inner_circle;
	float radius;
	Color color_inner;
	Color color_outer;
	float x;
	float y;
public:
	MyEnvironmentCircle(float radius, Color color_inner, Color color_outer);
	~MyEnvironmentCircle();
	void SetPosition(float x, float y);
	void changeColor(Color color);
	void DRAW(RenderWindow* WINDOW);
};

