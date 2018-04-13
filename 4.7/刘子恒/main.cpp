#include "LinkList.h"
void menu();
int main()
{
	LinkList z;
	int x;
	while(1)
	{
		menu();
		cin>>x;
		switch(x)
		{
		case 1:
			z.add();
			break;
		case 2:
			z.del();
			break;
		case 3:
			z.find();
			break;
		case 4:
			z.alter();
			break;
		case 5:
			z.display();
			break;
		case 0:
			z.~LinkList();
			break;
		}
	}
	return 0;
}

void menu()
{
	cout<<"\n1.增  2.删  3.查  4.改  5.输出  0.清除"<<endl;
}
