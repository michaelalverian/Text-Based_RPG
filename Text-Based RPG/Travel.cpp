#include "Travel.h"

Travel::Travel() {
	this->action = "";

	this->enemies[0] = new Goblin;
	this->enemies[1] = new Minotaur;
	this->enemies[2] = new Orc;
}

Travel::~Travel() {
	//delete[] enemies;
}

void Travel::traveling(Character& user, Enemy& enemies) {
	bool travel = true;

	while (travel)
	{
		system("cls");
		user.printDataUser();
		enemies.printDataEnemy();
		cout << "==================================================================" << "\n";
		cout << "Type 'move' to move forward, 'rest' to recover or 'exit'." << "\n";
		cout << "> "; getline(cin, this->action);

		if (this->action == "move") {
			walking(user);
		}
		else if (this->action == "rest") {
			resting(user);
		}
		else if (this->action == "exit") {
			travel = false;
		}
	}
}

void Travel::walking(Character& user) {
	int i = rand() % 20;

	cout << "Now walking..." << "\n";
	Sleep(4000);

	if (i > 1 && i < 6) { // Goblin
		cout << "You met the " << enemies[0]->getType() << "\n";
		//x = new Goblin;
		cout << "-----------------------------------------------------------------" << "\n";
		system("pause>nul | echo Press any key to continue...");
		battle(user, *enemies[0]);
	}
	else if (i > 15 && i < 18) { // Minotaur
		cout << "You met the " << enemies[1]->getType() << "\n";
		//x = new Minotaur;
		cout << "-----------------------------------------------------------------" << "\n";
		system("pause>nul | echo Press any key to continue...");
		battle(user, *enemies[1]);
	}
	else if (i > 8 && i < 13) { // Orc
		cout << "You met the " << enemies[2]->getType() << "\n";
		cout << "-----------------------------------------------------------------" << "\n";
		system("pause>nul | echo Press any key to continue...");
		battle(user, *enemies[2]);
	}
	else {
		cout << user.getName() << " moved few steps forward and nothing happened." << "\n";
		cout << "-----------------------------------------------------------------" << "\n";
		system("pause>nul | echo Press any key to continue...");
	}

}

void Travel::resting(Character& user) {
	cout << "Now resting..." << "\n";
	Sleep(4000);

	// Add 5 health
	user.addHealth(5);

	cout << "While " << user.getName() << " was resting, health recovered." << "\n";
	cout << "-----------------------------------------------------------------" << "\n";
	system("pause>nul | echo Press any key to continue...");
}

void Travel::battle(Character& user, Enemy& enemies) {
	string choice;

	bool playerTurn = true;

	// End Conditions
	bool escape = false;
	bool playerDefeated = false;
	bool enemyDefeated = false;

	// Battle Variable
	bool block = false;
	int gold;
	int exp;
	int damage = 0;

	while (!escape && !playerDefeated && !enemyDefeated)
	{
		if (playerTurn && !playerDefeated)
		{
			system("cls");

			user.printDataUser();
			enemies.printDataEnemy();
			cout << "==================================================================" << "\n";
			cout << "Type:" << "\n";
			cout << "'attack' to attack the enemy." << "\n";
			cout << "'block' to block enemy attacks." << "\n";
			cout << "'escape' to flee from enemy." << "\n";
			cout << "> "; getline(cin, choice);
			
			while (choice != "attack" && choice != "block" && choice != "escape")
			{
				system("cls");
				user.printDataUser();
				enemies.printDataEnemy();
				cout << "==================================================================" << "\n";
				cout << "Type:" << "\n";
				cout << "'attack' to attack the enemy." << "\n";
				cout << "'block' to block enemy attacks." << "\n";
				cout << "'escape' to flee from enemy." << "\n";
				cout << "> "; getline(cin, choice);
			}

			if (choice == "attack") {
				cout << "Now attacking..." << "\n";
				Sleep(4000);

				damage = user.getDamage() - (enemies.getArmor() / user.getDamage());
				enemies.takeDamage(damage);
				cout << enemies.getType() << " health -" << damage << "\n";
				if (enemies.getHealth() <= 0) {
					gold = enemies.getGoldDrop();
					exp = enemies.getExpDrop();
					user.addGold(gold);
					user.gainExp(exp);
					cout << "You defeated the enemy!" << "\n";
					cout << "You got " << gold << " gold and " << exp << " exp!" << "\n";
					if (user.getExp() >= user.getExpNext()) { user.levelUp(); }
					enemyDefeated = true;
					enemies.setFullHealth();
				}
			}
			else if (choice == "block") {
				cout << "Now blocking..." << "\n";
				Sleep(4000);
				cout << "Good choice " << user.getName() << "." << "\n";
				block = true;
			}
			else {
				escape = true;
			}
			cout << "-----------------------------------------------------------------" << "\n";
			system("pause>nul | echo Press any key to continue...");
		
			// End Turn
			playerTurn = false;
		}
		else if (!playerTurn && !playerDefeated && !escape && !enemyDefeated) {
			system("cls");

			user.printDataUser();
			enemies.printDataEnemy();
			cout << "==================================================================" << "\n";
			cout << enemies.getType() << " attacking..." << "\n";
			Sleep(4000);

			if (!block) {
				damage = enemies.getDamage() - (user.getArmor() / enemies.getDamage());
				user.takeDamage(damage);
				cout << user.getName() << " health -" << damage << "\n";
			}
			else {
				block = false;
				cout << user.getName() << " successfully blocked enemy attacks." << "\n";
			}
			cout << "-----------------------------------------------------------------" << "\n";
			system("pause>nul | echo Press any key to continue...");

			// End Turn
			playerTurn = true;
		}

		// Conditions
		if (!user.isAlive()) {
			playerDefeated = true;
		}
	}	
}