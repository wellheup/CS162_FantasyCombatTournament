/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/26/19
** Description: Specifies the TeamNode struct header.
** TeamNode is used for creating single value nodes for TeamQueued lists
*********************************************************************/
#ifndef TEAMNODE_HPP
#define TEAMNODE_HPP
class Character;

class TeamNode {
protected:
	Character* heldChar;
	TeamNode *next, *prev;
public:
	TeamNode(Character * inChar, TeamNode *next1 = nullptr, TeamNode *prev1 = nullptr);
	~TeamNode();
	Character * getHeldChar();
	void setHeldChar(Character * inChar);
	TeamNode* getNext();
	void setNext(TeamNode* next);
	TeamNode* getPrev();
	void setPrev(TeamNode* prev);
};
#endif