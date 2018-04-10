#include <iostream>
using namespace std;

class Stack
{
private :
	struct Node
	{
		int data;
		Node *next;
	};
	Node *top;
	int length;

public :
	Stack();
	~Stack();
	void in(int n);
	int out();
	int top1();
	bool empty();
	void clear();
};


