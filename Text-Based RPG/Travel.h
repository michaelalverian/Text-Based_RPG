#pragma once

#include "Enemy.h"
#include "Character.h"
#include <stdlib.h>
#include <Windows.h>
#include <ctime>
#include <vector>

using namespace std;

class Travel
{
private:
	string action;

	//Enemy* x;

	Enemy* enemies[5];

public:
	Travel();
	~Travel();

	void traveling(Character& user, Enemy& enemies);
	void walking(Character& user);
	void resting(Character& user);

	void battle(Character& user, Enemy& enemies);

	//get
};

