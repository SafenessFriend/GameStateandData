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
			remove(i - 1);
	}

	T& operator [](unsigned int _index) {
		return m_data[_index];
	}

	T& back() { return m_data[m_size - 1]; }

	// Iterator functions
	iterator begin() { return m_data; }
	const_iterator begin() const { return m_data; }

	iterator end() { return &m_data[m_size]; }
	const_iterator end() const{ return &m_data[m_size]; }

	unsigned int size() const { return m_size; }
	bool empty() const { return m_size == 0; }

protected:

private:
	unsigned int m_size, m_capacity;
	T* m_data;
};













