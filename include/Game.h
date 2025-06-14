#pragma once

#include <iostream>
#include <ctime>

#include "Player.h"

class Game {
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event event;

	Player player;

private:
	void initVariables();
	void initWindow();

public:
	//Constructors and Destructors
	Game();
	~Game();

	//Accessors

	//Modifier

	//Functions
	bool running() const;
	void pollEvents();

	void update(float deltaTime);
	void render();
};