#include "task.h"

int main()
{
	Stack s;
	int a;
	cout<<"输入十个元素存入栈:"<<endl;
	for(int i=0;i<10;i++)
	{
		cin>>a;
		s.in(a);
	}
	cout<<"此时栈顶是:"<<s.top1();
	cout<<"\n出栈:"<<s.out();
	cout<<"\n此时栈顶是:"<<s.top1();
	cout<<"\n出栈:"<<s.out();
	cout<<"\n打印全部:";
	while(!s.empty())
	{
		cout<<s.out()<<"  ";
	}
	cout<<endl;
	return 0;
}