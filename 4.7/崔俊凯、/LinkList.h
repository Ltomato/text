#include<string>
typedef struct list
{
	int num;
	struct list *next;
}list;
class LinkList
{
public:
	
	LinkList();//���캯��  
	
	~LinkList();//�������� 

	void InsertHead(list &L);//������ͷ��������  
	
	void Insert(list &L, int e);//������  
	
	void Remove(list &L,int e);//ɾ�����  
	
	int Length();//�õ�������  
	
	int Find(list &L,int e);//���ҽ��λ��  
	
	void Print();//��ӡ����  
	 
private:
	list *head;
	int length;
};
int main()
{
	

}




