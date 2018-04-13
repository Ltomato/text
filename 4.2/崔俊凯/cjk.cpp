#include<iostream>
using namespace std;
#define size 100
#define add 10
template <class T>
class list
{
private:

	T * date; // 存放顺序表中的元素

	int length; // 存放顺序表的长度

	int listsize;
public:

	list();// 构造函数（需要完成数组内存空间的申请）

	~list();// 析构函数（销毁数组）

	void DispList(); // 输出顺序表L中的所有元素

	int ListLength(); // 求顺序表的长度

	bool GetElem(int i, T &e); // 求顺序表中某序列号的元素值

	int LocateElem(T e); // 按元素查找其第一个序号位置

	bool ListInsert(int i, T e); // 在位置i插入数据元素e

	bool ListDelete(int i); // 在位置i删除数据元素

};
template <class T>
list<T >::list()// 构造函数（需要完成数组内存空间的申请）
{
	date = new T[size];
	if (date==NULL)
		cout << "over" << "\n";
	length = 0;
	listsize = size;
}

template <class T>
list<T >::~list()// 析构函数（销毁数组）
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
void list<T >::DispList()// 输出顺序表L中的所有元素
{
	int i = 0;
	for (i = 0; i < length; i++)
		cout << date[i] << "\n";
}
template <class T>
bool list<T >::ListInsert(int i, T e)// 在位置i插入数据元素e
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
bool list<T >::ListDelete(int i)// 在位置i删除数据元素
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
int list<T >::LocateElem(T e) // 按元素查找其第一个序号位置
{
	int i;
	for (i = 0; i < length - 1; i++)
		if (date[i] == e)
			return i + 1;
	return -1;

}

template <class T>
bool list<T >::GetElem(int i, T &e)// 求顺序表中某序列号的元素值
{
	if (i<1 || i>length)
		return false;
	else
		e = &(date[i - 1])
		return true;

}
