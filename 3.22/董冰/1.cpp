#include<iostream>
#include<string>
using namespace std;
class people
{
	public:
		string name;
			
} ;
class teacher:public people
{
	public:
		void task();
};
class student:public people
{
	public:
		void sort();
};

void teacher::task()
{
	cout<<"��ҵ�����2 1 4 3����"<<endl; 
}
void student::sort()
{
	int a[4]={2,1,4,3};
	int i,j,t;
	for(j=0;j<4;j++)
		for(i=0;i<4-j;i++)
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
	for(i=0;i<4;i++)
		cout<<a[i]<<endl;
} 
int main()
{
	teacher wu;
	wu.task();
	cout<<"xioming���õ���ҵ��"<<endl; 
	student xiaoming;
	xiaoming.sort();
	cout<<"xiaohong���õ���ҵ��"<<endl;
	student xiaohong;
	xiaohong.sort();
	cout<<"�����˶�������"<<endl;
	getchar();
	return 0;
	
}
