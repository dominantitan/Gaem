#include "Game.h"

void Game::initFont()
{
	if (!this->font.loadFromFile(RESOURCES_PATH"MedodicaRegular.otf"))
	{
		std::cerr << "ERROR::GAME::INITFONT::Could not load font!" << std::endl;
	}
}

void Game::initText()
{
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(32);
	this->guiText.setString("Points: 0");
}

void Game::initVariables()
{

	this->endGame = false;
	this->spawnTimerMax = 10.f; // Time in seconds to spawn a new ball
	this->spawnTimer = this->spawnTimerMax;
	this->maxBalls = 10; // Maximum number of balls allowed in the game
	this->point = 0;
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
	this->initFont();
	this->initText();
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

void Game::spawnBall()
{
	if (this->spawnTimer < this->spawnTimerMax)
	{
		this->spawnTimer += 1.f;
	}
	else
	{
		if (this->balls.size() < this->maxBalls)
		{
			this->balls.push_back(Ball(this->window)); // Add a new ball to the vector
			this->spawnTimer = 0.f; // Reset the spawn timer
		}
	}
}

void Game::updateCollision()
{
	for (size_t i = 0;i < this->balls.size();i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->balls[i].getShape().getGlobalBounds()))
		{
			this->balls.erase(this->balls.begin() + i); // Remove the ball if it collides with the player
		}
	}

}

void Game::updateGui()
{
	std::stringstream ss;
	ss << "Points: " << this->point; // Update the GUI text with the current points
	this->guiText.setString(ss.str()); // Set the updated string to the GUI text
}

void Game::update(float deltaTime)
{

	this->pollEvents();

	this->spawnBall(); // Check if we can spawn a new ball

	this->player.update(this->window,deltaTime); // Update player logic

	updateCollision(); // Check for collisions with balls

	this->updateGui(); // Update the GUI text

}


void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText); // Draw the GUI text
}

void Game::render()
{
	this->window->clear(sf::Color::Black);

	// Render game objects here
	this->player.render(this->window); // Assuming player is a member variable of type Player

	for (auto& i : this->balls)
	{
		i.render(this->window); // Render each ball in the vector
	}

	this->renderGui(this->window); // Render the GUI text

	this->window->display();

}
