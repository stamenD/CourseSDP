#include<iostream>
#include<stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool isNumber(char a)
{
	return ((int)a<=57 && (int)a>=48);
}

string compress(string exp)
{


	string result="";

	int len = exp.length(), i = 0;
	if (!(len - 1)) return exp;
	stack<char> stackDigit,stackSym;
	while (i < len)
	{
		char curr = exp[i];
		if (curr == ')')
		{
			int n = stackDigit.top() - 48;
			stackDigit.pop();
			string newSymbols = "";
			while (stackSym.top() != '(')
			{
				string help = "";
				help += stackSym.top();
				newSymbols.insert(0, help);
				stackSym.pop();
			}
			stackSym.pop();
			string final = "";
			for (int i = 0; i < n;i++)
		    final += newSymbols;

			for each (char var in final)
			{
				stackSym.push(var);
			} 
		}
		else if(isNumber(curr)){
			stackDigit.push(curr);
		}
		else{
	       stackSym.push(curr);
		}
		i++;
	}

	while (!stackSym.empty())
	{
		string help = "";
		help+=stackSym.top();
		result.insert(0,help);
		stackSym.pop();
	}

	return result;
}
int main()
{

	//string ans = compress("AB");
	//string ans = compress("3(AB)");
	//string ans = compress("3(AB2(B))");


	system("pause");
	return 0;
}
