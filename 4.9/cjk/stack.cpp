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
	Linkstack();//��ջ
	~Linkstack();//���ջ
	void addTop(int e);//����ջ
	int stackTop();//��ջ
	bool nullTop();//�п�
	void writeTop();//��ӡ
};
int main()
{
	Linkstack s;
	s.addTop(5);
	s.addTop(6);
	s.addTop(7);
	s.writeTop();
}
