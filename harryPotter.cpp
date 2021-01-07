/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/29/19
** Description: Implements HarryPotter class derived from Character
*********************************************************************/
#include <iostream>
#include <string>
#include "enums.hpp"
#include "menuShell.hpp" 
#include "character.hpp"
#include "harryPotter.hpp"
#include "die.hpp"

HarryPotter::HarryPotter() {
	thisChar = HARRY_POTTER;
	armor = 0;
	startingStrength = 10;
	strength = startingStrength;
	numAtkDie = 2;
	numDefDie = 2;
	atkDie = new Die(6);
	defDie = new Die(6);
	describeChar = "Harry Potter: Harry Potter is a wizard.";
	describeRegAbilities = "Attack 2d6, Defense 2d6, Armor 0, Strength 10";
	describeSpecialAbilities = "Hogwarts: If Harry Potter's strength reaches 0 or below,\n--"
		" he immediately recovers and his total strength becomes 20.\n--"
		" If he were to die again, then he's dead for real.";
	typeCharStr = "Harry Potter";
	hasHogwartsed = false;
}

HarryPotter::~HarryPotter() {
	
}

/*********************************************************************
** Description: attack() rolls and returns the character's attack dice
*********************************************************************/
int HarryPotter::attack() {
	int roll = 0;
	for (int i = 0; i < numAtkDie; i++) {
		roll += atkDie->roll();
	}
	return roll;
}

/*********************************************************************
** Description: defend() takes an integer attack value and applies
** it to the defensive capabilities of the character
** also adjusts Harry Potter's defense based on his special ability
*********************************************************************/
std::string HarryPotter::defend(int attack) {
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
		+ std::to_string(this->getStrength()) + " remaining." + "\nThey defended with a total roll of "
		+ std::to_string(defendRoll) + " and took " + std::to_string(damage) + " damage.";

	this->setStrength(this->getStrength() - damage);

	if (this->getStrength() <= 0 && hasHogwartsed== false) {
		hogwarts();
		result = this->nameStr + ", the " + this->typeCharStr + " has an armor of " + std::to_string(this->getArmor()) + " and had "
			+ std::to_string(this->getStrength()) + " strength remaining." + "\nThey defended with a total roll of "
			+ std::to_string(defendRoll) + " and took " + std::to_string(damage) + " damage. \n"
			"**Using Hogwarts, Harry Potter survived the devastating attack!";
	}

	return result;
}

/*********************************************************************
** Description: hogwarts() sets Harry Potter's strength to 20 and 
** the hasHogWartsed bool to true so that the ability won't be used again
*********************************************************************/
void HarryPotter::hogwarts() {
	this->setStrength(20);
	hasHogwartsed = true;
}
