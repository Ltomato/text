#include<string>
typedef struct list
{
	int num;
	struct list *next;
}list;
class LinkList
{
public:
	
	LinkList();//构造函数  
	
	~LinkList();//析构函数 

	void InsertHead(list &L);//在链表头部插入结点  
	
	void Insert(list &L, int e);//插入结点  
	
	void Remove(list &L,int e);//删除结点  
	
	int Length();//得到链表长度  
	
	int Find(list &L,int e);//查找结点位置  
	
	void Print();//打印链表  
	 
private:
	list *head;
	int length;
};
int main()
{
	

}




