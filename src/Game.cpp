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
	//GUI Text
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(32);
	this->guiText.setString("Points: 0");

	// End Game Text
	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(sf::Color::Red);
	this->endGameText.setCharacterSize(64);
	this->endGameText.setString("Game Over!\nPress Escape to Exit");
	this->endGameText.setPosition(
		this->videoMode.width / 2.f - this->endGameText.getGlobalBounds().width / 2.f,
		this->videoMode.height / 2.f - this->endGameText.getGlobalBounds().height / 2.f
	);
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

const bool& Game::getEndGame() const
{
	return {this->endGame};
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

const int Game::randBallType() const
{
	int type = ballType::DEFAULT;
	int randValue = rand() % 100 + 1;
	if (randValue <= 60) // 60% chance for DEFAULT
	{
		type = ballType::DEFAULT;
	}
	else if (randValue <= 75) // 15% chance for DAMAGING
	{
		type = ballType::DAMAGING;
	}
	else if (randValue <= 85) // 10% chance for HEALING
	{
		type = ballType::HEALING;
	}
	else // 15% chance for SPEED
	{
		type = ballType::SPEED;
	}
	return type;
}

void Game::updatePlayer(float deltaTime)
{
	this->player.update(this->window,deltaTime);

	if (this->player.getHealth() <= 0)
	{
		this->endGame = true; // End the game if player health is zero or below
		std::cout << "Game Over! Final Points: " << this->point << std::endl; // Print final points
		return;
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
			this->balls.push_back(Ball(this->window,this->randBallType())); // Add a new ball to the vector
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
			switch (this->balls[i].getType())
			{
			case ballType::DEFAULT:
				// Default ball, no special effect
				this->point += 10;// Increment points when the player collides with a ball
				break;
			case ballType::DAMAGING:
				this->player.takeDamage(10); // Player takes damage
				break;
			case ballType::HEALING:
				this->player.gainHealth(1); // Player gains health
				break;
			case ballType::SPEED:
				this->player.gainSpeed(50.f); // Player gains speed
				break;
			}
			
			this->balls.erase(this->balls.begin() + i); // Remove the ball if it collides with the player
		}
	}

}

void Game::updateGui()
{
	std::stringstream ss;
	ss << "Points: " << this->point << '\n'
			<< "Health: " << this->player.getHealth() << " / "<< this->player.getHealthMax() << '\n'
				<< "Speed: " << this->player.getSpeed(); // Update the GUI text with the current points
	this->guiText.setString(ss.str()); // Set the updated string to the GUI text
}

void Game::update(float deltaTime)
{

	this->pollEvents();

	if (this->endGame == false)
	{
		this->spawnBall(); // Check if we can spawn a new ball

		this->updatePlayer(deltaTime); // Update player state

		updateCollision(); // Check for collisions with balls

		this->updateGui(); // Update the GUI text

	}

	
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

	if (this->endGame == true)
	{
		this->window->draw(this->endGameText); // Draw end game text if the game is over
	}

	this->window->display();

}
