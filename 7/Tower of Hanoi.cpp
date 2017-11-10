#include<iostream>
#include<stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void moveDisk(int disk,stack<int>& source,stack<int>& helper,stack<int>& distination)
{
	if (disk < 1)
		return;

	moveDisk(disk-1, source, distination, helper);
	int curr = source.top();
	source.pop();
	distination.push(curr);
	moveDisk(disk - 1, helper, source, distination);

}
int main()
{

	stack<int> stackOne,b,c;
	stackOne.push(3);
	stackOne.push(2);
	stackOne.push(1);
	moveDisk(3, stackOne, b, c);

	system("pause");
	return 0;
}
