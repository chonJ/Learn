﻿#include <vector>
#include <list>
using namespace std;
template <typename HashedObj>
class HashTable
{
public:
	explicit HashTable(int size = 101) : array(size)
	{
		makeEmpty();
	}

	void makeEmpty()
	{
		currentSize = 0;
		for (int i = 0; i < array.size(); i++)
			array[i].info = EMPTY;
	}

	bool contains(const HashedObj & x) const
	{
		return isActive(findPos(x));
	}

	bool insert(const HashedObj & x)
	{
		// Insert x as active
		int currentPos = findPos(x);
		if (isActive(currentPos))
			return false;

		array[currentPos] = HashEntry(x, ACTIVE);

		if (++currentSize > array.size() / 2)
			rehash();

		return true;
	}

	bool remove(const HashedObj & x)
	{
		int currentPos = findPos(x);
		if (!isActive(currentPos))
			return false;
		array[currentPos].info = DELETED;
		return true;
	}

	enum EntryType { ACTIVE, EMPTY, DELETED };

private:
	struct HashEntry
	{
		HashedObj element;
		EntryType info;
		HashEntry(const HashedObj & e = HashedObj(), EntryType i = EMPTY)
			: element(e), info(i) { }
	};

	vector<HashEntry> array;
	int currentSize;

	int findPos(const HashedObj & x) const
	{
		int offset = 1;
		int currentPos = myhash(x);

		while (array[currentPos].info != EMPTY && array[currentPos].element != x)
		{
			currentPos += offset;  // Compute ith probe
			offset += 2;
			if (currentPos >= array.size())
				currentPos -= array.size();
		}
		return currentPos;
	}

	bool isActive(int currentPos) const
	{
		return array[currentPos].info == ACTIVE;
	}

	void rehash()
	{
		vector<HashEntry> oldArray = array;

		// Create new double-sized, empty table
		array.resize(2 * oldArray.size());
		for (int j = 0; j < array.size(); j++)
			array[j].info = EMPTY;

		// Copy table over
		currentSize = 0;
		for (int i = 0; i < oldArray.size(); i++)
			if (oldArray[i].info == ACTIVE)
				insert(oldArray[i].element);
	}

	int myhash(const HashedObj & x) const;
};