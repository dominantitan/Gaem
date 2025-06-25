#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum ballType {
	DEFAULT = 0,
	DAMAGING = 1,
	HEALING = 2,
	SPEED = 3,
	NOOFTYPES = 4
};;


class Ball
{
private:
	sf::CircleShape circle;
	int type;
	

private:
	void initShape(const sf::RenderTarget* target);


public:
	Ball(const sf::RenderTarget* target,int type);
	~Ball();

	//getters
	const sf::CircleShape& getShape() const;
	const int& getType() const;

	//functions
	void update();
	void render(sf::RenderTarget* target);
};