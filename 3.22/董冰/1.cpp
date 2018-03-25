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
	cout<<"作业是请给2 1 4 3排序"<<endl; 
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
	cout<<"xioming做好的作业是"<<endl; 
	student xiaoming;
	xiaoming.sort();
	cout<<"xiaohong做好的作业是"<<endl;
	student xiaohong;
	xiaohong.sort();
	cout<<"两个人都做对了"<<endl;
	getchar();
	return 0;
	
}
