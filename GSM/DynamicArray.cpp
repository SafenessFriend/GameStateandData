#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray()
{
	capacity = 10;
	elements = 0;
	array = new int[capacity];

}


DynamicArray::~DynamicArray()
{
}

void DynamicArray::Add(int el)
{
	if (elements >= capacity)
		Expand();

	array[elements++] = el;
}

const int DynamicArray::GetAt(int index)
{
	if (index < 0 || index >= elements)
		throw ("Out of bounds exception!");

	return array[index];
}

void DynamicArray::PopBack()
{
	if (elements > 0)
		array[--elements] = 0;
	else
		throw("Empty array!");
}

const int DynamicArray::GetElements() 
{
	return elements;
} 

void DynamicArray::Initialise(int from)
{
	for (size_t i = from; i < capacity; i++)
	{
		array[i] = 0;
	}
}

void DynamicArray::Expand()
{
	capacity *= 2;

	int *tempArray = new int[capacity];

	for (size_t i = 0; i < capacity; i++)
	{
		tempArray[i] = array[i];
	}

	delete[] array;

	array = tempArray;

	Initialise(elements);

}
