#include "Inventory.h"

Inventory::Inventory() {
	this->itemInventory = 0;
}

Inventory::~Inventory() {

}

void Inventory::resizeInventory(int idx) {
	this->itemInventory--;
	for (int i = idx; i < this->itemInventory; i++) {
		items[i] = items[i + 1];
	}
}

void Inventory::addItemIventory(Item* item) {
	if (this->itemInventory > 9)
	{
		cout << "Inventory full!" << "\n";
	}
	else {
		items[this->itemInventory] = item;
		this->itemInventory++;
	}
}

void Inventory::printInventory() {
	if (this->itemInventory == 0) {
		cout << "No item in Inventory." << "\n";
	}
	else {
		cout << "!===============[List of Items in Inventory]===============!" << "\n";
		for (int i = 0; i < this->itemInventory; i++) {
			cout << "[" << i + 1 << "]" << "\n";
			items[i]->displayItem();
		}
	}
}