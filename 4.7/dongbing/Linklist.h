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
	void Insert(info a,int);//������ 
	void Delete(info a);//ɾ����� 
	int Length();		//�õ������� 
	int Find(info a);		//���ҽ��λ�� 
	void Print();	//��ӡ���� 
	~Linklist();
private:
	Node *head;
	int length;
	 
};
