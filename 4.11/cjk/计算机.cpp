#include<string.h>
#include<stdlib.h>
#include <iostream> 
using namespace std;
void apple();//直接运算函数
void banana();//优先级函数
template <class T>
class MyStack
{
public:
	MyStack(int size);    //初始化栈空间  
	~MyStack();//回收栈空间内存  
	bool push(T elem);//元素入栈，栈顶上升  
	bool pop(T &elem);//元素出栈，栈顶不下降  
	bool poppp();//栈顶下降
private:
	T *m_pBuffer;//栈空间指针   
	int m_itop;//栈顶，也是栈中元素个数  
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
	ch2.push('(');//在栈底压入一个左括号
	int i = 0, a, d;
	double b,c;
	char str[100];
	char str1[10] = "=";
	char str2[10];
	printf("请输入一个算式\n");
	cin >> str;
	strcat_s(str, str1);
	d = strlen(str);
	for (i = 0; i < d; i++)
	{
		a = 0;
		if (str[i] >= '0'&&str[i] <= '9' || str[i] == '.')
		{
			str2[a] = str[i];//将连续的数字和小数点存到另一个数组
			a++;
			
		}
		str2[a] = 0;
		if (str2[0] != 0)
		{
			b = atof(str2);//将数组压缩成double型数字
			ch1.push(b);//压缩后，直接入栈
		}
		if (str[i] == '(' || str[i] == '{')//将大括号等价成小括号
			str[i] = '(';
		else if (str[i] == ')' || str[i] == '}')
			str[i] = ')';
		switch (str[i])
		{
			case '+':
			{
				apple();
				ch2.push('+');//将加号进栈
				break;
			}
			case '-':
			{
				apple();
				ch2.push('-');//将减号进栈
				break;
			}
			case '*':
			{
				banana();
				ch2.push('*');//将乘号进栈
				break;
			}
			case '/':
			{
				banana();
				ch2.push('/');//将除号进栈
				break;
			}
			case '(':
			{
				ch2.push('(');//将左括号进栈
				break;
			}
			case ')':
			{
				apple();
				ch2.poppp();//将左括号出栈
				break;
			}
			case '=':
			{
				apple();
				ch2.poppp();//将左括号出栈
				break;
			}
		}
	}
	ch1.pop(c);
	cout << "结果为：" << c << "\n";
	system("pause");
}
void apple()//将+-符号后面所有数字与运算符进行运算
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
void banana()//将* /同级符号进行运算
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


