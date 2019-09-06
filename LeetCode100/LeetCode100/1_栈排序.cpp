#include<iostream>
#include<stack>
using namespace std;

//栈排序

stack<int> sorting(stack<int> myStack)
{
	stack<int> result;//输出栈

	if (myStack.empty())
		return result;
	int tmp = myStack.top();//tmp记录的是下一个要插入到result栈中的数

	myStack.pop();

	while (!myStack.empty() || (!result.empty() && result.top() > tmp))
	{
		if (result.empty() || result.top() <= tmp)
		{
			result.push(tmp);
			tmp = myStack.top();
			myStack.pop();
		}
		else
		{
			myStack.push(result.top());
			result.pop();
		}
	}
	result.push(tmp);
	return result;
}