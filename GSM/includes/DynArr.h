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
		// check for room, if full create more space
		if (m_size == m_capacity)
			reserve();

		// append the item to the end
		m_data[m_size++] = item;
	}

	void insert(unsigned int _index, T item) {
		// check if the container has room, if no room insert at specific point
		if (m_size == m_capacity)
			reserve();

		// Shift to the right
		for (unsigned int i = m_size; i >= _index; i--)
			m_data[i + 1] = m_data[i];

		// Add the item to specific location
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
		// Decrease size
		m_data[m_size--] = T();
	}

	void remove(unsigned int _index) {
		// Shift to the left and replace
		for (unsigned int i = _index + 1; i < m_size; i++)
			m_data[i - 1] = m_data[i];

		// Decrease size
		m_size--;
	}

	void clear() {
		// If nothing do nothing
		if (empty()) return;

		// remove elements
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













