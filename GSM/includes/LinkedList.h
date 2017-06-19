#pragma once

struct node;

class LinkedList

{
public:
	LinkedList();
	~LinkedList();

	void createNode(int value);					// create a node
	void displayNode();							// display a node

	void insertStart(int value);				// insertion at the start
	void insertPosition(int pos, int value);	// insert at a particular position
	void deleteFirst();							// delete first node
	void deleteLast();							// delete last node
	void deletePosition(int pos);				// delete a certaion position
private:

	node *head, *tail;
};

