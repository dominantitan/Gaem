#include "Game.h"

int main()
{
	sf::Clock clock;
	//Initialize Random Seed
	srand(static_cast<unsigned>(time(0))); // Seed for random number generation

	//Initialize Game Object
	Game game;

	//Game loop

	while (game.running())
	{
		float deltaTime = clock.restart().asSeconds(); // Get the time elapsed since the last frame
		game.update(deltaTime); // Update the game state
		game.render(); // Render the game
	}


	//End of Application




    return 0;
}