#include "Game.h"

int main() {

	srand(time(NULL));

	Game game;

	while (game.getPlay())
	{
		game.mainMenu();
	}

	return 0;
}