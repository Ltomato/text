// Linear_List.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"LinearList_Template.h"

int main()
{
	int  FindElement, FindSpace;
	int  InsertElement, InsertSpace;
	int  DelSpace;
	int array[5] = { 0,1,2,3,4 };

	cout << "This is a LinearList of SequenceList" << endl;
	cout << "it  have 5 elemnts they're 0 1 2 3 4" << endl;
	cout << "please click keyboard to use it" << endl;
	cin >> DelSpace >> InsertSpace >> InsertElement;
	cin >> FindElement >> FindSpace;
	LinearList<int> L;
	L.CreateList(array, 5);
	L.DispList();
	L.ListLength();                           cout << "List length is " << L.ListLength() << endl;
	L.ListDelete(DelSpace);					  cout << "the delete result is" << L.ListDelete(DelSpace) << endl;
	L.ListInsert(InsertSpace, InsertElement); cout << "the insert result is" << L.ListInsert(InsertSpace, InsertElement) << endl;
	L.GetElem(FindElement, FindSpace);		  cout << "the space is" << L.GetElem(FindElement, FindSpace) << endl;

    return 0;
}

