#include<iostream>
#include<stack>
using namespace std;

void insertElement(stack<int>&, int);
void iterStack(stack<int> &myStack)
{
	int element;
	if (myStack.size())
	{
		element = myStack.top();
		myStack.pop();
		iterStack(myStack);
		insertElement(myStack, element);
	}
}

void insertElement(stack<int> &myStack, int element)
{
	if (!myStack.empty())
	{
		if (element>myStack.top())
		{
			int current = myStack.top();
			myStack.pop();
			insertElement(myStack, element);
			myStack.push(current);
		}
		else{
			myStack.push(element);
		}
	}
	else{
		myStack.push(element);
	}
}

void print(stack<int> &myStack)
{
	while (!myStack.empty())
	{
		cout << myStack.top() << endl;
		myStack.pop();
	}

}
int main()
{

	stack<int> mystack;
	mystack.push(6);
	mystack.push(3);
	mystack.push(8);
	mystack.push(1);

	//insertElement(mystack, 6);
	//insertElement(mystack, 3);
	//insertElement(mystack, 8);
	//insertElement(mystack, 1);
	iterStack(mystack);
	print(mystack);

	return 0;

}
