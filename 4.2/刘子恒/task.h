#include<iostream>
#define MAXSIZE 100
using namespace std;
template<class T>
class test
{
private:
        T *data; // 存放顺序表中的元素

        int length; // 存放顺序表现在的长度

public:
        test();// 构造函数（需要完成数组内存空间的申请）

        ~test();// 析构函数（销毁数组）

        void DispList(); // 输出顺序表L中的所有元素

        int ListLength(); // 求顺序表的长度

        bool GetElem(int i, T &e); // 求顺序表中某序列号的元素值

        int LocateElem(T e); // 按元素查找其第一个序号位置

        bool ListInsert(int i, T e); // 在位置i插入数据元素e

        bool ListDelete(int i); // 在位置i删除数据元素
};
template <class T>
test<T>::test()
{
	data=new T[MAXSIZE];
	length=0;
}
template <class T>
test<T>::~test()
{
	delete []data;
}
template <class T>
void test<T>::DispList()
{
	int j;
	for(j=0;j<1;j++)
	{
		cout<<data[j]<<" ";
	}
	cout<<endl;
	length=j;
}
template <class T>
int test<T>::ListLength()
{
	return length;
}
template <class T>
bool test<T>::GetElem(int i, T &e)
{
	int j;
	for(j=0;j<length;j++)
	{
		if(j+1==i)
			if(data[j+1]==e)
				return true;
	}
	return false;
}
template <class T>
int test<T>::LocateElem(T e)
{
	int i;
	for(i=0;i<length;i++)
	{
		if(data[i]==e)
			break;
	}
	return i+1;
}
template <class T>
bool test<T>::ListInsert(int i, T e)
{
	int j,t;
	if(i<=MAXSIZE)
	{
		for(j=i-1;j<=length;j++)
		{
			if(j==i-1)
			{
				t=data[j];
				data[j]=e;
				data[j+1]=t;
			}
			else
			{
				t=data[j];
				data[j]=data[j+1];
				data[j+1]=t;
			}
		}
		length++;
		return true;
	}
	else
		return false;
}
template <class T>
bool test<T>::ListDelete(int i)
{
	int j=0,k=0;
	for(j=0;j<length;j++)
	{
		if(j==i)
		{
			for(k=j;k<length-1;k++)
			{
				data[k]=data[k-1];
			}
			length--;
			return true;
		}
	}
	if(k==0)
	{
		return false;
	}
}

