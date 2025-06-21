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

	//Accessors
	const sf::RectangleShape& getShape() const;
	const int& getHealth() const;
	const int& getHealthMax() const;
	const float& getSpeed() const;

	//functions
	void takeDamage(const int damage);
	void gainHealth(const int health);
	void gainSpeed(const float speed);
	void updateInput(float deltaTime);
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target,float deltaTime);
	void render(sf::RenderTarget* target);

	
};