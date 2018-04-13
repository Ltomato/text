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
	cout<<"学号:";
	cin>>L.ID;
	cout<<"姓名:";
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
    cout<<"\n输入学号删除 ";
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
        cout<<"\n未找到"<<endl;
        return;
    }
    if(!p)
    {
        first=first->next;
        cout<<"\n成功删除"<<endl;
        delete t;
    }
    else
    {
        p->next=t->next;
        cout<<"成功删除"<<endl;
        delete t;
    }
	length--;
	return ;
}
void LinkList::find()
{
    int a;
    cout<<"\n输入学号查找";
	cin>>a;
    Node *t = first;
    while(t){
        if(t->L.ID==a)
            break;
        t=t->next;
    }
    if(!t)
    {
        cout<<"\n未找到"<<endl;
        return;
    }
    cout<<"\n查找成功！"<<endl;
	cout<<"学号:"<<t->L.ID<<"   "<<"姓名:"<<t->L.name<<endl;
	return ;
}
void LinkList::alter()
{
	Node *t=first;
	int i=0;
	cout<<"输入学号修改"<<endl;
	cin>>i;
    while(t)
	{
        if(t->L.ID==i)
            break;
        t=t->next;
    }
	if(!t)
	{
		cout<<"\n未找到"<<endl;
		return;
	}
	int ii;
	cout<<"输入新学号"<<endl;
	cin>>ii;
	t->L.ID=ii;
	cout<<"修改成功"<<endl;
	return ;
}
void LinkList::display()
{
	Node *p=first;
	while(p)
	{
		cout<<"学号:"<<p->L.ID<<"     "<<"姓名"<<p->L.name<<endl;
		p=p->next;
	}
	return;
}