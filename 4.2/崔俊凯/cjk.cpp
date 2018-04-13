#include<iostream>
using namespace std;
#define size 100
#define add 10
template <class T>
class list
{
private:

	T * date; // ���˳����е�Ԫ��

	int length; // ���˳���ĳ���

	int listsize;
public:

	list();// ���캯������Ҫ��������ڴ�ռ�����룩

	~list();// �����������������飩

	void DispList(); // ���˳���L�е�����Ԫ��

	int ListLength(); // ��˳���ĳ���

	bool GetElem(int i, T &e); // ��˳�����ĳ���кŵ�Ԫ��ֵ

	int LocateElem(T e); // ��Ԫ�ز������һ�����λ��

	bool ListInsert(int i, T e); // ��λ��i��������Ԫ��e

	bool ListDelete(int i); // ��λ��iɾ������Ԫ��

};
template <class T>
list<T >::list()// ���캯������Ҫ��������ڴ�ռ�����룩
{
	date = new T[size];
	if (date==NULL)
		cout << "over" << "\n";
	length = 0;
	listsize = size;
}

template <class T>
list<T >::~list()// �����������������飩
{
	if (date != NULL)
	{
		delete[] date;
		date = NULL;
		length = 0;
		listsize = 0;
	}
}

template <class T>
void list<T >::DispList()// ���˳���L�е�����Ԫ��
{
	int i = 0;
	for (i = 0; i < length; i++)
		cout << date[i] << "\n";
}
template <class T>
bool list<T >::ListInsert(int i, T e)// ��λ��i��������Ԫ��e
{
	T *p, *q;
	if (i<1 || i>length + 1)
		return false;
	q = &(date[i - 1]);
	p = &(date[length - 1]);
	for (p; p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	length++;
	return true;
}

template <class T>
bool list<T >::ListDelete(int i)// ��λ��iɾ������Ԫ��
{
	T *p, *q;
	if (i<1 || i>length)
		return false;
	p = &(date[i - 1]);
	q = date + lemgth - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	length--;
	return true;
}

template <class T>
int list<T >::LocateElem(T e) // ��Ԫ�ز������һ�����λ��
{
	int i;
	for (i = 0; i < length - 1; i++)
		if (date[i] == e)
			return i + 1;
	return -1;

}

template <class T>
bool list<T >::GetElem(int i, T &e)// ��˳�����ĳ���кŵ�Ԫ��ֵ
{
	if (i<1 || i>length)
		return false;
	else
		e = &(date[i - 1])
		return true;

}
