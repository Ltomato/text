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
			cout<<"大家好，我的名字叫"<<tea<<"\n";
			cout<<"我的学生是"<<ming<<"和"<<hong<<"\n"; 
		}
		void sum(int a)
		{
			cout<<"我的任务是将"<<a<<"排序"<<"\n"; 
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
			cout<<"我叫"<<na<<"\n";
			cout<<"我今年"<<age<<"岁了"<<"\n"; 
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
			cout<<"我叫"<<na<<"\n";
			cout<<"我今年"<<age<<"岁了"<<"\n"; 
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
	teacher tea("吴丽娟","小明","小红");
	xiaoming ming(6,"小明","","");
	xiaohong hong(7,"小红","","");
	printf("小红和小明到达了学校\n");
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
