#include <iostream>  
#include "linklist.h"  
using namespace std;
LinkList::LinkList()
{
	head = NULL;
	length = 0;
}
LinkList::~LinkList()
{
	list *p;
	int i ;
	for (i = 0; i<length; i++)
	{
		p = head;
		head = head->next;
		delete p;
	}
}
void LinkList::Insert(list &L, int e)
{
	int a;
	list *p = head;
	list *q = new list(L);
	if (e<0||e>length)
	{
		cout << "节点不规范" << endl;
		return;
	}
	if (p = NULL)
	{
		cout << "请先建立链表" << "\n";
		return;
	}
	if (e == 0)
	{
		q->next = p;
		head = q;
		length++;
		return;
	}
	while (e>a)
	{
		p = p->next;
		a++;
	}
	q->next = p->next;
	p->next = q;
	length++;
}
void LinkList::InsertHead(list &L)
{
	Insert(L, 0);
}
void LinkList::Remove(list &L, int e)
{
	if (e <= 0)
	{
		cout << "节点不规范" << "\n";
	}
	if (e == 1)
	{
		head = head->next;
		length--;
		return;
	}
	int a = 0;
	list *p = head;
	while (e > a)
	{
		p = p->next;
		a++;
	}
	p->next = p->next->next;
	length--;
}
int LinkList::Length()
{
	return length;
}
int LinkList::Find(list &L,int e)
{
	int b = 1;
	list *p = head;
	while (b)
	{
		if (p->num == e)
			return b;
		b++;
		p = p->next;
		if (p == NULL)
			return -1;
	}
}
void LinkList::Print()
{
	if (head == NULL)
	{
		cout << "LinkList is empty" << endl;
		return;
	}
	list *p = head;
	while (p != NULL)
	{
		cout << p->num << " ";
		p = p->next;
	}
	cout << "\n";
}