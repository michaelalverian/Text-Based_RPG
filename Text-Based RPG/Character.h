#pragma once

#include "Inventory.h"

class Character
{
private:
	string name;

	int level;
	int exp;
	int expNext;
	int gold;

	int strength;
	int vitality;
	int dexterity;
	int intelligence;

	int health;
	int healthMax;
	int armor;
	int damage;

	int statPoints;

public:
	Character();
	Character(string name, int level, int exp, int gold,
		int strength, int vitality, int dexterity, int intelligence,
		int health, int armor, int damage, int statPoints);
	~Character();

	void dataUser(const string name);
	void printDataUser();
	void printAttributes();

	void levelUp();
	void addAttributes();
	void updateStats();

	void equipItem(Inventory& item, int index);
	void offItem(Inventory& item, int index);

	void addHealth(int health);
	void takeDamage(int damage);

	void addGold(int gold) { this->gold += gold; };
	void decreaseGold(int gold) { this->gold -= gold; }
	void gainExp(int exp) { this->exp += exp; }

	// get
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getGold() const { return this->gold; }
	inline const int& getHealth() const { return this->health; }
	inline const int& getHealthMax() const { return this->healthMax; }
	inline const int& getDamage() const { return this->damage; }
	inline const int& getArmor() const { return this->armor; }
	inline const int& getStatPoints() const { return this->statPoints; }
	inline const bool isAlive() { return this->health > 0; }
};