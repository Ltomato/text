#include <iostream>
#include <string>
using namespace std;

class Node
{
	friend class LinkList;
private :
	struct link
	{
		int ID;
		string name;
	}L;	
	Node *next;
public :
	Node();
};

class LinkList
{
private :
	Node *head;
	Node *first;
	Node *last;
public :
	int length;
	LinkList();
	~LinkList();
	void add();
	void del();
	void find();
	void alter();
	void display();
};