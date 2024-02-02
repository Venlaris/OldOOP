#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	Node* head = nullptr;
	Node* tail = nullptr;
	DoublyLinkedList list(head, tail);

	Node* nodeOne = new Node(1);
	Node* nodeTwo = new Node(2);
	Node* nodeThree = new Node(7);
	Node* nodeFour = new Node(12);
	Node* nodeFive = new Node(14);
	Node* nodeSix = new Node(16);
	Node* nodeSeven = new Node(42);
	Node* nodeEight = new Node(53);

	list.add(nodeEight, 0);
	list.add(nodeTwo, 1);
	list.add(nodeFive, 2);
	list.add(nodeSix, 3);
	list.add(nodeSeven, 4);
	list.add(nodeFour, 5);
	list.add(nodeThree, 6);

	 
	cout << "Forwards: ";
	list.Display_Forward();
	cout << "Backwards: ";
	list.Display_Backward();
	//list.remove(2);
	//list.Display_Backward();
	cout << "Forwards: ";
	list.Display_Forward();
	cout << "Replaced ";
	list.replace(nodeThree, nodeEight);
	cout << "the nodes forwards: ";
	list.Display_Forward();
	
	cout << "Searching... found the node at pos: " << list.search(nodeFour) << endl;
	//cout << "Searching..." << list.search(nodeTwo) << endl;
	//cout << "Finding node..." << list.nodeAt(3) << endl;
	cout << "Finding list size... list size is: " << list.size() << endl;

	//Freeing up the memory again
	delete nodeOne;
	delete nodeTwo;
	delete nodeThree;
	delete nodeFour;
	delete nodeFive;
	delete nodeSix;
	delete nodeSeven;
	delete nodeEight;

	return 0;
}