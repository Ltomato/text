#include<string.h>
#include<stdlib.h>
#include <iostream> 
using namespace std;
void apple();//ֱ�����㺯��
void banana();//���ȼ�����
template <class T>
class MyStack
{
public:
	MyStack(int size);    //��ʼ��ջ�ռ�  
	~MyStack();//����ջ�ռ��ڴ�  
	bool push(T elem);//Ԫ����ջ��ջ������  
	bool pop(T &elem);//Ԫ�س�ջ��ջ�����½�  
	bool poppp();//ջ���½�
private:
	T *m_pBuffer;//ջ�ռ�ָ��   
	int m_itop;//ջ����Ҳ��ջ��Ԫ�ظ���  
};
template <class T>
MyStack<T >::MyStack(int size)
{
	m_pBuffer = new T[size];
	m_itop = 0;
}
template <class T>
MyStack<T >::~MyStack()
{
	delete[] m_pBuffer;
}
template <class T>
bool MyStack<T >::push(T elem)
{	
	m_pBuffer[m_itop] = elem;
	m_itop++;
	return true;
}
template <class T>
bool MyStack<T >::pop(T &elem)
{
	elem = m_pBuffer[m_itop-1];
	return true;
}
template <class T>
bool MyStack<T >::poppp()
{
	m_itop--;
	return true;
}
MyStack<double > ch1(100);
MyStack <char > ch2(100);
int main()
{
	ch2.push('(');//��ջ��ѹ��һ��������
	int i = 0, a, d;
	double b,c;
	char str[100];
	char str1[10] = "=";
	char str2[10];
	printf("������һ����ʽ\n");
	cin >> str;
	strcat_s(str, str1);
	d = strlen(str);
	for (i = 0; i < d; i++)
	{
		a = 0;
		if (str[i] >= '0'&&str[i] <= '9' || str[i] == '.')
		{
			str2[a] = str[i];//�����������ֺ�С����浽��һ������
			a++;
			
		}
		str2[a] = 0;
		if (str2[0] != 0)
		{
			b = atof(str2);//������ѹ����double������
			ch1.push(b);//ѹ����ֱ����ջ
		}
		if (str[i] == '(' || str[i] == '{')//�������ŵȼ۳�С����
			str[i] = '(';
		else if (str[i] == ')' || str[i] == '}')
			str[i] = ')';
		switch (str[i])
		{
			case '+':
			{
				apple();
				ch2.push('+');//���ӺŽ�ջ
				break;
			}
			case '-':
			{
				apple();
				ch2.push('-');//�����Ž�ջ
				break;
			}
			case '*':
			{
				banana();
				ch2.push('*');//���˺Ž�ջ
				break;
			}
			case '/':
			{
				banana();
				ch2.push('/');//�����Ž�ջ
				break;
			}
			case '(':
			{
				ch2.push('(');//�������Ž�ջ
				break;
			}
			case ')':
			{
				apple();
				ch2.poppp();//�������ų�ջ
				break;
			}
			case '=':
			{
				apple();
				ch2.poppp();//�������ų�ջ
				break;
			}
		}
	}
	ch1.pop(c);
	cout << "���Ϊ��" << c << "\n";
	system("pause");
}
void apple()//��+-���ź��������������������������
{
	char a;
	double b1, b2,b3;
	ch2.pop(a);
	while(a != '(')
	{
		ch1.pop(b1);
		ch1.poppp();
		ch1.pop(b2);
		ch1.poppp();
		switch (a)
		{
			case '+':
				b3 = b1 + b2;
				break;
			case '-':
				b3 = b2 - b1;
				break;
			case '*':
				b3 = b2 * b1;
				break;
			case '/':
				b3 = b2 / b1;
				break;
		}
		ch2.poppp();
		ch1.push(b3);
		ch2.pop(a);
	}
	return;
}
void banana()//��* /ͬ�����Ž�������
{
	char a;
	double a1, a2,a3;
	ch2.pop(a);
	while (a == '*' || a == '/')
	{
		ch1.pop(a1);
		ch1.pop(a2);
		if (a == '*')
		{
			a3 = a1 * a2;
			ch1.poppp();
			ch1.poppp();
		}
		if (a == '/')
		{
			a3 = a2 / a1;
			ch1.poppp();
			ch1.poppp();
		}
		ch1.push(a3);
		ch2.poppp();
		ch2.pop(a);
	}
		
}


