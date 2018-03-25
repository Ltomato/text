#include<iostream>
#include<string>
using namespace std;

class School{
	public:
		void SchoolName(){
		cout<<"我们是"<<name<<"幼儿园的一份子\n"<<endl; 
		}
		void SchoolEnviorment(){
		cout<<"进入"<<door<<"有"<<plant<<"和"<<flower; 
		}
	private:
			string name    ="春田花花";
			string door    ="大门";
			string building="大楼";
			string plant   ="大树";
			string flower  ="月季"; 
 };


 class teacher:public School{
 	private:
 		int age =25;
 		string name="林徽因";
		string sex="女";
	public:
		int  num[4]={2,3,1,4};
		char word[4]={'a','c','b','d'};
	void information()
	{
 	cout<<"我是"<<name<<"老师\n"<<endl;
	cout<<"我是"<<sex<<"的\n"<<endl; 
	cout<<"我打算布置作业给学生们做\n"<<endl; 
	cout<<"我就出两道排序题给你们做吧\n\n\n"<<endl; 
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
		  	 	cout<<"place"<<"是学校的方位"<<endl; 
			   }
	protected:
	string place="建设路";
 };
 

 class student1:public student{
 	private:
 			string name="小明";
			string face="帅";
			int age=6;
	public:
			void information();
			void way();
			void sortnum (int *p);
			void sortchar(char*p);
 };
 void student1::information(){
 	cout<<name<<"是我"<<"我很"<<face<<"\n我今年"<<age<<"岁\n"<<endl;
	cout<<"我打算上学去\n"<<endl; 
 } 
 void student1::way(){
 	cout<<"我从南拳路出发\n"<<endl;
	cout<<"我到了北腿路\n"<<endl;
	cout<<"我看到了我的学校--春田花花幼儿园\n"<<endl; 
 }
 void  student1::sortnum(int *p){
 	int i,j,temp;
 	int a[4];
 	cout<<"收到任务\n"<<endl; 
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
	cout<<"我小明完成了数字排序\n"<<endl; 
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
	cout<<"我小明完成了字符排序\n"<<endl; 
	}

 
 class student2:public student{
 	private:
 			string name="小红";
 			string face="美";
			int age=6; 
			public:
				void information();
				void way();
				void sortnum(int *p);
				void sortchar(char*p);
				
 };
 
 void student2::information(){
 	cout<<"我是"<<name <<"\n我今年"<<age<<"岁啦\n"<<endl;
	cout<<"我准备去上学\n"<<endl; 
 }
 void student2::way(){
 	cout<<"我从东土路出发"<<"我要到了西天路\n"<<endl;
	cout<<"我看到了我的学校--春田花花幼儿园\n"<<endl; 
 }
 void student2::sortnum(int *p){
 	int i,j,t;
 	int a1[4];
 	cout<<"收到任务\n"<<endl; 
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
    cout<<"我小红完成了数字排序\n"<<endl;
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
 	cout<<"我小红完成了字符排序\n"<<endl; 
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
