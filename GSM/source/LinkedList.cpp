#include "LinkedList.h"
#include <iostream>

struct node
{
	int data;
		node *next;
};

LinkedList::LinkedList()
{

	head = nullptr;
	tail = nullptr;
}


LinkedList::~LinkedList()
{
}

void LinkedList::createNode(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = nullptr;
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		temp = nullptr;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void LinkedList::displayNode()
{
	node *temp = new node;
	temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}

void LinkedList::insertStart(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = head;
	head = temp;
}

void LinkedList::insertPosition(int pos, int value)
{
	node *pre = new node;
	node *cur = new node;
	node *temp = new node;
	cur = head;
	for (int i = 1; i<pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;
}

void LinkedList::deleteFirst()
{
	node *temp = new node;
	temp = head;
	head = head->next;
	delete temp;
}

void LinkedList::deleteLast()
{
	node *current = new node;
	node *previous = new node;
	current = head;
	while (current->next != nullptr)
	{
		previous = current;
		current = current->next;
	}
	tail = previous;
	previous->next = nullptr;
	delete current;
}

void LinkedList::deletePosition(int pos)
{
	node *current = new node;
	node *previous = new node;
	current = head;
	for (int i = 1; i<pos; i++)
	{
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
}


