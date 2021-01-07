/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/29/19
** Description: Implements Game class which will run the game and
** use the different character classes 
*********************************************************************/
#include <iostream>
#include <string>
#include "enums.hpp"
#include "menuShell.hpp" 
#include "die.hpp"
#include "character.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "harryPotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"
#include "TeamQueue.hpp"
#include "game.hpp"

/*********************************************************************
** Description: base constructor sets all of the starting values 
** for all of the variables in the class 
*********************************************************************/
Game::Game(){
	initValues();
}

/*********************************************************************
** Description: 1 parameter constructor sets all of the starting values
** for all of the variables in the class and turns on6 character 
** selection confirmation if the passed int != 0
*********************************************************************/
Game::Game(int useVerbose) {
	initValues();
	this->useVerbose = useVerbose;
}

//destructor
Game::~Game(){
	delete p1Queue;
	delete p2Queue;
	delete deathStack;
	delete rollOffDie;
}

/*********************************************************************
** Description: initValues() actually sets all of the variables used in game
*********************************************************************/
void Game::initValues() {
	askPlay = "Would you like to play?";
	choosePlay = "1. Play";
	chooseExit = "2. Exit";
	welcome = "Welcome to Phillip Wellheuser's Project 4 Fantasy Combat Tournament. \nLet's begin.\n";
	askChooseChar = ", please choose from the following character types for ";
	askForName = "\nPlease name this character: ";
	askTeamSizesStr = "Please set the team sizes for each player:";
	askP1TeamSize = "Player 1 choose a team size from 1 to 10";
	askP2TeamSize = "Player 2 choose a team size from 1 to 10";
	p1Name = "Player 1";
	p2Name = "Player 2";
	chooseVampire = "1. Vampire";
	chooseBarbarian = "2. Barbarian";
	chooseBlueMen = "3. Blue Men";
	chooseMedusa = "4. Medusa";
	chooseHarryPotter = "5. Harry Potter";
	askSeeDeathStack = "Would you like to see the fighters who died in this tournament?";
	goesFirst = NO_PLAYER;
	rollOffDie = new Die(6);
	p1Queue = new TeamQueue;
	p2Queue = new TeamQueue;
	deathStack = new TeamQueue;
	p1TeamSize = 0;
	p2TeamSize = 0;
	p1Score = 0;
	p2Score = 0;
	useVerbose = 0;
}

/*********************************************************************
** Description: game() coordinates all of the game's fuctions
*********************************************************************/
void Game::runGame() {
	while (choiceMenu1(askPlay, choosePlay, chooseExit) == 1) {
		std::cout << welcome << std::endl;
		askTeamSizes();
		buildTeam();
		rollOff();
		fight();
		printDeathStack();
		askPlay = "\nWould you like to play again?";
		choosePlay = "1. Play again";
	}
}

/*********************************************************************
** Description: askTeamSizes() requests team sizes for each player's team
*********************************************************************/
void Game::askTeamSizes() {
	std::cout << askTeamSizesStr << std::endl;
	p1TeamSize = chooseIntInRange(askP1TeamSize, 1, 10);
	p2TeamSize = chooseIntInRange(askP2TeamSize, 1, 10);
}

/*********************************************************************
** Description: buildTeam() walks the user through adding characters 
** to fill out teams for each player up to the sizes provided
*********************************************************************/
void Game::buildTeam() {
	for (int i = 0; i < p1TeamSize; i++) {
		std::string teamMember= "team member " + std::to_string(i + 1) + ":";
		Character* characterPtr;
		p1Queue->addBack(chooseTypeChar(&characterPtr, p1Name, teamMember));
	}
	for (int i = 0; i < p2TeamSize; i++) {
		std::string teamMember = "team member " + std::to_string(i + 1) + ":";
		Character* characterPtr;
		p2Queue->addBack(chooseTypeChar(&characterPtr, p2Name, teamMember));
	}
}

