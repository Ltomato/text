#pragma once
#define NULL 0
#include<iostream>
using namespace std;
//�ڵ���
template <class T>
class Node
{
public:
	T data;
	Node <T> * next;

};
//ջ��������,��������ʵ��
template <class T>
class Stack
{
public:
	Stack();
	~Stack();
	T pop();//��ջ
	void push(const T&);//��ջ
	bool isEmpty();//�ж�ջ�ǲ��ǿ�
	void display();//shchu
private:
	Node<T> * top; //ջ��ָ��	
};
//���캯����������ջ
template <class T>
Stack<T>::Stack()
{
	top = NULL;
}
//��������
template <class T>
Stack<T>::~Stack()
{
	//�ͷ�������ڴ�
	if (top)
	{
		Node <T> *p;
		p = top;
		top = top->next;
		delete p;
	}
}

//�ж�ջ�ǲ��ǿ�
template <class T>
bool Stack<T>::isEmpty()
{
	if (top)
		return false;
	return true;
}
//��ջ
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
//��ջ
template <class T>
void Stack<T>::push(const T & a)
{
	//�����ڴ棬�洢����ջ�ڵ�
	Node<T> * p = new Node <T>;
	p->next = top;
	p->data = a;
	top = p;
}
template <class T>
void Stack<T>::display()
{
	cout << "������Ҫ����ջ��Ԫ�ص�����\n" << endl;
	int a, i, number;
	cin >> a;
	cout << "���������ջ��Ԫ����ֵ\n";
	for (i = 0; i<a; i++)
	{
		cin >> number;
		push(number);
	}
	cout << "Ԫ�س�ջ\n";
	for (i = 0; i<a; i++)
	{
		cout << pop() << endl;
	}
}
