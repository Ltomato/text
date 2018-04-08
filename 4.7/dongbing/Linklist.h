#include<string>
using namespace std;

struct info
{
	string name;
	int id;
};

struct Node
{
	info a;
	Node *next;
};

class Linklist
{
public:
	Linklist();
	void Insert(info a,int);//插入结点 
	void Delete(info a);//删除结点 
	int Length();		//得到链表长度 
	int Find(info a);		//查找结点位置 
	void Print();	//打印链表 
	~Linklist();
private:
	Node *head;
	int length;
	 
};
