#pragma once

#include<iostream>
using namespace std;
#define ture  1
#define false 0 
int  MaxSize = 100;
template <class T>
class LinearList {
private:

	T * data;   // ���˳����е�Ԫ��
	int length; // ���˳���ĳ���

public:

	LinearList();                       // ���캯������Ҫ��������ڴ�ռ�����룩
	~LinearList();                       // �����������������飩
	void   CreateList(T a[], int n);           // ����LinearList
	void   DispList();                         // ���˳���L�е�����Ԫ��
	int    ListLength();                       // ��˳���ĳ���
	bool   GetElem(int i, T &e);               // ��˳�����ĳ���кŵ�Ԫ��ֵ
	int    LocateElem(T e);                    // ��Ԫ�ز������һ�����λ��
	bool   ListInsert(int i, T e);             // ��λ��i��������Ԫ��e
	bool   ListDelete(int i);                  // ��λ��iɾ������Ԫ��

};
template<class T>//���캯��
LinearList<T>::LinearList()
{
	data = new T[MaxSize];
	length = 0;
}
template<class T>//��������
LinearList<T>::~LinearList()
{
	delete[] data;
}
template<class T>//�������Ա�
void LinearList<T>::CreateList(T a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		data[i] = a[i];

	length = i;
}
template<class T>//������Ա�
void LinearList<T>::DispList()
{
	cout << "this is LinearLiat\n";

	for (int i = 0; i < length; i++)
		cout << data[i] << endl;
}
template<class T>//�������
int LinearList<T>::ListLength()
{
	return length;
}
template<class T>//�����Ԫ��ֵ
bool LinearList<T>::GetElem(int i, T &e) {
	if (i<0 || i>length)
		return false;

	e = data[i - 1];
	return true;
}
template<class T>//��Ԫ�ز������һ�����λ��
int LinearList<T>::LocateElem(T e) {
	for (int i = 0; i < length&&data[i] != e; i++)
		if (i > length)
			return false;
		else
			return i + 1;
}
template<class T>// ��λ��i��������Ԫ��e
bool LinearList<T>::ListInsert(int i, T e)
{
	int j = length;
	if (i < 0 || i>length)
		return false;
	for (j; j >= i; j--)
		data[j] = data[j - 1];

	data[i - 1] = e;
	length++;
	return ture;
}
template<class T> // ��λ��iɾ������Ԫ��
bool LinearList<T>::ListDelete(int i)
{
	if (i<0 || i>length)
		return false;
	for (int j = i - 1; j < length; j++)
		data[j] = data[j + 1];

	length--;
	return true;
}
