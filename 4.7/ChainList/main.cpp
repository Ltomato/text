#include<iostream>
#include"ChainList.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	Chain<int> chain;
	int value;
	for (int i = 0; i < 10; i++)//����
	{
		chain.Insert(i, i + 1);
	}

	chain.Output();
	cout << endl;

	cout << "�ÿ�" << chain.IsEmpty() << endl;//�����

	cout << "������" << chain.Length() << endl;//�������
	chain.Find(4, value);//Ѱ�ҵ���λԪ��
	cout << "Ѱ�ҵ���λ = " << value << endl;
	cout << "��ѯ4" << chain.Search(4) << endl;//��ѯ��Ԫ��
	chain.Delete(1, value);//ɾ����һλԪ��
	cout << "ɾ����һ��" << value << endl;
	chain.Output();//���
	cout << endl;
	chain.Reverse();//��ת���� ��ĺ�����⻨��������ӿ���
	cout << "��ת���� ";
	chain.Output();
	cout << endl;
	system("pause");
	return 0;
}