/*********************************************************************
** Description: chooseTypeChar() takes a pointer to a pointer to a
** character as well as a player name and prompts players to choose
** a character type via a menu then replaces the their respective 
** character pointer with a derived character type
*********************************************************************/
Character* Game::chooseTypeChar(Character** playerObject, std::string playerName, std::string teamMember) {
	std::string prompt = playerName + askChooseChar + teamMember;
	int choice = NO_CHAR; 
	while (choice == NO_CHAR) {
		choice = choiceMenu4(prompt, chooseVampire, chooseBarbarian, chooseBlueMen, chooseMedusa, chooseHarryPotter);
		if (choice == VAMPIRE) {
			if (useVerbose !=0) {
				*playerObject = new Vampire;
				int confirm = confirmCharSelection(*playerObject);
				if (confirm == 1) {
					(*playerObject)->setNameStr(enterStringWithinRange(askForName, 1, 30));
					return *playerObject;
				}
				else {
					choice = NO_CHAR;
					delete *playerObject;
					*playerObject = nullptr;
				}
			}
			else {
				*playerObject = new Vampire;
				(*playerObject)->setNameStr(enterStringWithinRange(askForName, 1, 30));
				return *playerObject;
			}
		}
		else if (choice == BARBARIAN) {
			if (useVerbose !=0) {
				*playerObject = new Barbarian;
				int confirm = confirmCharSelection(*playerObject);
				if (confirm == 1) {
					(*playerObject)->setNameStr(enterStringWithinRange(askForName, 1, 30));
					return *playerObject;
				}
				else {
					choice = NO_CHAR;
					delete *playerObject;
					*playerObject = nullptr;
				}
			}
			else {
				*playerObject = new Barbarian;
				(*playerObject)->setNameStr(enterStringWithinRange(askForName, 1, 30));
				return *playerObject;
			}
		}
		else if (choice == BLUE_MEN) {
			if (useVerbose !=0) {
				*playerObject = new BlueMen;
				int confirm = confirmCharSelection(*playerObject);
				if (confirm == 1) {
					(*playerObject)->setNameStr(enterStringWithinRange(askForName, 1, 30));
					return *playerObject;
				}
				else {
					choice = NO_CHAR;
					delete *playerObject;
					*playerObject = nullptr;
				}
			}
			else {
				*playerObject = new BlueMen;
				(*playerObject)->setNameStr(enterStringWithinRange(askForName, 1, 30));
				return *playerObject;
			}
		}
		else if (choice == MEDUSA) {
			if (useVerbose != 0) {
				*playerObject = new Medusa;
				int confirm = confirmCharSelection(*playerObject);
				if (confirm == 1) {
					(*playerObject)->setNameStr(enterStringWithinRange(askForName, 1, 30));
					return *playerObject;
				}
				else {
					choice = NO_CHAR;
					delete *playerObject;
					*playerObject = nullptr;
				}
			}
			else {
				*playerObject = new Medusa;
				(*playerObject)->setNameStr(enterStringWithinRange(askForName, 1, 30));
				return *playerObject;
			}
		}
		else if (choice == HARRY_POTTER) {
			if (useVerbose != 0) {
				*playerObject = new HarryPotter;
				int confirm = confirmCharSelection(*playerObject);
				if (confirm == 1) {
					(*playerObject)->setNameStr(enterStringWithinRange(askForName, 1, 30));
					return *playerObject;
				}
				else {
					choice = NO_CHAR;
					delete *playerObject;
					*playerObject = nullptr;
				}
			}
			else {
				*playerObject = new HarryPotter;
				(*playerObject)->setNameStr(enterStringWithinRange(askForName, 1, 30));
				return *playerObject;
			}
		}
		else {
			choice = NO_CHAR;
			std::cout << "error in choosing type of character" << std::endl;
		}
	}
	return nullptr;
}

/*********************************************************************
** Description: displays a description of the selected character type
** and asks the user to approve their choice
*********************************************************************/
int Game::confirmCharSelection(Character*currentChar) {
	std::cout << currentChar->getDescribeChar() << std::endl;
	return choiceMenu1("Would you like to select this character?", "1. Yes", "2. No");
}

/*********************************************************************
** Description: rollOff() simply rolls dice for each player and sets
** the payer who rolls higher to go first 
*********************************************************************/
void Game::rollOff(){
	while (goesFirst == NO_PLAYER) {
		int rollOff = rollOffDie->roll();
		if (rollOff%2==0) {
			goesFirst = PLAYER1;
			std::cout <<"\n" << p1Name << " goes first." << std::endl;
		}
		else if (rollOff % 2 != 0) {
			goesFirst = PLAYER2;
			std::cout << "\n" << p2Name << " goes first." << std::endl;
		}
		else {
			goesFirst = NO_PLAYER;
		}
	}
}

