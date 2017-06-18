#pragma once
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	void Add(int el);
	const int GetAt(int index);
	void PopBack();
	const int GetElements();

private:
	int capacity;
	int elements;
	int *array;

	void Expand();
	void Initialise(int from);

};

