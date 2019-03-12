#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (m.find(key) != m.end())
		{
			int v = m[key];
			m.erase(key);

			m.insert(pair<int, int>(key, v));
			return v;
		}
		else
			return -1;
	}

	void put(int key, int value) {
		//unordered_map<int, int>::iterator pre;
		if (m.size() == cap && m.find(key) == m.end())
		{
			//unordered_map<int, int>::iterator it;
			m.erase(m.begin());

		}
		m.erase(key);
		m.insert(pair<int, int>(key, value));

	}
private:
	int cap;
	unordered_map<int, int> m;
};

void main1111()
{
	LRUCache cache(2) ;

	cache.put(1, 1);
	cache.put(2, 2);
//	cache.put(6, 6);
	cache.put(1, 9);
	cache.put(3, 3);
	cout << cache.get(1) << endl;       // returns 1
	//cache.put(3, 3);    // evicts key 2
	cout << cache.get(3) << endl;       // returns -1 (not found)
	cout << cache.get(2) << endl;
	cache.put(4, 4);    // evicts key 1
	cout << cache.get(1) << endl;       // returns -1 (not found)
	cout << cache.get(3) << endl;       // returns 3
	cout << cache.get(2) << endl;
	cout << cache.get(4) << endl;       // returns 4

	system("pause");
}
