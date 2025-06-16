#pragma once

#include <iostream>
#include <ctime>
#include <vector>

#include "Player.h"
#include "Ball.h"

class Game {
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event event;

	Player player;
	std::vector<Ball> balls; // Vector to hold multiple balls
	float spawnTimer;
	float spawnTimerMax;
	int maxBalls;

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

	void spawnBall();
	void updateCollision();
	void update(float deltaTime);
	void render();
};