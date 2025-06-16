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
	void initShape(const sf::RenderTarget* target);


public:
	Ball(const sf::RenderTarget* target);
	~Ball();

	//functions
	const sf::CircleShape& getShape() const;
	void update();
	void render(sf::RenderTarget* target);
};