#include<iostream>
#include<string>
using namespace std;

void sort(int a[4])
{
	int i,j,t;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<4;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<4;i++)
	cout<<a[i];
	cout<<endl;
}
void sort(char b[4])
{
	int i,j,t;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<4;j++)
		{
			if(b[i]>b[j])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
	for(i=0;i<4;i++)
	cout<<b[i];
	cout<<endl;
}
class person
{
	public :
		string name;
};
class teacher :public person
{
	private :
		int a[4]={2,3,1,4};
		char b[4]={'a','c','b','d'};
	public :
		void task()
		{
			cout<<"\n作业："<<endl;
			cout<<"请把“2314”按顺序排序"<<endl;
			cout<<"并把“acbd”按顺序排序"<<endl;
		}
		int* blackboard1()
		{
			return a;
		}
		char* blackboard2()
		{
			return b;
		}
};
class student :public person
{
	public :
		int homework1(int *a)
		{
			sort(a);
		}
		char homework2(char b[4])
		{
			sort(b);
		}
};
int main()
{
	student xm;
	xm.name="Xiao Ming";
	cout<<xm.name<<"现在去上学"<<endl;
	student xh;
	xh.name="Xiao Hong";
	cout<<xh.name<<"现在去上学"<<endl;
	teacher a;
	cout<<xm.name<<xh.name<<"发现老师留下了作业"<<endl;
	a.task();
	cout<<xm.name<<"最后交的作业是:"<<endl;
	xm.homework1(a.blackboard1());
	xm.homework2(a.blackboard2());
	cout<<endl;
	cout<<xh.name<<"最后交的作业是:"<<endl;
	xh.homework1(a.blackboard1());
	xh.homework2(a.blackboard2());
	cout<<"两个人都完成了作业"<<endl;
	return 0;	
}


