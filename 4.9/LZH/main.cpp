#include "task.h"

int main()
{
	Stack s;
	int a;
	cout<<"����ʮ��Ԫ�ش���ջ:"<<endl;
	for(int i=0;i<10;i++)
	{
		cin>>a;
		s.in(a);
	}
	cout<<"��ʱջ����:"<<s.top1();
	cout<<"\n��ջ:"<<s.out();
	cout<<"\n��ʱջ����:"<<s.top1();
	cout<<"\n��ջ:"<<s.out();
	cout<<"\n��ӡȫ��:";
	while(!s.empty())
	{
		cout<<s.out()<<"  ";
	}
	cout<<endl;
	return 0;
}