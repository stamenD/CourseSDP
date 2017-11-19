#include<iostream>
#include<stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char resolve(string exp)
{
	int len = exp.length(), i = 0;
	char result;
	if (!(len - 1)) return exp[i];
	stack<char> myStack;
	while (i < len)
	{
		char curr = exp[i];
		if (curr == '(') { i++; continue; }
		if (curr == ')')
		{
			curr = myStack.top();
			int el1 = atoi(&curr); myStack.pop();
			char op = myStack.top(); myStack.pop();
			int el2 = atoi(&myStack.top()); myStack.pop();
			(op=='@')? (myStack.push(char((el1 + el2) % 10) + 48)):(el1<el2 ? myStack.push(char(48+el1)) : myStack.push(char(48+el2)));
		}
		else{
			myStack.push(curr);
		}
		i++;
	}
	result = myStack.top();
	return result;
}







int main()
{

	//cout << resolve("(2@(3$4))") << endl;

	system("pause");
	return 0;
}
