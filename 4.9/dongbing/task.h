#include<iostream>
using namespace std;
typedef int datatype;
struct node
{
	datatype data;
	node *next;
};
class stack
{
public:
	stack();
	~stack();
	void push(datatype a);
	void pop();
	bool Empty();
private:
	node *top;
};


