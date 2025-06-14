#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
	sf::RectangleShape rectangle;
	// Player attributes
	float speed;

	void initVariables();
	void initShape();

public:
	Player(float x = 0.f,float y = 0.f);
	~Player();

	void updateInput(float deltaTime);
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target,float deltaTime);
	void render(sf::RenderTarget* target);
	
};