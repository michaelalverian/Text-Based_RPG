#pragma once

#include <iostream>
#include <string>

using namespace std;

// Base Class
class Enemy
{
protected:
	string type;

	int goldDrop;
	int expDrop;

	int health;
	int armor;
	int damage;
public:
	Enemy();
	Enemy(string type, int health, int armor, int damage);
	~Enemy();

	void setType(string type) { this->type = type; }
	void setHealth(int health) { this->health = health; }
	void setArmor(int armor) { this->armor = armor; }
	void setDamage(int damage) { this->damage = damage; }

	string getType() { return this->type; }
	int getHealth() { return this->health; }
	int getArmor() { return this->armor; }
	int getDamage() { return this->damage; }
	int getGoldDrop() { return this->goldDrop; }
	int getExpDrop() { return this->expDrop; }

	virtual void takeDamage(int damage);
	virtual void setFullHealth() { this->health = 0; }

	virtual void printDataEnemy();
};

// Child Class

// Goblin Class
class Goblin : public Enemy
{
public:
	Goblin();
	~Goblin();

	void takeDamage(int damage);
	void setFullHealth() { this->health = 20; }

	void printDataEnemy();
};

// Orc Class
class Orc : public Enemy {
public:
	Orc();
	~Orc();

	void takeDamage(int damage);
	void setFullHealth() { this->health = 37; }

	void printDataEnemy();
};

// Minotaur Class
class Minotaur : public Enemy {
public:
	Minotaur();
	~Minotaur();

	void takeDamage(int damage);
	void setFullHealth() { this->health = 58; }

	void printDataEnemy();
};