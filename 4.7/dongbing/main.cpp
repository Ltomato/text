#include<iostream>
#include<string>
#include"Linklist.h"
using namespace std;
int main()
{
	Linklist head;
	info a1,a2,a3,a4;
	a1.id=1;
	a1.name="dongbing";
	a2.id=2;
	a2.name="liuziheng";
	a3.id=3;
	a3.name="fanyongqi";
	a4.id=4;
	a4.name="cuijunkai";
	
	cout<<"Insert test:"<<endl;
	head.Insert(a2,1);
	head.Print();
	head.Insert(a3,4);
	head.Print();
	head.Insert(a4,2);
	head.Print();
	
	cout<<"remove test:"<<endl;
	cout<<"the length of Linklist is:"<<endl;
	cout<<head.Length()<<endl;
	head.Delete(a4);
	head.Print();
	return 0;
	
	
}
