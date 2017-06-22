#pragma once
#include <memory>

template <class T>
class DynArr {
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	DynArr(unsigned int _capacity = 10) : m_capacity(0), m_size(0) {
		reserve(_capacity);
	}
	~DynArr() {
		if (!empty())
			delete[] m_data;
	}

	void push_back(T item) {
		// check if the container has room for new items, if it doesn't, add new capacity
		if (m_size == m_capacity)
			reserve();

		// append the item to the end of the list
		m_data[m_size++] = item;
	}

	void insert(unsigned int _index, T item) {
		// check if the container has room for new items, if it doesn't, add new capacity
		if (m_size == m_capacity)
			reserve();

		// Shift existing items to the right, to make room for the new item at the specified index
		for (unsigned int i = m_size; i >= _index; i--)
			m_data[i + 1] = m_data[i];

		// Add the item to the specified location
		m_data[_index] = item;
		m_size++;
	}

	void reserve(unsigned int _capacity = 10) {
		m_capacity += _capacity;
		T* temp = new T[m_capacity];
		memcpy(temp, m_data, sizeof(T) * m_size);
		delete[] m_data;
		m_data = temp;
	}

	void pop_back() {
		// Decrease size, and set the last element's data to a "null" initialized value
		m_data[m_size--] = T();
	}

	void remove(unsigned int _index) {
		// Shift existing items to the left, to replace the item we want to remove
		for (unsigned int i = _index + 1; i < m_size; i++)
			m_data[i - 1] = m_data[i];

		// Decrease the size
		m_size--;
	}

	void clear() {
		// If there is nothing in the container, do nothing
		if (empty()) return;

		// For every element that exists in the container, remove it
		for (unsigned int i = m_size; i > 0; i--)
			remove_at(i - 1);
	}

	T& operator [](unsigned int _index) {
		return m_data[_index];
	}

	// Iterator functions


	unsigned int size() const { return m_size; }
	bool empty() const { return m_size == 0; }

protected:
private:
	unsigned int m_size, m_capacity;
	T* m_data;
};

















//#pragma once
//#include <memory>
//#include <assert.h>
//
//template <class T>
//class DynamicArray {
//private:
//	static const unsigned int DEFAULT_CAPACITY = 20;
//	typedef T* iterator;
//	typedef const T* const_iterator;
//
//public:
//	DynamicArray(unsigned int _capacity = DEFAULT_CAPACITY) : m_capacity(_capacity), m_size(0) {
//		reserve(_capacity);
//	}
//	~DynamicArray() {
//		if (m_size > 0)
//			delete[] data;
//	}
//
//	void push_back(T _item) {
//		if (m_size == m_capacity)
//			reserve();
//
//		// assign the new element into the array location
//		data[m_size++] = _item;
//	}
//
//	void insert_at(unsigned int _index, T _item) {
//		assert(_index <= m_size);
//
//		// If we have reached capacity, expand to fit new elements
//		if (m_size == m_capacity)
//			reserve();
//
//		T *temp(new T[m_capacity]);
//		int count = 0;
//		m_size++;
//		for (unsigned int i = 0; i < m_size; ++i) {
//			if (i == _index) {
//				temp[_index] = _item;
//				count++;
//			}
//			temp[count++] = data[i];
//		}
//		memcpy(data, temp, sizeof(T) * m_size);
//		delete[] temp;
//	}
//
//	void pop_back() {
//		data[--m_size] = T();
//	}
//
//	void erase_at(unsigned int _index) {
//		assert(_index < m_size);
//
//		for (unsigned int i = _index + 1; i < m_capacity; ++i)
//			data[i - 1] = data[i];
//
//		// Update the size
//		m_size--;
//	}
//
//	// Remove everything currently stored in the list (if anything)
//	void clear() {
//		if (m_size == 0) return; // return out of the function if there isn't anything to delete
//		for (unsigned int i = m_size; i > 0; --i)
//			erase_at(i - 1);
//	}
//
//	void reserve(unsigned int _capacity = DEFAULT_CAPACITY) {
//		m_capacity += _capacity;
//		T *newData = new T[m_capacity];
//		memcpy(newData, data, sizeof(T) * m_size);
//		delete[] data;
//		data = newData;
//	}
//
//	T& operator [](unsigned int _index) {
//		assert(_index <= m_size);
//
//		return data[_index];
//	}
//
//	T& back() { return data[m_size - 1]; }
//
//	iterator begin() { return data; }
//	iterator end() { return &data[m_size]; }
//	const_iterator begin() const { return data; }
//	const_iterator end() const { return &data[m_size]; }
//
//	unsigned int size() const { return m_size; }
//	bool empty() { return m_size == 0; }
//
//private:
//	unsigned int m_capacity, m_size;
//	T* data;
//};