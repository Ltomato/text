#include<iostream>
#define MAXSIZE 100
using namespace std;
template<class T>
class test
{
private:
        T *data; // ���˳����е�Ԫ��

        int length; // ���˳������ڵĳ���

public:
        test();// ���캯������Ҫ��������ڴ�ռ�����룩

        ~test();// �����������������飩

        void DispList(); // ���˳���L�е�����Ԫ��

        int ListLength(); // ��˳���ĳ���

        bool GetElem(int i, T &e); // ��˳�����ĳ���кŵ�Ԫ��ֵ

        int LocateElem(T e); // ��Ԫ�ز������һ�����λ��

        bool ListInsert(int i, T e); // ��λ��i��������Ԫ��e

        bool ListDelete(int i); // ��λ��iɾ������Ԫ��
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

