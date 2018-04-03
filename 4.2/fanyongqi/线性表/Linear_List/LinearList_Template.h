#pragma once

#include<iostream>
using namespace std;
#define ture  1
#define false 0 
int  MaxSize = 100;
template <class T>
class LinearList {
private:

	T * data;   // 存放顺序表中的元素
	int length; // 存放顺序表的长度

public:

	LinearList();                       // 构造函数（需要完成数组内存空间的申请）
	~LinearList();                       // 析构函数（销毁数组）
	void   CreateList(T a[], int n);           // 创建LinearList
	void   DispList();                         // 输出顺序表L中的所有元素
	int    ListLength();                       // 求顺序表的长度
	bool   GetElem(int i, T &e);               // 求顺序表中某序列号的元素值
	int    LocateElem(T e);                    // 按元素查找其第一个序号位置
	bool   ListInsert(int i, T e);             // 在位置i插入数据元素e
	bool   ListDelete(int i);                  // 在位置i删除数据元素

};
template<class T>//构造函数
LinearList<T>::LinearList()
{
	data = new T[MaxSize];
	length = 0;
}
template<class T>//析构函数
LinearList<T>::~LinearList()
{
	delete[] data;
}
template<class T>//创建线性表
void LinearList<T>::CreateList(T a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		data[i] = a[i];

	length = i;
}
template<class T>//输出线性表
void LinearList<T>::DispList()
{
	cout << "this is LinearLiat\n";

	for (int i = 0; i < length; i++)
		cout << data[i] << endl;
}
template<class T>//输出表长度
int LinearList<T>::ListLength()
{
	return length;
}
template<class T>//输出表元素值
bool LinearList<T>::GetElem(int i, T &e) {
	if (i<0 || i>length)
		return false;

	e = data[i - 1];
	return true;
}
template<class T>//按元素查找其第一个序号位置
int LinearList<T>::LocateElem(T e) {
	for (int i = 0; i < length&&data[i] != e; i++)
		if (i > length)
			return false;
		else
			return i + 1;
}
template<class T>// 在位置i插入数据元素e
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
template<class T> // 在位置i删除数据元素
bool LinearList<T>::ListDelete(int i)
{
	if (i<0 || i>length)
		return false;
	for (int j = i - 1; j < length; j++)
		data[j] = data[j + 1];

	length--;
	return true;
}
