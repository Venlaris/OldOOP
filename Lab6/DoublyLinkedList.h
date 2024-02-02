#pragma once
#include "Node.h"

class DoublyLinkedList {

	Node* head;
	Node* tail;
	Node* focusNode;

	int listSize = 0;
	

public:
	DoublyLinkedList(Node* newHead, Node* newTail);

	bool add(Node* data, int pos); //adds a node
	bool remove(int pos); //removes a node
	bool replace(Node* oldNode, Node* newNode); //replaces oldNode with newNode

	
	Node* nodeAt(int pos); //checks if there is a node at ..

	void Display_Forward(); //displays the list from start to end
	void Display_Backward(); //displays the list in reverse

	int search(Node* data); //searches for a node
	int size(); //lists the list size
};