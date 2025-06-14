#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Ball
{
private:
	sf::CircleShape circle;

private:
	void initShape();


public:
	Ball();
	~Ball();

	//functions
	void update();
	void render(sf::RenderTarget* target);
};