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
			cout<<"\n��ҵ��"<<endl;
			cout<<"��ѡ�2314����˳������"<<endl;
			cout<<"���ѡ�acbd����˳������"<<endl;
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
	cout<<xm.name<<"����ȥ��ѧ"<<endl;
	student xh;
	xh.name="Xiao Hong";
	cout<<xh.name<<"����ȥ��ѧ"<<endl;
	teacher a;
	cout<<xm.name<<xh.name<<"������ʦ��������ҵ"<<endl;
	a.task();
	cout<<xm.name<<"��󽻵���ҵ��:"<<endl;
	xm.homework1(a.blackboard1());
	xm.homework2(a.blackboard2());
	cout<<endl;
	cout<<xh.name<<"��󽻵���ҵ��:"<<endl;
	xh.homework1(a.blackboard1());
	xh.homework2(a.blackboard2());
	cout<<"�����˶��������ҵ"<<endl;
	return 0;	
}


