#include "LinkList.h"

LinkList::LinkList()
{
	head=NULL;
	first=NULL;
	last=NULL;
	length=0;
}

LinkList::~LinkList()
{
	Node *t;
	for(int i=0;i<length;i++)
	{
		t=head;
		head=head->next;
		delete t;
	}
}
Node::Node()
{
	cout<<"ѧ��:";
	cin>>L.ID;
	cout<<"����:";
	cin>>L.name;
	next=NULL;
}

void LinkList::add()
{
	Node *t=new Node;
	Node *p=first;
    while(p)
	{
        p=p->next;
    }
    if(first==NULL)
    {
        first=last=t;
        
    }
    else
    {    
        last->next=t;
        last=last->next;
    }
	length++;
	return;
}
void LinkList::del()
{
    int a;
    cout<<"\n����ѧ��ɾ�� ";
	cin>>a;
    Node *t = first;
    Node *p=NULL;
    while(t){
        if(t->L.ID==a)
            break;
        p=t;
        t=t->next;
    }
    if(!t)
    {
        cout<<"\nδ�ҵ�"<<endl;
        return;
    }
    if(!p)
    {
        first=first->next;
        cout<<"\n�ɹ�ɾ��"<<endl;
        delete t;
    }
    else
    {
        p->next=t->next;
        cout<<"�ɹ�ɾ��"<<endl;
        delete t;
    }
	length--;
	return ;
}
void LinkList::find()
{
    int a;
    cout<<"\n����ѧ�Ų���";
	cin>>a;
    Node *t = first;
    while(t){
        if(t->L.ID==a)
            break;
        t=t->next;
    }
    if(!t)
    {
        cout<<"\nδ�ҵ�"<<endl;
        return;
    }
    cout<<"\n���ҳɹ���"<<endl;
	cout<<"ѧ��:"<<t->L.ID<<"   "<<"����:"<<t->L.name<<endl;
	return ;
}
void LinkList::alter()
{
	Node *t=first;
	int i=0;
	cout<<"����ѧ���޸�"<<endl;
	cin>>i;
    while(t)
	{
        if(t->L.ID==i)
            break;
        t=t->next;
    }
	if(!t)
	{
		cout<<"\nδ�ҵ�"<<endl;
		return;
	}
	int ii;
	cout<<"������ѧ��"<<endl;
	cin>>ii;
	t->L.ID=ii;
	cout<<"�޸ĳɹ�"<<endl;
	return ;
}
void LinkList::display()
{
	Node *p=first;
	while(p)
	{
		cout<<"ѧ��:"<<p->L.ID<<"     "<<"����"<<p->L.name<<endl;
		p=p->next;
	}
	return;
}