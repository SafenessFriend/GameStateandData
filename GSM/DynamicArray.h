#pragma once
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	void CreateArray(int initialSize);

private:
	int cap;
	int elements;
	int *array;


};

