#include "Player.h"

void Player::initVariables()
{
	this->speed = 250.f; // Set the speed of the player
	this->healthMax = 10; // Set the maximum health of the player
	this->health = this->healthMax; // Initialize health to maximum
}

void Player::initShape()
{
	this->rectangle.setSize(sf::Vector2f(50.f, 50.f));
	this->rectangle.setFillColor(sf::Color::Green);
	this->rectangle.setPosition(100.f, 100.f);
}

Player::Player(float x,float y)
{
	this->rectangle.setPosition(x, y); // Set initial position of the player rectangle

	this->initVariables();
	this->initShape();
}

Player::~Player()
{


}

const sf::RectangleShape& Player::getShape() const
{
	return {this->rectangle};
}

const int& Player::getHealth() const
{
	return {this->health};
}

const int& Player::getHealthMax() const
{
	return { this->healthMax};
}

const float& Player::getSpeed() const
{
	return {this->speed};
}

void Player::takeDamage(const int damage)
{
	if (this->health > 0)
		this->health -= damage; // Reduce health by damage amount

	if (this->health < 0) // Ensure health does not go below zero
		this->health = 0;
}

void Player::gainHealth(const int health)
{
	if (this->health < this->healthMax)
	{
		this->health += health; // Increase health by the specified amount
		if (this->health > this->healthMax) // Ensure health does not exceed maximum
			this->health = this->healthMax;
	}
}

void Player::gainSpeed(const float speed)
{
	this->speed += speed; // Increase player speed by the specified amount
	if (this->speed < 0.f) // Ensure speed does not go below zero
		this->speed = 0.f;
}

void Player::updateInput(float deltaTime)
{
	// Window Bound collision


	// Handle player movement based on input
	sf::Vector2f movement = sf::Vector2f(0.f, 0.f); // Initialize movement vector

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += 1.f;
	}

	if (movement.x != 0.f || movement.y != 0.f)
	{
		// Normalize the movement vector to maintain consistent speed
		float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
		if (length != 0.f)
		{
			movement /= length; // Normalize the vector
		}
	}

	this->rectangle.move(movement * this->speed * deltaTime); // Move the player rectangle
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	sf::FloatRect bounds = this->rectangle.getGlobalBounds();
	float newX = bounds.left;
	float newY = bounds.top;

	// Left and right boundaries
	if (bounds.left < 0.f)
		newX = 0.f;
	else if (bounds.left + bounds.width > target->getSize().x)
		newX = target->getSize().x - bounds.width;

	// Top and bottom boundaries
	if (bounds.top < 0.f)
		newY = 0.f;
	else if (bounds.top + bounds.height > target->getSize().y)
		newY = target->getSize().y - bounds.height;

	this->rectangle.setPosition(newX, newY);
}


void Player::update(const sf::RenderTarget* target,float deltaTime)
{
	// Update player logic here, e.g., movement, animations, etc.

	// Call the movement update function
	this->updateInput(deltaTime); 

	// Window Bound collision
	this->updateWindowBoundsCollision(target); // Check for collisions with window bounds
}



void Player::render(sf::RenderTarget* target)
{
	target->draw(this->rectangle); // Draw the player rectangle to the target
}
