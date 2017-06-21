#pragma once
#include <memory>

template <class T>
class DynArr
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	DynArr(unsigned int _capacity = 10) : m_capacity(0), m_size(0)
	{
		reserve(_capacity);
	}

	~DynArr() {
		if (!empty())
			delete[] m_data;
	}

	void push_back(T item)
	{
		// check if there is room, if not, add capacity
		if (m_size == m_capacity)
			reserve();

		// add item to end
		m_data[m_size++] = item;
	}

	void insert(unsigned int _index, T item)
	{
		// check for room, if not, add capacity
		if (m_size == m_capacity)
			reserve();

		// shift existing items right, make room for new item at location
		for (unsigned int i = m_size; i >= _index; i--)
			m_data[i + 1] = m_data[i];


		// add to specific location
		m_data[_index] = item;
		m_size++;

	}

	void reserve(unsigned int _capacity = 10)
	{
		m_capacity += _capacity;
		T* temp = new T[m_capacity];
		memcpy(temp, m_data, sizeof(T) * m_size);
		delete[] m_data;
		m_data = temp;
	}

	void pop_back()
	{
		m_data[m_size--] = T();
	}

	void remove(unsigned int _index)
	{
		// shift left 
		for (unsigned int i = _index + 1; i < m_size; i++)
			m_data[i - 1] = m_data[i];

		// shrink array
		m_size--;
	}

	void clear()
	{
		if (empty()) return;

		for (unsigned int i = m_size; i > 0; i--)
			remove(i - 1);
	}

	T& operator [](unsigned int _index)
	{
		return m_data[_index];
	}

	unsigned int size() const { return m_size; }
	bool empty() const { return m_size == 0; }

protected:

private:
	unsigned int m_size, m_capacity;
	T* m_data;

};