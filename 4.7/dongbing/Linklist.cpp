#include<iostream>
#include"Linklist.h"
using namespace std;

Linklist::Linklist()
{
	head=NULL;
	length=0;
}
Linklist::~Linklist()
{
	int i;
	Node *temp;
	for(i=0;i<length;i++)
	{
		temp=head;
		head=head->next;
		delete temp;
	}
}
int Linklist::Length()
{
	return length;
}
void Linklist::Insert(info a,int)
{
	int pos;
	if(pos<0)
	{
		cout<<"pos must be greater than 0"<<endl;
		return;
	}
	int n=1;
	Node *temp=head;
	Node *node=new Node;
	if(pos==0)
	{
		node->next=temp;
		head=node;
		length++;
		return;
	}
	while(temp!=NULL&&n<pos)
	{
		temp=temp->next;
		n++;
		
	}
	if(temp==NULL)
	{
		cout<<"Insert failed"<<endl;
		return;
	}
	node->next=temp->next;
	temp->next=node;
	length++;
}
void Linklist::Delete(info a)
{
	int pos=Find(a);
	if(pos=-1)
	{
		cout<<"Delete failed"<<endl; 
		return;
	}
	if(pos==1)
	{
		head=head->next;
		length--;
		return;
	}
	int n=2;
	Node *temp=head;
	while(n<pos)
		temp=temp->next;
	temp->next=temp->next->next;
	length--;
}
int Linklist::Find(info a)
{
	Node *temp=head;
	int n=1;
	while(temp!=NULL)
	{
		if(temp->a.name==a.name&&temp->a.id==a.id)
			return n;
		temp=temp->next;
		n++;	
	} 
	return -1;
}
void Linklist::Print()
{
	if(head==NULL)
	{
		cout<<"Linklist is empty"<<endl;
		return;
	}
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->a.name<<","<<temp->a.id<<endl;
		temp=temp->next;
		
	}
	cout<<endl;
}