/*********************************************************************
** Description: fight() calls attacks between the players' characters
** depending on which player is set to go first
*********************************************************************/
void Game::fight(){
	int round = 1;
	while (p1Queue->isEmpty() == false && p2Queue->isEmpty() == false) {
		int bout = 1;
		if (useVerbose != 0) {
			std::cout << "Round: " << round << " start!" << std::endl;
		}
		Character * p1 = p1Queue->getFront();
		Character * p2 = p2Queue->getFront();
		
		while (p1->getStrength() > 0 && p2->getStrength() > 0) {
			if (useVerbose != 0) {
				std::cout << "Round: " << round << ", " << "Bout: " << bout << std::endl;
			}
			if (goesFirst == PLAYER1) {
				runBout(p1Name, p1, p2Name, p2);
				if (p2->getStrength() > 0) {
					runBout(p2Name, p2, p1Name, p1);
				}
			}
			else if (goesFirst == PLAYER2) {
				runBout(p2Name, p2, p1Name, p1);
				if (p1->getStrength() > 0) {
					runBout(p1Name, p1, p2Name, p2);
				}
			}
			bout++;
		}
		printRoundVictor(round, p1, p2);
		if (p1->getStrength() <= 0) { //if p1's fighter is dead
			deathStack->addBack(p1);
			p1Queue->setFrontChar(nullptr);
			p1Queue->removeFront();
			p2->heal();
			p2Queue->moveFrontToBack();
			p2Score++;
		}
		else if (p2->getStrength() <= 0) { //if p2's fighter is dead
			deathStack->addBack(p2);
			p2Queue->setFrontChar(nullptr);
			p2Queue->removeFront();
			p1->heal();
			p2Queue->moveFrontToBack();
			p1Score++;
		}
		round++;
	}
	printTourneyVictor();
}

/*********************************************************************
** Description: runBout() manages a single attack of one character vs
** another, optionally printing out the specific results if the 
** isVerbose boolean value is true
*********************************************************************/
void Game::runBout(std::string atkPName, Character* attacker, std::string defPName, Character* defender) {
	int attack = attacker->attack();
	if (useVerbose != 0) {
		std::cout << atkPName << "'s " << attacker->getTypeCharStr() << ", "
			<< attacker->getNameStr() << " rolls an attack of "
			<< attack << " damage." << std::endl;
		std::cout << defPName << "'s " << defender->defend(attack) << std::endl;
		std::cout << defPName << "'s " << defender->getTypeCharStr() << ", "
			<< attacker->getNameStr() << " has " << defender->getStrength()
			<< " strength remaining." << "\n" << std::endl;
	}
	else {
		defender->defend(attack);
	}
}

/*********************************************************************
** Description: printBoutVictor() prints out the victor of a bout depending
** on which character still has strength greater than 0
*********************************************************************/
void Game::printRoundVictor(int currentRound, Character* p1, Character* p2) {
	std::cout << "\nRound " << currentRound << ":\n"
		<< p1Name << "'s " << p1->getTypeCharStr() << ", " << p1->getNameStr() << " vs. "
		<< p2Name << "'s " << p2->getTypeCharStr() << ", " << p2->getNameStr() << ":\n";
	
	if (p1->getStrength() <= 0) {
		std::cout << "---" << p2Name << "'s " << p2->getNameStr()<< " wins the Round!---" << std::endl;
	}
	else if (p2->getStrength() <= 0) {
		std::cout << "---" << p1Name << "'s " << p1->getNameStr() << " wins the Round!---" << std::endl;
	}
	else {
		std::cout << "something wrong with printBoutVictor()" << std::endl;
	}
}

/*********************************************************************
** Description: printTourneyVictor() prints out the victor of a tournament
** depending on which player queue has remaining characters
*********************************************************************/
void Game::printTourneyVictor() {
	if (p1Score < p2Score){
		std::cout << "\n---" << p2Name << "'s team defeated " << p1Name << "'s team " << p2Score << " to " << p1Score << "---\n" << std::endl;
	}
	else if (p1Score > p2Score) {
		std::cout << "\n---" << p1Name << "'s team defeated " << p2Name << "'s team " << p1Score << " to " << p2Score << "---\n" << std::endl;
	}
	else if (p1Score == p2Score) {
		std::cout << "\n---The tournament is a tie!---\n" << std::endl;
	}
	else {
		std::cout << "something wrong with printTourneyVictor()" << std::endl;
	}
}

/*********************************************************************
** Description: printDeathStack() prints out the all of the dead characters
** from the tournament in reverse of the order they died
*********************************************************************/
void Game::printDeathStack() {
	int choice = 0;
	choice = choiceMenu1(askSeeDeathStack, "1. Yes", "2. No");
	if (choice == 1) {
		std::cout << "The fighters who died in this tournament were: ";
		deathStack->printRevQueue();
	}
	else {
		//do nothing
	}
}
