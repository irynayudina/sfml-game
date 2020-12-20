#pragma once 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
class MyShape 
{
public:
	virtual void DRAW(RenderWindow* WINDOW);
};