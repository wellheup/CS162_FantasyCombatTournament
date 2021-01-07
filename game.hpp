/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/26/19
** Description: Specifies Game class which will run the game and
** use the different character classes 
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "enums.hpp"
enum typeChar;
enum Player;
class Character; 
class Die;
class TeamQueue;

class Game{
private:
	TeamQueue *p1Queue, 
		*p2Queue, 
		*deathStack;
	std::string askPlay,
		choosePlay,
		chooseExit,
		welcome,
		askChooseChar,
		askForName,
		p1Name,
		p2Name,
		askTeamSizesStr,
		askP1TeamSize,
		askP2TeamSize,
		chooseVampire,
		chooseBarbarian,
		chooseBlueMen,
		chooseMedusa,
		chooseHarryPotter,
		dispRollOff,
		askSeeDeathStack;
	int p1TeamSize,
		p2TeamSize,
		p1Score,
		p2Score,
		useVerbose;
	Die *rollOffDie;
	Player goesFirst;
protected:

public:
	/*********************************************************************
** Description: base constructor sets all of the starting values
** for all of the variables in the class
*********************************************************************/
	Game();

	/*********************************************************************
** Description: 1 parameter constructor sets all of the starting values
** for all of the variables in the class and turns on character
** selection confirmation if the passed int != 0
*********************************************************************/
	Game(int useVerbose);

	//destructor
	~Game();
	
	/*********************************************************************
** Description: initValues() actually sets all of the variables used in game
*********************************************************************/
	void initValues();

	/*********************************************************************
** Description: runGame() coordinates all of the game's fuctions
*********************************************************************/
	void runGame(); 

	/*********************************************************************
** Description: askTeamSizes() requests team sizes for each player's team
*********************************************************************/
	void askTeamSizes();

	/*********************************************************************
** Description: buildTeam() walks the user through adding characters
** to fill out teams for each player up to the sizes provided
*********************************************************************/
	void buildTeam();

	/*********************************************************************
** Description: chooseTypeChar() takes a pointer to a pointer to a
** character as well as a player name and prompts players to choose
** a character type via a menu then replaces the their respective
** character pointer with a derived character type
*********************************************************************/
	Character* chooseTypeChar(Character** playerObject, std::string playerName, std::string teamMember);

	/*********************************************************************
** Description: displays a description of the selected character type
** and asks the user to approve their choice
*********************************************************************/
	int confirmCharSelection(Character*confirmThis);

	/*********************************************************************
** Description: rollOff() simply rolls dice for each player a player a
** as going first depending if the roll is even or odd
*********************************************************************/
	void rollOff();

	/*********************************************************************
** Description: fight() calls attacks between the players' characters
** depending on which player is set to go first
*********************************************************************/
	void fight(); 

	/*********************************************************************
** Description: runBout() takes an attacker and defender parameter, performs
** an attack exchange between them and prints the results
*********************************************************************/
	void runBout(std::string atkPName, Character* attacker, std::string defPName, Character* defender);

	/*********************************************************************
** Description: printBoutVictor() prints out the victor of a bout depending
** on which character passed still has strength greater than 0
*********************************************************************/
	void printRoundVictor(int currentRound, Character* p1, Character* p2);

	/*********************************************************************
** Description: printTourneyVictor() prints out the victor of a tournament
** depending on which player queue has remaining characters
*********************************************************************/
	void printTourneyVictor();

	/*********************************************************************
** Description: printDeathStack() prints out the all of the dead characters
** from the tournament in reverse of the order they died
*********************************************************************/
	void printDeathStack();
};
#endif
