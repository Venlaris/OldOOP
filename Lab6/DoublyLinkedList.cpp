#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList(Node* newHead, Node* newTail) {

	head = newHead;
	tail = newTail;
}

bool DoublyLinkedList::add(Node* data, int pos) {
    if (pos < 0 || pos > listSize) {
        cerr << "You're trying to add in a position that is not in the list" << endl;
        return false;
    }

    Node* focusNode;  // Declare focusNode here

    if (pos == 0) {
        // Adding at the beginning
        if (head != nullptr) {
            data->setNext(head);
            head->setPrev(data);
        }
        head = data;

        if (listSize == 0) {
            // If the list was empty, set the tail as well
            tail = data;
        }
    } else if (pos == listSize) {
        // Adding at the end
        tail->setNext(data);
        data->setPrev(tail);
        tail = data;
    } else {
        // Adding in the middle
        focusNode = nodeAt(pos - 1);
        if (focusNode == nullptr) {
            cerr << "Error: Attempting to add beyond the end of the list." << endl;
            return false;
        }

        data->setNext(focusNode->getNext());
        data->setPrev(focusNode);
        focusNode->getNext()->setPrev(data);
        focusNode->setNext(data);
    }

    listSize += 1;
    return true;
}

bool DoublyLinkedList::remove(int pos) {
	
	Node* focusNode = head;
	Node* subNode;

	if (pos > listSize || pos < 0) {
		return false;
		cerr << "You're trying to remove something that doesn't exist" << endl;
	}
	
	else if (pos == 0) { //removes the head and switches it to the next node in line
		Node* focusNode = head;
		head = focusNode->getNext(); //simply puts the head to the next node in line
		
		if (head != nullptr) {
			head->setPrev(nullptr);
		}
		else{ //just to make sure the user knows that the last node has been //deleted
			cout << "You //deleted the last node in this list" << endl;
		}
		
		delete focusNode;
	}

	else if (pos == listSize) { //removes the tail
		Node* focusNode = tail;
		tail = focusNode->getPrev(); //simply puts the tail to the previous node in line

		if (tail != nullptr) {
			tail->setNext(nullptr);
		}
		else { //just to make sure the user knows that the last node has been deleted
			cout << "You deleted the last node in this list" << endl;
		}
		delete focusNode;
	}

	else { //node is somewhere in the middle
		int i = 0;
		while (i < pos) {
			focusNode = focusNode->getNext();
			i++;
		}
		subNode = focusNode;
		focusNode->getPrev()->setNext(focusNode->getNext());
		focusNode->getNext()->setPrev(focusNode->getPrev());
		delete subNode;
	}
	listSize -= 1;
	return true;
}

bool DoublyLinkedList::replace(Node* oldNode, Node* newNode) {
	if (oldNode == nullptr || newNode == nullptr) {
		return false;
	}

	Node* focusNode = head;

	// Find the oldNode in the list
	while (focusNode != nullptr && focusNode != oldNode) {
		focusNode = focusNode->getNext();
	}

	if (focusNode == nullptr) {
		// oldNode not found in the list
		return false;
	}

	// Update pointers around oldNode
	if (focusNode->getPrev() != nullptr) {
		focusNode->getPrev()->setNext(newNode);
	}
	else {
		head = newNode;  // If oldNode is the head
	}

	if (focusNode->getNext() != nullptr) {
		focusNode->getNext()->setPrev(newNode);
	}
	else {
		return false;  // If oldNode is the tail
	}

	// Update the next node's prev pointer if it's not the tail
	if (focusNode->getNext() != nullptr) {
		focusNode->getNext()->setPrev(newNode);
	}

	// Update the prev node's next pointer if it's not the head
	if (focusNode->getPrev() != nullptr) {
		focusNode->getPrev()->setNext(newNode);
	}

	// Connect newNode to the list
	newNode->setPrev(focusNode->getPrev());
	newNode->setNext(focusNode->getNext());

	// Update the next node's prev pointer if it's not the tail
	if (focusNode->getNext() != nullptr) {
		focusNode->getNext()->setPrev(newNode);
	}

	// Update the prev node's next pointer if it's not the head
	if (focusNode->getPrev() != nullptr) {
		focusNode->getPrev()->setNext(newNode);
	}

	// Check if oldNode is the tail, and update tail accordingly
	//if (oldNode == tail) {
	//	tail = newNode;
	//}

	// Delete oldNode
	//delete oldNode;

	return true;
}


	/*if (focusNode->getPrev() != nullptr) {
		focusNode->getPrev()->setNext(newNode);
	}
	else {
		head = newNode;
	}

	if (focusNode->getNext() != nullptr) {
		focusNode->getNext()->setPrev(newNode);
	}
	else {
		tail = newNode;
	}

	newNode->setPrev(focusNode->getPrev());
	newNode->setNext(focusNode->getNext());

	//delete focusNode;
	return true;
}*/

Node* DoublyLinkedList::nodeAt(int pos) {
	
	Node* focusNode = head;
	int i = 0;

	if (pos < 0 || pos > listSize) {
		cerr << "The node position is not in the list" << endl;
		return nullptr;
	}
	
	while (i < pos) { //for loops can be used as for(i = 0, i < pos, i++) but I just like while loops
		focusNode = focusNode->getNext(); //loops through the list until it finds the node at the given position
		i++;
	}
	return focusNode;
}

void DoublyLinkedList::Display_Forward() {
	Node* focusNode = head;
	int i = 0;

	if (listSize == 0) { //just in case the list happens to be empty
		cout << "List is empty" << endl;
		return;
	}
	else { //otherwise prints the list in a [x, y, z, a, b] fashion
		cout << "[";
		while (i < listSize) {
			cout << focusNode->getData();

			if (i < listSize - 1) { //puts a comma and space as long as i is 1 less than list length
				cout << ", ";
			}

			focusNode = focusNode->getNext();
			i++;
		}
		cout << "]" << endl;
	}
}

void DoublyLinkedList::Display_Backward() {
	Node* focusNode = tail;
	int i = listSize;

	if (listSize == 0) { //just in case the list happens to be empty
		cout << "List is empty" << endl;
		return;
	}
	else { //otherwise prints the list in a [x, y, z, a, b] fashion
		cout << "[";
		while (i > 0) {
			cout << focusNode->getData();

			if (i > 1) { //puts a comma and space as long as i is 1 less than list length
				cout << ", ";
			}

			focusNode = focusNode->getPrev();
			i--;
		}
		cout << "]" << endl;
	}
}


int DoublyLinkedList::search(Node* data) {
	Node* focusNode = head;

	for (int i = 0; i < listSize; i++) {
		if (focusNode == data) {
			return i;
		}
		focusNode = focusNode->getNext();
	}
	return -1;
}

int DoublyLinkedList::size() {
	return listSize;
}