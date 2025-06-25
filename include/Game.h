#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

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
	int maxBalls;

	float spawnTimer;
	float spawnTimerMax;

	int point;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;

private:
	void initFont();
	void initText();
	void initVariables();
	void initWindow();

public:
	//Constructors and Destructors
	Game();
	~Game();

	//Accessors
	const bool& getEndGame() const;

	//Modifier

	//Functions
	bool running() const;
	void pollEvents();

	const int randBallType() const;
	void updatePlayer(float deltaTime);
	void spawnBall();
	void updateCollision();

	void updateGui();
	void update(float deltaTime);

	void renderGui(sf::RenderTarget* target);
	void render();
};