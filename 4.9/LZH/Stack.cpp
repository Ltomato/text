#include "task.h"

Stack::Stack()
{
	top=NULL;
	length=0;
}

Stack::~Stack()
{
	if(top)
	{
		Node *t;
		t=top;
		top=top->next;
		delete t;
	}
}

void Stack::in(int n)
{
	Node *t=new Node;
	t->next=top;
	t->data=n;
	top=t;
	length++;
}

int Stack::out()
{
	if(length<=0)
	{
		cout<<"无元素可供出栈\n";
		exit(0);
	}
	if(top)
	{
	Node *t=top;
	int data;
	data=top->data;
	top=top->next;
	delete(t);
	length--;
	return data;
	}
}

int Stack::top1()
{
	return top->data;
}

bool Stack::empty()
{
	if(length==0)
		return true;
	return false;
}
