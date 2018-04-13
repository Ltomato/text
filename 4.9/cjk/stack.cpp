#include <iostream>  
#include "stack.h"  
using namespace std;
typedef struct stack
{
	int date;
	struct stack *next;
}stack;
class Linkstack
{
private:
	stack * Top;
	int num;
public:
	Linkstack();//建栈
	~Linkstack();//清空栈
	void addTop(int e);//插入栈
	int stackTop();//出栈
	bool nullTop();//判空
	void writeTop();//打印
};
int main()
{
	Linkstack s;
	s.addTop(5);
	s.addTop(6);
	s.addTop(7);
	s.writeTop();
}
