#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	cap = 10;
	elements = 0;
	array = new int[cap];

}


DynamicArray::~DynamicArray()
{
}

void DynamicArray::CreateArray(int initialSize)
{

}