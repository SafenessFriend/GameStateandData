#pragma once
#include "DynArr.h"

template <class Key, class Val>
class Map {
public:
	class Pair {
	public:
		Pair() = default;
		Pair(Key _key) : first(_key), second(Val()) {}
		Pair(Key _key, Val _value) : first(_key), second(_value) {}
		~Pair() = default;

		explicit operator Val() { return second; }

		Key first;
		Val second;
	};

	typedef Pair* iterator;
	typedef const Pair* const_iterator;

	Map() = default;
	~Map() = default;

	Val& operator [](const Key _index) {
		// Search for a matching key
		iterator iter = find(_index);
		// if we find one, return the existing value
		if (iter != end()) {
			return (*iter).second;
		}
		// otherwise, insert a default element to that key
		return insert_default(_index).second;
	}

	iterator find(const Key _index) {
		// iterate through every element in the list, to see if there is a key that matches.
		for (iterator iter = begin(); iter != end(); iter++) {
			if ((*iter).first == _index) {
				// Matching key found!
				return iter;
			}
		}

		// If no key found, return an iterator at the end of the container (nullptr)
		return end();
	}
	const_iterator find(const Key _index) const {
		// iterate through every element in the list, to see if there is a key that matches.
		for (iterator iter = begin(); iter != end(); iter++) {
			if ((*iter).first == _index) {
				// Matching key found!
				return iter;
			}
		}

		// If no key found, return an iterator at the end of the container (nullptr)
		return end();
	}

	void clear() { m_elements.clear(); }

	iterator begin() { return &m_elements[0]; }
	iterator end() { return &m_elements[size()]; }
	const_iterator begin() const { return &m_elements[0]; }
	const_iterator end() const { return &m_elements[size()]; }

	unsigned int size() { return m_elements.size(); }
	bool empty() { return m_elements.empty(); }

private:
	Pair& insert_default(const Key _key) {
		m_elements.push_back(Pair(_key));
		return m_elements.back();
	}

	DynArr<Pair> m_elements;
};