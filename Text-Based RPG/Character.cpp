#include "Character.h"

Character::Character() {
	this->name = "";

	this->level = 0;
	this->exp = 0;
	this->expNext = 0;

	this->gold = 0;

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->health = 0;
	this->healthMax = 0;
	this->armor = 0;
	this->damage = 0;

	this->statPoints = 0;
}

Character::Character(string name, int level, int exp, int gold,
	int strength, int vitality, int dexterity, int intelligence,
	int health, int armor, int damage, int statPoints)
{
	this->name = name;

	this->level = level;
	this->exp = exp;
	this->expNext = 0;

	this->gold = gold;

	this->strength = strength;
	this->vitality = vitality;
	this->dexterity = dexterity;
	this->intelligence = intelligence;

	this->health = health;
	this->healthMax = 0;
	this->armor = armor;
	this->damage = damage;

	this->statPoints = statPoints;

	updateStats();
}

Character::~Character() {


}

void Character::dataUser(const string name) {
	this->name = name;

	this->level = 1;
	this->exp = 0;

	this->gold = 0;

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->statPoints = 5;

	updateStats();
}

void Character::printDataUser() {
	cout << "| " << this->name << "\n";
	cout << "| Level  : " << this->level << "\n";
	cout << "| Exp    : " << this->exp << " / " << this->expNext << "\n";
	cout << "| Gold   : " << this->gold << "\n";
	cout << "| Health : " << this->health << " / " << this->healthMax << "\n";
	cout << "| Armor  : " << this->armor << "\n";
	cout << "| Damage : " << this->damage << "\n";
}

void Character::printAttributes() {
	cout << "= Attributes =" << "\n";
	cout << "| Strength     : " << this->strength << "\n";
	cout << "| Vitality     : " << this->vitality << "\n";
	cout << "| Dexterity    : " << this->dexterity << "\n";
	cout << "| Intelligence : " << this->intelligence << "\n";
	cout << "\n";
	cout << "[ Stat Point   : " << this->statPoints << " ]" << "\n";
}

void Character::addHealth(int health) {
	this->health += health;
	if (this->health > this->healthMax) {
		this->health = this->healthMax;
	}
}

void Character::levelUp() {
	this->exp -= this->expNext;
	this->level++;
	this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3)
		- 6 * pow(level, 2))
		+ 17 * level - 12)) + 100;

	this->statPoints++;

	updateStats();

	cout << "\n";
	cout << ">> Congratulations you are level up! <<" << "\n\n";
}

void Character::addAttributes() {
	bool addingAtt = true;
	string att;

	while (addingAtt)
	{
		system("cls");
		printAttributes();
		cout << "==================================================================" << "\n";
		cout << "Type:" << "\n";
		cout << "'add name_attributes' to add the desired attribute points or 'exit'." << "\n";
		cout << "> "; getline(cin, att);

		while (att != "add Strength" && att != "add Vitality" && att != "add Dexterity" && att != "add Intelligence" && att != "exit") {
			system("cls");
			printAttributes();
			cout << "==================================================================" << "\n";
			cout << "Type:" << "\n";
			cout << "'add name_attributes' to add the desired attribute points or 'exit'." << "\n";
			cout << "> "; getline(cin, att);
		}

		if (this->statPoints != 0 && att != "exit") {
			if (att == "add Strength") { this->strength++; this->statPoints--; }
			else if (att == "add Vitality") { this->vitality++; this->statPoints--; }
			else if (att == "add Dexterity") { this->dexterity++; this->statPoints--; }
			else if (att == "add Intelligence") { this->intelligence++; this->statPoints--; }
		}
		else if (this->statPoints == 0 && att != "exit") {
			cout << "Your stat points are all used up." << "\n";
			cout << "-----------------------------------------------------------------" << "\n";
			system("pause>nul | echo Press any key to continue...");
		}
		else if (att == "exit") {
			addingAtt = false;
		}
	}

	this->healthMax = (this->vitality * 5) + (this->strength) + (this->level * 5) + 95;
	this->damage = (this->strength) + (this->level / 2) + 5;
	this->armor = this->dexterity + (this->intelligence / 2);
	//updateStats();
}

void Character::updateStats() {
	this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3)
		- 6 * pow(level, 2))
		+ 17 * level - 12)) + 100;

	this->healthMax = (this->vitality * 5) + (this->strength) + (this->level * 5) + 95;
	this->damage = (this->strength) + (this->level / 2) + 5;
	this->armor = this->dexterity + (this->intelligence / 2);
	this->health = this->healthMax;
}

void Character::takeDamage(int damage) {
	this->health -= damage;
	if (this->health < 0) {
		this->health = 0;
	}
}

void Character::equipItem(Inventory& item, int index) {
	for (int i = 0; i < item.getItemInventory(); i++) {
		if (i == index - 1) {
			if (item.getItems(i)->getType() == "Weapon" && item.getItems(i)->isEquip() != true) {
				this->damage += item.getItems(i)->getDamage();
				item.getItems(i)->setEquip(true);
			}
			else if (item.getItems(i)->getType() == "Armor" && item.getItems(i)->isEquip() != true) {
				this->armor += item.getItems(i)->getArmor();
				item.getItems(i)->setEquip(true);
			}
			else {
				cout << "This item is currently in use." << "\n";
			}
		}
	}
}

void Character::offItem(Inventory& item, int index) {
	for (int i = 0; i < item.getItemInventory(); i++) {
		if (i == index - 1) {
			if (item.getItems(i)->getType() == "Weapon" && item.getItems(i)->isEquip() == true) {
				this->damage -= item.getItems(i)->getDamage();
				item.getItems(i)->setEquip(false);
			}
			else if (item.getItems(i)->getType() == "Armor" && item.getItems(i)->isEquip() == true) {
				this->armor -= item.getItems(i)->getArmor();
				item.getItems(i)->setEquip(false);
			}
			else {
				cout << "This item is not used." << "\n";
			}
		}
	}
}