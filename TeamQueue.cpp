/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/29/19
** Description: Implements source code for TeamQueue class.
** TeamQueue is used for creating a queue for each team
*********************************************************************/
#include <iostream>
#include <string>
#include "character.hpp"//could cause circular include...?
#include "TeamNode.hpp"
#include "TeamQueue.hpp"

TeamQueue::TeamQueue() { 
	front = nullptr;
	back = nullptr;
}

TeamQueue::~TeamQueue() {
	TeamNode *nodePtr = front;
	while (nodePtr != back) {
		TeamNode *garbage = nodePtr;
		nodePtr = nodePtr->getNext(); 
		delete garbage; 
	}
	delete nodePtr;
}

/*********************************************************************
** Description: adds a node to the back of the queue using parameter 
** and sets it to the tail value of the list
*********************************************************************/
void TeamQueue::addBack(Character * inChar) {
	if (back == nullptr) {
		back = new TeamNode(inChar, front, front);
		back->setNext(back);
		back->setPrev(back);
		front = back;
	}
	else {
		//new tail's previous = old tail
		TeamNode *nodePtr = back;//make a temporary pointer to reference nodes
		nodePtr->setNext(new TeamNode(inChar, front, back));//make new back and set its next = front
		back = nodePtr->getNext();//reassign the back pointer to the new node
		front->setPrev(back);
	}
}

/*********************************************************************
** Description: removes a node from the head of the list and sets the 
** second node to the head value
*********************************************************************/
void TeamQueue::removeFront() {
	if (!front) {
		std::cout << "There are no values in this list." << std::endl;
		return;
	}
	else {
		TeamNode *nodePtr;
		nodePtr = front;
		if (front->getNext() != front) {
			front = front->getNext();
			back->setNext(front);
			front->setPrev(back);
		}
		else if (front->getNext() == front) {
			front = nullptr;
			back = nullptr;
		}
		else {
			std::cout << "unexpected occured in removeFromFront()" << std::endl;
		}
		delete nodePtr;
	}
}

/*********************************************************************
** Description: displays the current value of the front node of the list
*********************************************************************/
void TeamQueue::displayFront() {
	if (front == nullptr) {
		std::cout << "There are no values in this list." << std::endl;
	}
	else {
		std::cout << front->getHeldChar()->getNameStr() << " the " << front->getHeldChar()->getTypeCharStr();
	}
}

/*********************************************************************
** Description: returns the character in the node at the front of the
** queue
*********************************************************************/
Character * TeamQueue::getFront() {
	return this->front->getHeldChar();
}

/*********************************************************************
** Description: sets the front node's character value to the provided
** parameter character
*********************************************************************/
void TeamQueue::setFrontChar(Character* charIn) {
	this->front->setHeldChar(charIn);
}

/*********************************************************************
** Description: displays the current value of the back node of the list
*********************************************************************/
void TeamQueue::displayBack() {
	if (back == nullptr) {
		std::cout << "There are no values in this list." << std::endl;
	}
	else {
		std::cout << front->getHeldChar()->getNameStr() << " the " << front->getHeldChar()->getTypeCharStr();
	}
}

/*********************************************************************
** Description: returns the character in the node at the front of the
** queue
*********************************************************************/
Character * TeamQueue::getBack() {
	return this->back->getHeldChar();
}

/*********************************************************************
** Description: returns true if the queue is empty
*********************************************************************/
bool TeamQueue::isEmpty() {
	if (front == nullptr && back == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

/*********************************************************************
** Description: moves the front node to the back of the queue
*********************************************************************/
void TeamQueue::moveFrontToBack() {
	if (front != back) {
		front = front->getNext();
		back = front->getPrev();
	}
}

/*********************************************************************
** Description: prints the names of the characters in the queue in
** reverse order
*********************************************************************/
void TeamQueue::printRevQueue() {
	if (!front) {
		std::cout << "empty";
	}
	else {
		TeamNode *nodePtr = back;
		std::cout << nodePtr->getHeldChar()->getNameStr();
		nodePtr = nodePtr->getPrev();
		while (nodePtr->getPrev() !=front){
			std::cout << nodePtr->getHeldChar()->getNameStr() << std::endl;
			nodePtr = nodePtr->getPrev();
		} 
		std::cout << "\n";
	}
}


