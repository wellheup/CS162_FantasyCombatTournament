/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/29/19
** Description: Implements Medusa class derived from Character
*********************************************************************/
#include <iostream>
#include <string>
#include "enums.hpp"
#include "menuShell.hpp" 
#include "character.hpp"
#include "medusa.hpp"
#include "die.hpp"

Medusa::Medusa() {
	thisChar = MEDUSA;
	armor = 3;
	startingStrength = 8;
	strength = startingStrength;
	numAtkDie = 2;
	numDefDie = 1;
	atkDie = new Die(6);
	defDie = new Die(6);
	describeChar = "Medusa: Scrawny lady with snakes for hair which helps her during combat. Just don't look at her!";
	describeRegAbilities = "Attack 2d6, Defense 1d6, Armor 3, Strength 8";
	describeSpecialAbilities = "Glare: If a Medusa rolls a 12 when attacking then the target\n--"
		" instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter on his first life,\n--"
		" then Harry Potter comes back to life.";
	typeCharStr = "Medusa";
}

Medusa::~Medusa() {

}

/*********************************************************************
** Description: attack() rolls and returns the character's attack dice
** also implements the Medusa's special abilites
*********************************************************************/
int Medusa::attack() {
	int roll = 0;
	for (int i = 0; i < numAtkDie; i++) {
		roll += atkDie->roll();
	}
	if (roll == 12) {
		//turned off for tournament*****
		//std::cout << "**The Medusa glares at her opponent turning them to stone!" << std::endl;
		return 100;
	}
	else {
		return roll;
	}
}

/*********************************************************************
** Description: defend() takes an integer attack value and applies
** it to the defensive capabilities of the character
*********************************************************************/
std::string Medusa::defend(int attack) {
	int defendRoll = 0;
	for (int i = 0; i < numDefDie; i++) {
		defendRoll += defDie->roll();
	}
	int totalDefense = defendRoll + this->getArmor();
	int damage = attack - totalDefense;
	if (damage < 0) {
		damage = 0;
	}
	std::string result = this->nameStr + ", the " + this->typeCharStr + " has an armor of " + std::to_string(this->getArmor()) + " and had "
		+ std::to_string(this->getStrength()) + " strength remaining." + "\nThey defended with a total roll of "
		+ std::to_string(defendRoll) + " and took " + std::to_string(damage) + " damage.";

	this->setStrength(this->getStrength() - damage);

	return result;
}