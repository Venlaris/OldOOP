#pragma once
#ifndef NODE_H
#define NODE_H



class Node {

	int data;
	Node* next;
	Node* prev;

public:

	Node(int value);
	Node(const Node& other);
	int getData();
	void setData(int newData);
	Node* getNext();
	void setNext(Node* newNext);
	Node* getPrev();
	void setPrev(Node* newPrev);
};

#endif // !NODE_H