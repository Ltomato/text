#include<iostream>
#include"task.h"
using namespace std;
int main()
{
	stack exp;
	int i=0;
	for(i=0;i<3;i++)
	{
		exp.Push(i);
	}
	for(i=0;i<3;i++)
	{
		if(!exp.Empty())
		{
			cout<<exp.Pop()<<endl;
		}
	}
	return 0;
}

