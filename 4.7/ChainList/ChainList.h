template<class T>
class ChainNode//链表节点
{
public:
	T data;
	ChainNode<T> *next;
};

template<class T>
class Chain//链表类
{
public:
	Chain();//构造函数
	~Chain();//析构函数

	bool IsEmpty();//置空函数
	int Length();//返回长度函数
	bool Find(int index, T &t);//查询位置函数寻找
	int Search(T value);//查询元素函数
	Chain<T>& Insert(int index, const T &t);//插入函数
	Chain<T>& Delete(int index, T &t);//删除函数
	Chain<T>& Reverse(void);//反转函数
	void Output();//输出函数

private:
	ChainNode<T> *head;
	int len;
};


#include <iostream>
using namespace std;

template<class T>
Chain<T>::Chain()
{
	head = NULL;
	len = 0;
}

template<class T>
Chain<T>::~Chain()
{
	
	ChainNode<T> *next=NULL;

	while (head)
	{
		next = head->next;
		delete head;
		head = next;
	}
}

template<class T>
bool Chain<T>::IsEmpty()//让头等于空直接返回即可
{
	return (head == NULL);
}

template<class T>//返回长度
int Chain<T>::Length()
{
	return len;
}

template<class T>
bool Chain<T>::Find(int index, T &t)
{
	ChainNode<T> *p = head;

	if (index < 1 || index > len + 1)
	{
		return false;
	}

	for (int i = 1; i < index && p; i++)
	{
		p = p->next;
	}

	if (p)
	{
		t = p->data;
		return true;
	}

	return false;
}

template<class T>
int Chain<T>::Search(T t)//查找 逐个遍历直到找到位置
{
	ChainNode<T> *p = head;
	int postion = 1;

	while (p && p->data != t)
	{
		p = p->next;
		postion++;
	}

	if (p)
	{
		return postion;
	}
	else {
		cout << "error" << endl;
	}
	return 0;
}

template<class T>//插入
Chain<T>& Chain<T>::Insert(int pos, const T &t)
{
	ChainNode<T> *p = head;

	if (pos < 0 || pos > len + 1)
	{
		cout << "Insert error" << endl;
	}

	for (int i = 1; i < pos && p; i++)
	{
		p = p->next;
	}

	if (pos > 0 && !p)
	{
		cout << "Insert Failed" << endl;
	}

	ChainNode<T> *newNode = new ChainNode<T>;
	newNode->data = t;

	if (pos)//插入步骤
	{
		newNode->next = p->next;
		p->next = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}

	len++;
	return *this;
}

template<class T>
Chain<T>& Chain<T>::Delete(int pos, T &t)//删除
{
	ChainNode<T> *p = head;

	if (pos < 1 || pos > len)
	{
		cout << "Delete Failed" << endl;
	}

	if (pos == 1)
	{
		head = p->next;
	}
	else
	{
		ChainNode<T> *prev = head;//删除过程 越过被删的元素
		for (int i = 1; i < pos - 1 && prev; i++)
		{
			prev = prev->next;
		}
		p = prev->next;
		prev->next = p->next;//关键
	}
	t = p->data;
	delete p;

	len--;

	return *this;
}

template<class T>
void Chain<T>::Output()//循环输出 直到为空
{
	ChainNode<T> *p = head;

	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
}

template<class T>//反转链表
Chain<T>& Chain<T>::Reverse(void)
{
	ChainNode<T> *p1 = head;
	ChainNode<T> *p2 = p1->next;
	ChainNode<T> *p3 = p2->next;

	p1->next = NULL;
	while (p3 != NULL)//所谓反转链表实际上就是把链表的指向反转过来
	{
		p2->next = p1;//讲不好 
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}
	p2->next = p1;
	head = p2;

	return *this;
}

