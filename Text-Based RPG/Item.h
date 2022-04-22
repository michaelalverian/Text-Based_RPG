#pragma once

#include <iostream>
#include <string>

using namespace std;

class Item
{
protected:
	string name;
	string type;
	int price;
	int damage;
	int armor;

	bool equip;
public:
	Item(string name, string type, int price);
	~Item();

	//set
	void setName(string name) { this->name = name; }
	void setType(string type) { this->type = type; }
	void setPrice(int price) { this->price = price; }

	//get
	string getName() { return this->name; }
	string getType() { return this->type; }
	int getPrice() { return this->price; }
	int getDamage() { return this->damage; }
	int getArmor() { return this->armor; }

	bool isEquip() { return this->equip; }
	void setEquip(bool equip) { this->equip = equip; }

	virtual void displayItem();
};

// Weapon
class Dagger : public Item {
public:
	Dagger();
	Dagger(string name, int damage, int price);
	~Dagger();

	//set
	void setName(string name) { this->name = name; }
	void setType(string type) { this->type = type; }
	void setDamage(int damage) { this->damage = damage; }
	void setPrice(int price) { this->price = price; }

	//get
	string getName() { return this->name; }
	string getType() { return this->type; }
	int getDamage() { return this->damage; }
	int getPrice() { return this->price; }

	void displayItem();
};

class Bone_Sword : public Item {
public:
	Bone_Sword();
	Bone_Sword(string name, int damage, int price);
	~Bone_Sword();

	//set
	void setName(string name) { this->name = name; }
	void setType(string type) { this->type = type; }
	void setDamage(int damage) { this->damage = damage; }
	void setPrice(int price) { this->price = price; }

	//get
	string getName() { return this->name; }
	string getType() { return this->type; }
	int getDamage() { return this->damage; }
	int getPrice() { return this->price; }

	void displayItem();
};

// Armor
class Copper_Armor : public Item {
public:
	Copper_Armor();
	Copper_Armor(string name, int armor, int price);
	~Copper_Armor();

	//set
	void setName(string name) { this->name = name; }
	void setType(string type) { this->type = type; }
	void setArmor(int armor) { this->armor = armor; }
	void setPrice(int price) { this->price = price; }

	//get
	string getName() { return this->name; }
	string getType() { return this->type; }
	int getArmor() { return this->armor; }
	int getPrice() { return this->price; }

	void displayItem();
};

class Iron_Armor : public Item {
public:
	Iron_Armor();
	Iron_Armor(string name, int armor, int price);
	~Iron_Armor();

	//set
	void setName(string name) { this->name = name; }
	void setType(string type) { this->type = type; }
	void setArmor(int armor) { this->armor = armor; }
	void setPrice(int price) { this->price = price; }

	//get
	string getName() { return this->name; }
	string getType() { return this->type; }
	int getArmor() { return this->armor; }
	int getPrice() { return this->price; }

	void displayItem();
};