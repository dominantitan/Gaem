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
	int healthMax;
	int health;
	float speed;

private:
	void initVariables();
	void initShape();


public:
	Player(float x = 0.f,float y = 0.f);
	~Player();

	const sf::RectangleShape& getShape() const;

	void updateInput(float deltaTime);
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target,float deltaTime);
	void render(sf::RenderTarget* target);

	
};