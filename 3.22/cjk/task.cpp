#include <iostream>
#include<string.h>
using namespace std;
class teacher
{
	public:
		teacher(string n,string m,string x) 
		{
			tea=n;
			ming=m;
			hong=x;
		}
		void sum()
		{
			cout<<"��Һã��ҵ����ֽ�"<<tea<<"\n";
			cout<<"�ҵ�ѧ����"<<ming<<"��"<<hong<<"\n"; 
		}
		void sum(int a)
		{
			cout<<"�ҵ������ǽ�"<<a<<"����"<<"\n"; 
		 } 
		int suun()
		{
				return a[i++];
			
		}
		
		string tea;
		string ming;
		string hong;
		int a[4]={2,1,3,4};
		int i=0;
}; 
class xiaoming:public teacher
{
	public:
		xiaoming(int a,string n,string m,string x):teacher(n,m,x)
		{
			age=a;
			na=n;
		}
		void sum(int a)
		{
			n[i]=a;
			i++;
		}
		void putnum()
		{
			cout<<"�ҽ�"<<na<<"\n";
			cout<<"�ҽ���"<<age<<"����"<<"\n"; 
		}
		void sort()
			{
				for(i=1;i<4;i++)
					for(j=0;j<4-i;j++)
						if(n[j]>n[j+1])
						{
							t=n[j];
							n[j]=n[j+1];
							n[j+1]=t;
						}
				for(i=0;i<4;i++)
				{
					printf("%d",n[i]);
				}
				printf("\n");
		
			}
		int i=0,j,t;
		int n[4];
		int age;
		string na;
};
class xiaohong:public teacher
{
	public:
		xiaohong(int a,string n,string m,string x):teacher(n,m,x)
		{
			age=a;
			na=n;
		}
		void sum(int a)
		{
			n[i]=a;
			i++;
		}
		void putnum()
		{
			cout<<"�ҽ�"<<na<<"\n";
			cout<<"�ҽ���"<<age<<"����"<<"\n"; 
		}
		void sort()
			{
				for(i=1;i<4;i++)
					for(j=0;j<4-i;j++)
						if(n[j]>n[j+1])
						{
							t=n[j];
							n[j]=n[j+1];
							n[j+1]=t;
						}
				for(i=0;i<4;i++)
				{
					printf("%d",n[i]);
				}
				printf("\n"); 
			}
		int i=0,j,t;
		int n[4];
		int age;
		string na;
};
int main() 
{	
	int i;
	int a=2134;
	teacher tea("������","С��","С��");
	xiaoming ming(6,"С��","","");
	xiaohong hong(7,"С��","","");
	printf("С���С��������ѧУ\n");
	tea.sum();
	tea.sum(a);
	ming.putnum();
	for(i=0;i<4;i++)
	{
		ming.sum(tea.suun());
	}
	ming.sort();
	hong.putnum();
	for(i=0;i<4;i++)
	{
		hong.sum(tea.suun());
	}
	hong.sort();
	return 0;
}
