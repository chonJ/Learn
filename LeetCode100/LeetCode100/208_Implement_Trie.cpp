#include<iostream>
#include<string>
#include<set>
using namespace std;

class Trie_my_bad {
public:
	/** Initialize your data structure here. */
	Trie_my_bad() {

	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		t.insert(word);
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		return t.find(word) != t.end();
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		int len = prefix.size();
		for (auto a : t)
		{
			if (a.size() < len)
				continue;
			int i;
			for ( i = 0; i <len; ++i)
			{
				if (a[i] != prefix[i])
					break;
			}
			if (i == len)
				return true;

		}
		return false;
	}
private:
	multiset<string> t;
};

// good solution
class TrieNode{
public:
	TrieNode *next[26];
	bool is_word;
	
	//初始化 initialize data structure 
	TrieNode(bool b = false)
	{
		memset(next, 0, sizeof(next));
		//memset(void *buffer, int c, int count)
		//buffer：为指针或是数组,
		//c：是赋给buffer的值,    一般只用于清零
		//count：是buffer的长度. 一般都是  sizeof()
		is_word = b;
	}
};
class Trie {
public:
	TrieNode *root;
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.size(); ++i)
		{
			if (p->next[word[i] - 'a'] == NULL)//如果之前没有这个字母 要新建个节点
				p->next[word[i] - 'a'] = new TrieNode();
			p = p->next[word[i] - 'a']; //跳到下一个
		}
		p->is_word = true; //标志是结束点
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode *p = find(word);
		return p != NULL && p->is_word;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		return  find(prefix) != NULL ;
	}
private:
	TrieNode* find(string word)
	{
		TrieNode *p = root;
		for (int i = 0; i < word.size() && p != NULL; ++i)
			p = p->next[word[i] - 'a'];
		return p;
	}
};
void main_Implement_Trie()
{
	Trie trie;

	//trie.insert("apple");
	//cout << trie.search("apple") << endl;   // returns true
	//cout << trie.search("app") << endl;     // returns false
	//cout << trie.startsWith("app") << endl; // returns true
	trie.insert("ab");
	trie.insert("ab");
	trie.insert("abc");

	cout << trie.startsWith("abc") << endl; // returns true

	//cout << trie.search("app") << endl;     // returns true
	system("pause");
}
