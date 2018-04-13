#include<iostream>
using namespace std; 
#define maxsize  100
template<class T>
class task
{
	private:
        T *data; // ���˳����е�Ԫ��
        int length; // ���˳������ڵĳ���

    public:
        task();// ���캯������Ҫ��������ڴ�ռ�����룩
        ~task();// �����������������飩
        void DispList(); // ���˳���L�е�����Ԫ��
        int ListLength(); // ��˳���ĳ���
        bool GetElem(int i, T &e); // ��˳�����ĳ���кŵ�Ԫ��ֵ
        int LocateElem(T e); // ��Ԫ�ز������һ�����λ��
        bool ListInsert(int i, T e); // ��λ��i��������Ԫ��e
        bool ListDelete(int i); // ��λ��iɾ������Ԫ��


}; 
template<class T>
task<T>::task()
{
	length=0;
	data=new T[maxsize];		
}
template<class T>
task<T>::~task()
{
	delete [] data;
}
template<class T>
void task<T>:: DispList()
{
	int j;
	cout<<"�������ŵ�Ԫ��"<<endl; 
	for(j=0;j<10;j++)
	{
		cin>>data[j]>>endl;
		length++;
	}
	cout<<"�����Ԫ��Ϊ"<<endl;
	for(j=0;j<length-1;j++)
		cout<<data[j]<<" ";
	cout<<endl;
		
			
}
template<class T>
int task<T>:: ListLength()
{
	cout<<"����Ϊ��"<<endl;
	return length;	
}
template<class T>
bool task<T>::GetElem(int i, T &e)
{
	if(data[i]==e)
		return true;
	else
		return false;	
}
template<class T>
int task<T>::LocateElem(T e)
{
	int i;
	for(i=0;i<length;i++)
		{
			if(length==data[i])
				{
					e=i;
					return true;	
				}	
		}
	return false;	
}
template<class T>
bool task<T>::ListInsert(int i, T e)
{
	cout<<"��Ԫ��"<<e<<"���뵽λ��"<<i<<endl;
	int j;
	if(i<1||i>length+1)
		return false;
	if(length=10)
		return false;
	for(j=length-1;j>=i;j--)
		data[j+1]=data[j];
	data[i]=e;
	length++;
	cout<<"����ɹ�"<<endl;
	return true;
}
template<class T>
bool task<T>::ListDelete(int i)
{
	cout<<"��λ��Ϊ"<<i<<"��Ԫ��ɾ��"<<endl;
	int j;
	if(i<1||i>length)
		cout<<"���������Ԫ��"<<endl;
	for(j=i;j<=length-1;j++)
		data[j]=data[j+1];
	length--;
	cout<<"ɾ���ɹ�"<<endl;
	return true;	
	
}

