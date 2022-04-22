#pragma once

#include "Travel.h"
#include "Market.h"

class Game
{
private:
	bool playingRPG;
	int choice;

	Character user;
	Enemy enemy;
	Travel travel;
	Market marketPlace;
	Inventory inven;

public:
	Game();
	~Game();

	// Selamat datang
	void mainMenu();
	void start();
	void credits();

	// Setelah pencet start
	void inputUser();
	void story();
	void menuGame();
	void adventure();
	void inventory();
	void market();

	// get
	bool getPlay() { return this->playingRPG; }

};