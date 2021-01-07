/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/26/19
** Description: Specifies the TeamQueue class header. TeamQueue is
** used for creating a queue for each team
*********************************************************************/
#ifndef TEAMQueue_HPP
#define TEAMQueue_HPP
class TeamNode;
class Character;

class TeamQueue {
protected:
	TeamNode* front;
	TeamNode* back;
public:
	TeamQueue();
	~TeamQueue();

	/*********************************************************************
** Description: adds a node to the tail of the list using parameter
** and sets it to the tail value of the list
*********************************************************************/
	void addBack(Character * inChar);
	
	/*********************************************************************
** Description: removes a node from the head of the list and sets the
** second node to the head value
*********************************************************************/
	void removeFront();

	/*********************************************************************
** Description: displays the current value of the head node of the list
*********************************************************************/
	void displayFront();

	/*********************************************************************
** Description: returns the character in the node at the front of the 
** queue
*********************************************************************/
	Character * getFront();

	/*********************************************************************
** Description: sets the front character to the provided parameter
*********************************************************************/
	void setFrontChar(Character* CharIn);

	/*********************************************************************
** Description: displays the current value of the back node of the list
*********************************************************************/
	void displayBack();

	/*********************************************************************
** Description: returns the character in the node at the back of the
** queue
*********************************************************************/
	Character * getBack();

	/*********************************************************************
** Description: returns true if the queue is empty
*********************************************************************/
	bool isEmpty();

	/*********************************************************************
** Description: moves the front node to the back of the queue
*********************************************************************/
	void moveFrontToBack();

	/*********************************************************************
** Description: prints the names of the characters in the queue in
** reverse order
*********************************************************************/
	void printRevQueue();
};


#endif