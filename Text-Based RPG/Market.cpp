#include "Market.h"

Market::Market() {
	this->buy = "";
	this->sell = "";

	weapon[0] = new Dagger;
	weapon[1] = new Bone_Sword;
	armor[0] = new Copper_Armor;
	armor[1] = new Iron_Armor;
}

Market::~Market() {
	//delete[]weapon;
	//delete[]armor;
}

void Market::marketMenu(Character& user, Inventory& inven) {
	bool market = true;
	int chc;

	while (market)
	{
		system("cls");
		cout << "!============[Welcome to the Market]============!" << "\n";
		cout << "1. Buy Item" << "\n";
		cout << "2. Sell Item" << "\n";
		cout << "0. Exit Market" << "\n";
		cout << "--> "; cin >> chc;

		while (chc < 0 || chc > 2 || cin.fail())
		{
			system("cls");
			cin.clear();
			cin.ignore(100, '\n');
			cout << "!============[Welcome to the Market]============!" << "\n";
			cout << "1. Buy Item" << "\n";
			cout << "2. Sell Item" << "\n";
			cout << "0. Exit Market" << "\n";
			cout << "--> "; cin >> chc;
		}

		cin.ignore();

		if (chc == 1) { // buy
			buyItem(user, inven);
		}
		else if (chc == 2) { // sell
			sellItem(user, inven);
		}
		else if (chc == 0) {
			market = false;
		}
	}
}

void Market::buyItem(Character& user, Inventory& inven) {
	// Buy variable
	int gold;
	bool buyAct = true;

	while (buyAct)
	{
		system("cls");
		printDataItemMarket();
		cout << "-----------------------------------------------------------------" << "\n";
		cout << "Your Gold : " << user.getGold() << "\n";
		cout << "What Item do you want to buy? " << "\n";
		cout << "Type name of item or 'exit' to exit from Market." << "\n";
		cout << "> "; getline(cin, this->buy);

		if (this->buy == weapon[0]->getName()) {
			if (user.getGold() > weapon[0]->getPrice()) {
				gold = weapon[0]->getPrice();
				user.decreaseGold(gold);
				inven.addItemIventory(weapon[0]);
				cout << "Thank you for buying our items." << "\n";
			}
			else cout << "Not enough Gold to buy that item." << "\n";
		}
		else if (this->buy == weapon[1]->getName()) {
			if (user.getGold() > weapon[0]->getPrice()) {
				gold = weapon[1]->getPrice();
				user.decreaseGold(gold);
				inven.addItemIventory(weapon[1]);
				cout << "Thank you for buying our items." << "\n";
			}
			else cout << "Not enough Gold to buy that item." << "\n";
		}
		else if (this->buy == armor[0]->getName()) {
			if (user.getGold() > armor[0]->getPrice()) {
				gold = armor[0]->getPrice();
				user.decreaseGold(gold);
				inven.addItemIventory(armor[0]);
				cout << "Thank you for buying our items." << "\n";
			}
			else cout << "Not enough Gold to buy that item." << "\n";
		}
		else if (this->buy == armor[1]->getName()) {
			if (user.getGold() > armor[1]->getPrice()) {
				gold = armor[1]->getPrice();
				user.decreaseGold(gold);
				inven.addItemIventory(armor[1]);
				cout << "Thank you for buying our items." << "\n";
			}
			else cout << "Not enough Gold to buy that item." << "\n";
		}
		else if (this->buy == "exit") {
			buyAct = false;
		}
		else {
			cout << "No item with that name." << "\n";
		}
		cout << "-----------------------------------------------------------------" << "\n";
		system("pause>nul | echo Press any key to continue...");
	}
}

void Market::sellItem(Character& user, Inventory& inven) {
	if (inven.getItemInventory() > 0) {
		// Sell Variable
		bool sellAct = true;

		while (sellAct)
		{
			system("cls");
			int gold;
			int tmp;

			Inventory* temp;
			temp = new Inventory[inven.getItemInventory() - 1];

			inven.printInventory();
			cout << "-----------------------------------------------------------------" << "\n";
			cout << "What items do you want to sell? " << "\n";
			cout << "Type name of item or 'exit' to exit from Market." << "\n";
			cout << "> "; getline(cin, this->sell);

			for (int i = 0; i < inven.getItemInventory(); i++) {
				if (this->sell == "exit") {
					sellAct = false;
				}
				else if (this->sell != inven.getItems(i)->getName()) {
					cout << "No item with that name." << "\n";
					cout << "-----------------------------------------------------------------" << "\n";
					system("pause>nul | echo Press any key to continue...");
				}
				else {
					for (int i = 0; i < inven.getItemInventory(); i++) {
						if (this->sell == inven.getItems(i)->getName()) {
							tmp = i;
						}
					}
					gold = inven.getItems(i)->getPrice();
					user.addGold(gold);
					inven.resizeInventory(tmp);
					sellAct = false;
				}
			}
		}
	}
	else {
		cout << "Your inventory is empty." << endl;
	}
	cout << "-----------------------------------------------------------------" << "\n";
	system("pause>nul | echo Press any key to continue...");
}

void Market::printDataItemMarket() {
	cout << "!==================[List Market Items]==================!" << "\n";
	cout << "--------[Weapon]--------" << "\n";
	for (int i = 0; i < 2; i++) {
		cout << "[" << i + 1 << "]" << "\n";
		weapon[i]->displayItem();
	}
	cout << "--------[Armor]---------" << "\n";
	for (size_t i = 0; i < 2; i++) {
		cout << "[" << i + 1 << "]" << "\n";
		armor[i]->displayItem();
	}
}