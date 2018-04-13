#include<iostream>
#include"ChainList.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	Chain<int> chain;
	int value;
	for (int i = 0; i < 10; i++)//插入
	{
		chain.Insert(i, i + 1);
	}

	chain.Output();
	cout << endl;

	cout << "置空" << chain.IsEmpty() << endl;//输出空

	cout << "长度是" << chain.Length() << endl;//输出长度
	chain.Find(4, value);//寻找第四位元素
	cout << "寻找第四位 = " << value << endl;
	cout << "查询4" << chain.Search(4) << endl;//查询四元素
	chain.Delete(1, value);//删除第一位元素
	cout << "删除第一个" << value << endl;
	chain.Output();//输出
	cout << endl;
	chain.Reverse();//反转链表 妈的好难理解花了我五分钟看懂
	cout << "反转链表 ";
	chain.Output();
	cout << endl;
	system("pause");
	return 0;
}