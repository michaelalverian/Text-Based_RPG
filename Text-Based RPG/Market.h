#pragma once

#include "Character.h"
#include "Item.h"
#include "Inventory.h"

class Market {
private:
	Item* weapon[5];
	Item* armor[5];

	Item* item;

	string buy;
	string sell;
public:
	Market();
	~Market();

	void marketMenu(Character& user, Inventory& inven);

	void buyItem(Character& user, Inventory& inven);
	void sellItem(Character& user, Inventory& inven);
	void printDataItemMarket();

	//get
};