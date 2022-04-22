#include "Game.h"

Game::Game() {
	this->playingRPG = true;
	this->choice = 0;
}

Game::~Game() {

}

void Game::mainMenu() {
	system("cls");

	cout << "!==========[Welcome To My RPG Game!]==========!" << "\n";
	cout << "[] 1. Start" << "\n";
	cout << "[] 2. Credits" << "\n";
	cout << "[] 3. Exit" << "\n";
	cout << "-> "; cin >> this->choice;

	while (this->choice > 3 || this->choice < 1 || cin.fail())
	{
		system("cls");
		cin.clear();
		cin.ignore(100, '\n');
		cout << "!==========[Welcome To My RPG Game!]==========!" << "\n";
		cout << "[] 1. Start" << "\n";
		cout << "[] 2. Credits" << "\n";
		cout << "[] 3. Exit" << "\n";
		cout << "-> "; cin >> this->choice;
	}

	if (this->choice == 1) {
		system("cls");
		start();
		//story();
		menuGame();
	}
	else if (this->choice == 2) {
		system("cls");
		credits();
		system("pause>nul");
	}
	else if (this->choice == 3) {
		this->playingRPG = false;
	}
}

void Game::start() {
	inputUser();
}

void Game::credits() {
	cout << "My RPG Game" << "\n";
	cout << "Written By" << "\n";
	cout << "Kevin Montoya      | C14190133" << "\n";
	cout << "Jovin              | C14190144" << "\n";
	cout << "Michael Alverian M | C14190149" << "\n";
	cout << "Software : Visual Studio 2019" << "\n";
	cout << "Programmed in C++" << "\n";
	cout << "June 2020" << "\n";
}

void Game::inputUser() {
	cin.ignore();

	string name;
	cout << "Enter Character Name: "; getline(cin, name);
	user.dataUser(name);
}

void Game::story() {
	// bagian pertama
	system("cls");
	cout << "Ahh..." << "\n";
	Sleep(2000);
	cout << "Where am i?" << "\n";
	Sleep(5000);
	for (int i = 0; i < 3; i++)
	{
		cout << ". ";
		Sleep(500);
	}
	cout << "\n";
	cout << "Ah, I remember. I just got hit by a train" << "\n";
	system("pause>nul | echo Press any key to continue...");

	// bagian kedua
	system("cls");
	cout << "Let's go " << this->user.getName() << "!" << "\n";
	system("pause>nul | echo Press any key to continue...");
}

void Game::menuGame() {
	bool playingGame = true;
	int chc;

	while (playingGame)
	{
		system("cls");
		cout << "!========[Main Menu]========!" << "\n";
		cout << "1. Adventure" << "\n";
		cout << "2. User Stats" << "\n";
		cout << "3. Inventory" << "\n";
		cout << "4. Market" << "\n";
		cout << "0. Back" << "\n";
		cout << "--> "; cin >> chc;

		while (chc > 4 || chc < 0 || cin.fail())
		{
			system("cls");
			cin.clear();
			cin.ignore(100, '\n');
			cout << "!========[Main Menu]========!" << "\n";
			cout << "1. Adventure" << "\n";
			cout << "2. User Stats" << "\n";
			cout << "3. Inventory" << "\n";
			cout << "4. Market" << "\n";
			cout << "0. Back" << "\n";
			cout << "--> "; cin >> chc;
		}

		if (chc == 1) {
			adventure();
		}
		else if (chc == 2) {
			system("cls");
			user.printDataUser();
			cout << "\n";
			user.printAttributes();
			if (user.getStatPoints() > 0) {
				cin.ignore();
				string choice;
				cout << "\n";
				cout << "Stat Points Available." << "\n";
				cout << "Do you want to add attribute points? (Yes/No)" << "\n";
				cout << "> "; getline(cin, choice);

				while (choice != "Yes" && choice != "No") {
					system("cls");
					user.printDataUser();
					cout << "\n";
					user.printAttributes();
					cout << "\n";
					cout << "Stat Points Available." << "\n";
					cout << "Do you want to add attribute points? (Yes/No)" << "\n";
					cout << "> "; getline(cin, choice);
				}

				if (choice == "Yes") {
					user.addAttributes();
				}
				else if (choice == "No") {
					system("cls");
					user.printDataUser();
					cout << "\n";
					user.printAttributes();
				}
			}
			cout << "-----------------------------------------------------------------" << "\n";
			system("pause>nul | echo Press any key to continue...");
		}
		else if (chc == 3) {
			system("cls");
			int index;
			string choice;
			inventory();
			cout << "\n";
			if (inven.getItemInventory() > 0)
			{
				cout << "Want to use an item, take it off or just check your inventory? (Use/Off/Check)" << "\n";
				cout << "> "; getline(cin, choice);

				while (choice != "Use" && choice != "Off" && choice != "Check") {
					system("cls");
					inventory();
					cout << "\n";
					cout << "Want to use an item, take it off or just check your inventory? (Use/Off/Check)" << "\n";
					cout << "> "; getline(cin, choice);
				}

				if (choice == "Use") {
					bool indexPlay = true;
					while (indexPlay)
					{
						cout << "\n";
						cout << "What items do you want to use? (Item number)" << "\n";
						cout << "> "; cin >> index;

						if (inven.getItemInventory() >= index) {
							user.equipItem(inven, index);
							indexPlay = false;
						}
						else {
							cout << "Sorry, item not found." << "\n";
						}
					}
				}
				else if (choice == "Off") {
					bool indexPlay = true;
					while (indexPlay)
					{
						cout << "\n";
						cout << "what items do you want to detach? (Item number)" << "\n";
						cout << "> "; cin >> index;

						if (inven.getItemInventory() >= index) {
							user.offItem(inven, index);
							indexPlay = false;
						}
						else {
							cout << "Sorry, item not found." << "\n";
						}
					}
				}
				else if (choice == "Check") {
					system("cls");
					inventory();
				}
			}
			cout << "-----------------------------------------------------------------" << "\n";
			system("pause>nul | echo Press any key to continue...");
		}
		else if (chc == 4) {
			market();
			cout << "-----------------------------------------------------------------" << "\n";
			system("pause>nul | echo Press any key to continue...");
		}
		else if (chc == 0) {
			playingGame = false;
		}
	}
}

void Game::adventure() {
	travel.traveling(user, enemy);
}

void Game::inventory() {
	inven.printInventory();
}

void Game::market() {
	marketPlace.marketMenu(user, inven);
}