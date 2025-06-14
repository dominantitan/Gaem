#include "Game.h"

void Game::initVariables()
{

	this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "SFML Game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60); // Set the frame rate limit
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			this->window->close();
		}
		if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
	}
}

void Game::update(float deltaTime)
{

	this->pollEvents();


	this->player.update(this->window,deltaTime); // Update player logic

}

void Game::render()
{
	this->window->clear(sf::Color::Black);

	// Render game objects here
	this->player.render(this->window); // Assuming player is a member variable of type Player

	this->window->display();

}
