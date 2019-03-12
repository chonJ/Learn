#include<iostream>
#include<stack>
using namespace std;

class MinStack_Twostacks {
public:
	/** initialize your data structure here. */
	MinStack_Twostacks() {

	}

	void push(int x) {
		s1.push(x);
		if (s2.size() == 0 ||x <= s2.top())
			s2.push(x);
	}

	void pop() {
		if (s1.top() == s2.top())
			s2.pop();
		s1.pop();
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}
private:
	stack<int> s1;
	stack<int> s2;
};
class MinStack {//只用一个栈 但每次 压入两个 先压此时的min 然后再压要压的值

				//更节省空间的  如下 再每次压入的新值为最小值时先压入一个 之前的 min 为pop后更新min用
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		if (x <= min)
		{
			s1.push(min);
			min = x;
		}
		s1.push(x);
	}

	void pop() {
		// if pop operation could result in the changing of the current minimum value, 
		// pop twice and change the current minimum value to the last minimum value.
		if (s1.top() == min)
		{
			s1.pop();
			min = s1.top();
			s1.pop();
		}
		else
			s1.pop();
		
		
		

	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return min;
	}
private:
	stack<int> s1;
	int min = INT_MAX;
};
void main_Min_Stack()
{
	MinStack minStack ;
	minStack.push(2);
	minStack.push(3);
	minStack.push(1);
	cout << minStack.getMin() << endl;   //-- > Returns - 3.
	minStack.pop();
	//cout << minStack.top() << endl;      //-- > Returns 0.
	cout << minStack.getMin() << endl;  // -- > Returns - 2.
	system("pause");
}