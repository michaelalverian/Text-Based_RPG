#include "Item.h"

Item::Item(string name = "", string type = "", int price = 0) {
	this->name = name;
	this->type = type;
	this->price = price;

	this->equip = false;
}

Item::~Item() {
	
}

void Item::displayItem() {
	cout << "| Name   : " << this->name << "\n";
	cout << "| Type   : " << this->type << "\n";
	cout << "| Price  : " << this->price << " gold" << "\n";
}

// Weapon

// Dagger
Dagger::Dagger() {
	this->name = "Dagger";
	this->type = "Weapon";
	this->damage = 3;
	this->price = 150;
}

Dagger::Dagger(string name = "", int damage = 0, int price = 0) {
	this->name = name;
	this->type = "Weapon";
	this->damage = damage;
	this->price = price;
}

Dagger::~Dagger() {

}

void Dagger::displayItem() {
	Item::displayItem();
	cout << "| Damage : " << this->damage << "\n";
}

// Bone Sword
Bone_Sword::Bone_Sword() {
	this->name = "Bone Sword";
	this->type = "Weapon";
	this->damage = 5;
	this->price = 225;
}

Bone_Sword::Bone_Sword(string name = "", int damage = 0, int price = 0) {
	this->name = name;
	this->type = "Weapon";
	this->damage = damage;
	this->price = price;
}

Bone_Sword::~Bone_Sword() {

}

void Bone_Sword::displayItem() {
	Item::displayItem();
	cout << "| Damage : " << this->damage << "\n";
}

// Armor

// Copper Armor
Copper_Armor::Copper_Armor() {
	this->name = "Copper Armor";
	this->type = "Armor";
	this->armor = 4;
	this->price = 200;
}

Copper_Armor::Copper_Armor(string name = "", int armor = 0, int price = 0) {
	this->name = name;
	this->type = "Armor";
	this->armor = armor;
	this->price = price;
}

Copper_Armor::~Copper_Armor() {

}

void Copper_Armor::displayItem() {
	Item::displayItem();
	cout << "| Armor  : " << this->armor << "\n";
}

// Iron Armor
Iron_Armor::Iron_Armor() {
	this->name = "Iron Armor";
	this->type = "Armor";
	this->armor = 7;
	this->price = 375;
}

Iron_Armor::Iron_Armor(string name = "", int armor = 0, int price = 0) {
	this->name = name;
	this->type = "Armor";
	this->armor = armor;
	this->price = price;
}

Iron_Armor::~Iron_Armor() {

}

void Iron_Armor::displayItem() {
	Item::displayItem();
	cout << "| Armor  : " << this->armor << "\n";
}