#include "Enemy.h"

// Base Class
Enemy::Enemy() {
	this->type = "";

	this->goldDrop = 0;
	this->expDrop = 0;

	this->health = 0;
	this->armor = 0;
	this->damage = 0;
}

Enemy::Enemy(string type, int health, int armor, int damage) {
	this->type = type;

	this->goldDrop = 0;
	this->expDrop = 0;

	this->health = health;
	this->armor = armor;
	this->damage = damage;
}

Enemy::~Enemy() {


}

void Enemy::printDataEnemy() {
	cout << "-------------------------" << "\n";
	cout << "| Enemy  : " << this->type << "\n";
	cout << "| Health : " << this->health << "\n";
	cout << "| Armor  : " << this->armor << "\n";
	cout << "| Damage : " << this->damage << "\n";
}

void  Enemy::takeDamage(int damage) {
	this->health -= damage;
	if (this->health < 0) {
		this->health = 0;
	}
}

// Child Class

// Goblin Class
Goblin::Goblin() {
	this->type = "Goblin";

	// rand()%(max-min + 1) + min;
	this->goldDrop = rand() % (20 - 10 + 1) + 10;
	this->expDrop = rand() % (17 - 10 + 1) + 10;

	this->health = 20;
	this->armor = 0;
	this->damage = 7;
}

Goblin::~Goblin() {

}

void  Goblin::takeDamage(int damage) {
	this->health -= damage;
	if (this->health < 0) {
		this->health = 0;
	}
}

void Goblin::printDataEnemy() {
	Enemy::printDataEnemy();
}

// Orc Class
Orc::Orc() {
	this->type = "Orc";

	// rand()%(max-min + 1) + min;
	this->goldDrop = rand() % (45 - 35 + 1) + 35;
	this->expDrop = rand() % (30 - 20 + 1) + 20;

	this->health = 37;
	this->armor = 2;
	this->damage = 8;
}

Orc::~Orc() {

}

void  Orc::takeDamage(int damage) {
	this->health -= damage;
	if (this->health < 0) {
		this->health = 0;
	}
}

void Orc::printDataEnemy() {
	Enemy::printDataEnemy();
}

// Minotaur Class
Minotaur::Minotaur() {
	this->type = "Minotaur";

	// rand()%(max-min + 1) + min;
	this->goldDrop = rand() % (50 - 43 + 1) + 43;
	this->expDrop = rand() % (45 - 37 + 1) + 37;

	this->health = 58;
	this->armor = 10;
	this->damage = 17;
}

Minotaur::~Minotaur() {

}

void  Minotaur::takeDamage(int damage) {
	this->health -= damage;
	if (this->health < 0) {
		this->health = 0;
	}
}

void Minotaur::printDataEnemy() {
	Enemy::printDataEnemy();
}