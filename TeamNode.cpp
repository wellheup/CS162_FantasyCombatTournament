/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/29/19
** Description: Implements source code for TeamNode class header.
** TeamNode is used for creating single value nodes for TeamQueued lists
*********************************************************************/
#include <iostream>
#include "character.hpp"
#include "TeamNode.hpp"

TeamNode::TeamNode(Character * inChar, TeamNode * next1, TeamNode * prev1) {
	heldChar = inChar;
	next = next1;
	prev = prev1;
}

TeamNode::~TeamNode() {
	delete heldChar;
}

Character * TeamNode::getHeldChar() {
	return this->heldChar;
}

void TeamNode::setHeldChar(Character * inChar) {
	this->heldChar = inChar;
}

TeamNode * TeamNode::getNext() {
	return this->next;
}

void TeamNode::setNext(TeamNode * next) {
	this->next = next;
}

TeamNode * TeamNode::getPrev() {
	return this->prev;
}

void TeamNode::setPrev(TeamNode * prev) {
	this->prev = prev;
}
