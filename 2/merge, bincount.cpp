#include <iostream>
#include<stack>
#include<string>
#include<queue>
using namespace std;

//reverse stack with recursion
template<typename T>
void insert_bottom(stack<T>& st, T& el)
{
	if (st.empty()) st.push(el);
	else
	{
		T temp = st.top(); st.pop();
		insert_bottom(st, el);
		st.push(temp);
	}
}
template<typename T>
void reverse_stack(stack<T>& st)
{
	if (!st.empty())
	{
		T temp = st.top(); st.pop();
		reverse_stack(st);
		insert_bottom(st,temp);
	}
}


//merge st2 and st1 to st1
void insert(stack<int>& st, int x)
{
    if(st.empty() || st.top()<= x)
    {
        st.push(x);
    }
    else
    {
        int temp = st.top(); st.pop();
        insert(st, x);
        st.push(temp);
    }
}
void merge(stack<int>& st1, stack<int>& st2)
{
    while(!st2.empty())
    {
        insert(st1, st2.top());
        st2.pop();
    }
}



void bin_count(int n)
{
	queue<string> helper;
	helper.push("1");
	while(n)
	{
		string front = helper.front();
		helper.pop();
		cout<<front<<endl;
		helper.push(front+"0");
		helper.push(front+"1");
		n--;
	}
}

int main() {
	
	return 0;
}
