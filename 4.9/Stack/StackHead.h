#pragma once
#define NULL 0
#include<iostream>
using namespace std;
//节点类
template <class T>
class Node
{
public:
	T data;
	Node <T> * next;

};
//栈的类声明,基于链表实现
template <class T>
class Stack
{
public:
	Stack();
	~Stack();
	T pop();//出栈
	void push(const T&);//入栈
	bool isEmpty();//判断栈是不是空
	void display();//shchu
private:
	Node<T> * top; //栈顶指针	
};
//构造函数，建立空栈
template <class T>
Stack<T>::Stack()
{
	top = NULL;
}
//析构函数
template <class T>
Stack<T>::~Stack()
{
	//释放申请的内存
	if (top)
	{
		Node <T> *p;
		p = top;
		top = top->next;
		delete p;
	}
}

//判断栈是不是空
template <class T>
bool Stack<T>::isEmpty()
{
	if (top)
		return false;
	return true;
}
//出栈
template <class T>
T Stack<T>::pop()
{
	if (top)
	{
		T tmp = top->data;
		Node<T> * p = top;
		top = top->next;
		delete p;
		return tmp;
	}
}
//入栈
template <class T>
void Stack<T>::push(const T & a)
{
	//申请内存，存储新入栈节点
	Node<T> * p = new Node <T>;
	p->next = top;
	p->data = a;
	top = p;
}
template <class T>
void Stack<T>::display()
{
	cout << "请输入要存入栈的元素的数量\n" << endl;
	int a, i, number;
	cin >> a;
	cout << "请输入存入栈的元素数值\n";
	for (i = 0; i<a; i++)
	{
		cin >> number;
		push(number);
	}
	cout << "元素出栈\n";
	for (i = 0; i<a; i++)
	{
		cout << pop() << endl;
	}
}
