#include "task.h"
void main()
{
	test<int> A;
	int e=3;
	A.ListInsert(1, e);
	A.DispList();
	cout<<"��ʱ˳���ĳ���Ϊ:"<<A.ListLength()<<endl;
	cout<<"������Ԫ���Ƿ�Ϊ3"<<endl;
	if(A. GetElem(3,e))
		cout<<"��"<<endl;
	else
		cout<<"��"<<endl;
	cout<<"˳�����3��λ��"<<endl;
	if(A.LocateElem(e)==10)
		cout<<"���ҵ�Ԫ�ز�����"<<endl;
	else
		cout<<A.LocateElem(e)<<endl;
	cout<<"�ڵ�����λ��ɾ��"<<endl;
	if(A.ListDelete(3))
		cout<<"�ɹ�"<<endl;
	else
		cout<<"λ������"<<endl;
	cout<<"��ʱ˳���ĳ���Ϊ:"<<A.ListLength()<<endl;
}