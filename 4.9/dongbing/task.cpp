#include<iostream>
#include"task.h"
using namespace std;

stack::stack()
{
	top=NULL;
}
stack::~stack()
{
	node *p=NULL;
	while(top!=NULL)
	{
		p=top->next;
		delete top;
		top=p;
	}
}
void stack::push(datatype a)
{
	node *p=new node;
	p->data=a;
	p->next=top;
	top=p;
}
void stack::pop()
{
	node *p=top->next;
	delete top;
	top=p;
}
bool stack::Empty()
{
	return top==NULL;
}
