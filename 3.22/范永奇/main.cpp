#include<iostream>
#include<string>
using namespace std;

class School{
	public:
		void SchoolName(){
		cout<<"������"<<name<<"�׶�԰��һ����\n"<<endl; 
		}
		void SchoolEnviorment(){
		cout<<"����"<<door<<"��"<<plant<<"��"<<flower; 
		}
	private:
			string name    ="���ﻨ��";
			string door    ="����";
			string building="��¥";
			string plant   ="����";
			string flower  ="�¼�"; 
 };


 class teacher:public School{
 	private:
 		int age =25;
 		string name="�ֻ���";
		string sex="Ů";
	public:
		int  num[4]={2,3,1,4};
		char word[4]={'a','c','b','d'};
	void information()
	{
 	cout<<"����"<<name<<"��ʦ\n"<<endl;
	cout<<"����"<<sex<<"��\n"<<endl; 
	cout<<"�Ҵ��㲼����ҵ��ѧ������\n"<<endl; 
	cout<<"�Ҿͳ��������������������\n\n\n"<<endl; 
 }
	int*  trannum(){
 		return num;}
		 	
	char* tranchar(){
 		return word;}
};
 

 class student :public School{
 	public:
 			void virtual sort(){	
			 };
			void virtual way(){	
		  	 };
		  	 void display(){
		  	 	cout<<"place"<<"��ѧУ�ķ�λ"<<endl; 
			   }
	protected:
	string place="����·";
 };
 

 class student1:public student{
 	private:
 			string name="С��";
			string face="˧";
			int age=6;
	public:
			void information();
			void way();
			void sortnum (int *p);
			void sortchar(char*p);
 };
 void student1::information(){
 	cout<<name<<"����"<<"�Һ�"<<face<<"\n�ҽ���"<<age<<"��\n"<<endl;
	cout<<"�Ҵ�����ѧȥ\n"<<endl; 
 } 
 void student1::way(){
 	cout<<"�Ҵ���ȭ·����\n"<<endl;
	cout<<"�ҵ��˱���·\n"<<endl;
	cout<<"�ҿ������ҵ�ѧУ--���ﻨ���׶�԰\n"<<endl; 
 }
 void  student1::sortnum(int *p){
 	int i,j,temp;
 	int a[4];
 	cout<<"�յ�����\n"<<endl; 
 	for( i=0;i<4;i++){
 		a[i]=*p;
 		p++;
	 }
	 for(i=0;i<4;i++){
	 	for(j=0;j<4-i;j++)
	 	{
	 		if(a[i]>a[i+1])
	 		a[i]=temp;
	 		a[i]=a[i+1];
	 		a[i+1]=temp;
		 }
	 }
 	for(i=0;i<4;i++)
 	cout<<a[i];
	cout<<"��С���������������\n"<<endl; 
 } 
 void student1::sortchar(char*p){
 		int i,j,temp;
 	char arr[4];
 	for( i=0;i<4;i++){
 		arr[i]=*p;
 		p++;
	 }
	 for(i=0;i<4;i++){
	 	for(j=0;j<4-i;j++)
	 	{
	 		if(arr[i]>arr[i+1])
	 		arr[i]=temp;
	 		arr[i]=arr[i+1];
	 		arr[i+1]=temp;
		 }
	 }
 	for(i=0;i<4;i++)
 	cout<<arr[i];
	cout<<"��С��������ַ�����\n"<<endl; 
	}

 
 class student2:public student{
 	private:
 			string name="С��";
 			string face="��";
			int age=6; 
			public:
				void information();
				void way();
				void sortnum(int *p);
				void sortchar(char*p);
				
 };
 
 void student2::information(){
 	cout<<"����"<<name <<"\n�ҽ���"<<age<<"����\n"<<endl;
	cout<<"��׼��ȥ��ѧ\n"<<endl; 
 }
 void student2::way(){
 	cout<<"�ҴӶ���·����"<<"��Ҫ��������·\n"<<endl;
	cout<<"�ҿ������ҵ�ѧУ--���ﻨ���׶�԰\n"<<endl; 
 }
 void student2::sortnum(int *p){
 	int i,j,t;
 	int a1[4];
 	cout<<"�յ�����\n"<<endl; 
 	for( i=0;i<4;i++){
 		a1[i]=*p;
 		p++;
	 }
    for ( i = 0; i <4; i ++ )
    for ( j = i + 1; j < 4; j ++)
    if (a1[i]>a1[j]) {
	t=a1[i]; a1[i] =a1[j];
	a1[j]=t;}
    for(i=0;i<4;i++)
    cout<<a1[i];
    cout<<"��С���������������\n"<<endl;
 }
    
void student2::sortchar(char*p){
		int i,j,temp;
 	char arr1[4];
 	for( i=0;i<4;i++){
 		arr1[i]=*p;
 		p++;
	 }
	 for(i=0;i<4;i++){
	 	for(j=0;j<4-i;j++)
	 	{
	 		if(arr1[i]>arr1[i+1])
	 		arr1[i]=temp;
	 		arr1[i]=arr1[i+1];
	 		arr1[i+1]=temp;
		 }
	 }
 	for(i=0;i<4;i++)
 	cout<<arr1[i];
 	cout<<"��С��������ַ�����\n"<<endl; 
 	cout<<"\n";
}
    
 int main(){
 	
 	student1   xiaoming;
 	student2   xiaohong;
 	teacher    linhuiyin;
 	
 	xiaoming.information();
	xiaoming.way();
 	
 	xiaohong.information();
 	xiaohong.way();
 	
 	linhuiyin.information();
 	
	xiaoming.sortnum (linhuiyin.trannum());
	xiaoming.sortchar(linhuiyin.tranchar());
	
 	xiaohong.sortnum (linhuiyin.trannum());
 	xiaohong.sortchar(linhuiyin.tranchar());
 	
 	return 0;
 }
