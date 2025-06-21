#include "Ball.h"


void Ball::initShape(const sf::RenderTarget* target)
{
	this->circle.setRadius(static_cast<float>(rand() % 20 + 10)); // Random radius between 10 and 30
	sf::Color randomColor; // Random color
	switch (this->type)
	{
	case DEFAULT:
		randomColor = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
		break;
	case DAMAGING:
		this->circle.setOutlineColor(sf::Color::White);
		this->circle.setOutlineThickness(2.f); // Set outline for damaging ball
		randomColor = sf::Color::Red; // Red for damaging ball
		break;
	case HEALING:
		this->circle.setOutlineColor(sf::Color::White);
		this->circle.setOutlineThickness(2.f); // Set outline for damaging ball
		randomColor = sf::Color::Green; // Green for healing ball
		break;
	case SPEED:
		this->circle.setOutlineColor(sf::Color::White);
		this->circle.setOutlineThickness(2.f); // Set outline for damaging ball
		randomColor = sf::Color::Yellow; // Yellow for speed ball
		break;
	}
	this->circle.setFillColor(randomColor);
	this->circle.setPosition(
		static_cast<float>(rand() % (target->getSize().x - static_cast<unsigned int>(this->circle.getRadius() * 2))),
		static_cast<float>(rand() % (target->getSize().y - static_cast<unsigned int>(this->circle.getRadius() * 2)))
	);

}

Ball::Ball(const sf::RenderTarget* target,int type)
	: type(type)
{
	this->initShape(target);
}

Ball::~Ball() {

}

const sf::CircleShape& Ball::getShape() const
{
	return {this->circle};
}

const int& Ball::getType() const
{
	return {this->type};
}

void Ball::update()
{

}

void Ball::render(sf::RenderTarget* target)
{
	if (target)
	{
		target->draw(this->circle);
	}
}
