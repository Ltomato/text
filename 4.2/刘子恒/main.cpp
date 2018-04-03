#include "task.h"
void main()
{
	test<int> A;
	int e=3;
	A.ListInsert(1, e);
	A.DispList();
	cout<<"此时顺序表的长度为:"<<A.ListLength()<<endl;
	cout<<"第三个元素是否为3"<<endl;
	if(A. GetElem(3,e))
		cout<<"是"<<endl;
	else
		cout<<"否"<<endl;
	cout<<"顺序表中3的位置"<<endl;
	if(A.LocateElem(e)==10)
		cout<<"查找的元素不存在"<<endl;
	else
		cout<<A.LocateElem(e)<<endl;
	cout<<"在第三个位置删除"<<endl;
	if(A.ListDelete(3))
		cout<<"成功"<<endl;
	else
		cout<<"位置有误"<<endl;
	cout<<"此时顺序表的长度为:"<<A.ListLength()<<endl;
}