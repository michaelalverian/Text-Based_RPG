#pragma once

#include "Item.h"

class Inventory {
private:
	Item* items[10];
	int itemInventory;
public:
	Inventory();
	~Inventory();

	void addItemIventory(Item* item);
	void resizeInventory(int idx);
	void printInventory();
	
	void setItemInventory(int itemInventory) { this->itemInventory = itemInventory; }
	void setItems(Item* items, int i) { this->items[i] = items; }

	int getItemInventory() { return this->itemInventory; }
	Item* getItems(int i) { return items[i]; }
};