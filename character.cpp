/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/29/19
** Description: Implements Character class which serves as the base
**		for all character classes
*********************************************************************/
#include <string>
#include <iostream>
#include "menuShell.hpp" 
//#include "enums.hpp"
#include "character.hpp"

Character::Character(){
	armor = 0;
	strength = 0;
	numDefDie = 1;
	numAtkDie = 1;
	thisChar = NO_CHAR;
	describeChar = "No Description";
	describeRegAbilities = "No regular abilities";
	describeSpecialAbilities = "No special abilites";
	typeCharStr = "Character";
	nameStr = "Unnamed";
}

Character::~Character(){
	delete atkDie;
	atkDie = nullptr;
	delete defDie;
	defDie = nullptr; 
}

int Character::getArmor(){
	return this->armor;
}

void Character::setArmor(int armor){
	this->armor = armor;
}

int Character::getStrength(){
	return this->strength;
}

void Character::setStrength(int strength){
	this->strength = strength;
}

int Character::getNumAtkDie() {
	return this->numAtkDie;
}

void Character::setNumAtkDie(int numAtkDie) {
	this->numAtkDie = numAtkDie;
}

int Character::getNumDefDie() {
	return this->numDefDie;
}

void Character::setNumDefDie(int numDefDie) {
	this->numDefDie = numDefDie;
}


int Character::getTypeChar(){
	return this->thisChar;
}

std::string Character::getTypeCharStr() {
	return this->typeCharStr;
}

void Character::setTypeChar(){
}

/*********************************************************************
** Description: getDescribeChar() prints out character descriptions
** and abilities for the player to see
*********************************************************************/
std::string Character::getDescribeChar() {
	std::string temp = describeChar + "\n--" + describeRegAbilities + "\n--" + describeSpecialAbilities + "\n";
	return temp;
}

void Character::setNameStr(std::string nameIn) {
	this->nameStr = nameIn;
}

std::string Character::getNameStr() {
	return this->nameStr;
}

/*********************************************************************
** Description: heal() uses the character's startingStrength as the 
** basis for a die, rolls it and heals them for that many points up
** to their maximum strength
*********************************************************************/
void Character::heal() {
	if (this->strength < startingStrength) {//this makes sure Harry Potter doesn't lose any hogwarts strength
		Die healDie = Die(startingStrength);
		int healFor = healDie.roll();
		if (healFor >= (startingStrength - this->strength)) {
			this->strength = startingStrength;
			std::cout << nameStr << " will heal up to full strength." << std::endl;
		}
		else {
			this->strength += healFor;
			std::cout << nameStr << " will heal up to " << this->strength << " strength." << std::endl;
		}
	}
}
