#include<iostream>
using namespace std; 
#define maxsize  100
template<class T>
class task
{
	private:
        T *data; // 存放顺序表中的元素
        int length; // 存放顺序表现在的长度

    public:
        task();// 构造函数（需要完成数组内存空间的申请）
        ~task();// 析构函数（销毁数组）
        void DispList(); // 输出顺序表L中的所有元素
        int ListLength(); // 求顺序表的长度
        bool GetElem(int i, T &e); // 求顺序表中某序列号的元素值
        int LocateElem(T e); // 按元素查找其第一个序号位置
        bool ListInsert(int i, T e); // 在位置i插入数据元素e
        bool ListDelete(int i); // 在位置i删除数据元素


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
	cout<<"请输入存放的元素"<<endl; 
	for(j=0;j<10;j++)
	{
		cin>>data[j]>>endl;
		length++;
	}
	cout<<"输出的元素为"<<endl;
	for(j=0;j<length-1;j++)
		cout<<data[j]<<" ";
	cout<<endl;
		
			
}
template<class T>
int task<T>:: ListLength()
{
	cout<<"长度为："<<endl;
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
	cout<<"把元素"<<e<<"插入到位置"<<i<<endl;
	int j;
	if(i<1||i>length+1)
		return false;
	if(length=10)
		return false;
	for(j=length-1;j>=i;j--)
		data[j+1]=data[j];
	data[i]=e;
	length++;
	cout<<"插入成功"<<endl;
	return true;
}
template<class T>
bool task<T>::ListDelete(int i)
{
	cout<<"将位置为"<<i<<"的元素删除"<<endl;
	int j;
	if(i<1||i>length)
		cout<<"不存在这个元素"<<endl;
	for(j=i;j<=length-1;j++)
		data[j]=data[j+1];
	length--;
	cout<<"删除成功"<<endl;
	return true;	
	
}

