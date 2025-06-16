#include "Ball.h"


void Ball::initShape(const sf::RenderTarget* target)
{
	this->circle.setRadius(static_cast<float>(rand() % 20 + 10)); // Random radius between 10 and 30
	sf::Color randomColor(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1); // Random color
	this->circle.setFillColor(randomColor);
	this->circle.setPosition(
		static_cast<float>(rand() % (target->getSize().x - static_cast<unsigned int>(this->circle.getRadius() * 2))),
		static_cast<float>(rand() % (target->getSize().y - static_cast<unsigned int>(this->circle.getRadius() * 2)))
	);

}

Ball::Ball(const sf::RenderTarget* target) {
	this->initShape(target);
}

Ball::~Ball() {

}

const sf::CircleShape& Ball::getShape() const
{
	return {this->circle};
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
