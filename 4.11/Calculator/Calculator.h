#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
stack< double > NumberStack;
double number;

/**********************************���ȼ�*******************************/
int priority(char ch)
{
	int p = -2;
	if (int(ch) >= 48 && int(ch) <= 57 || ch == 'e' || ch == 'p'||ch=='.') p = -1;
	else if (ch == '+' || ch == '-') p = 1;
	else if (ch == '*' || ch == '/') p = 2;
	else if (ch == '^') p = 3;
	else if (ch == 's' || ch == 'c' || ch == 't' || ch == 'l' || ch == 'o') p = 4;
	return p;
}


/****************���ַ������ջ****************/
string SimplyChar(string equation1)
{
	string equation2;
	for (int i = 0; i < equation1.size(); i++)
	{
		//������Ҫ�򻯵����� ���� dot ֱ��׷�ӵ�equation2
		if (priority(equation1[i]) == -1 || priority(equation1[i]) >= 1 
			&& priority(equation1[i]) < 5 || equation1[i] == '(' || equation1[i] == ')'
			|| equation1[i] == '.')
		{
			equation2.push_back(equation1[i]);
		}
		else if (equation1[i] == 's' && equation1[i + 1] == 'i')//sin�Ļ�ֱ�Ӽ�Ϊ s
		{
			equation2.push_back('s');
		}
		else if (equation1[i] == 'c')//cos��Ϊc
		{
			equation2.push_back('c');
		}
		else if (equation1[i] == 't')//tan��
		{
			equation2.push_back('t');
		}
		else if (equation1[i] == 'l' && equation1[i + 1] == 'g')//lg��Ϊl
		{
			equation2.push_back('l');
		}
		else if (equation1[i] == 'l' && equation1[i + 1] == 'o')//log��Ϊo
		{
			equation2.push_back('o');
		}
		else if (equation1[i] == 'p' && equation1[i + 1] == 'i')//pi��Ϊp
		{
			equation2.push_back('p');
		}
		else if (equation1[i] == 'e')//eֱ�ӷ���e
		{
			equation2.push_back('e');
		}
		else if (equation1[i] == 'a' && equation1[i + 1] == 'b')//abs��Ϊa
		{
			equation2.push_back('a');
		}
		else;
	}
	return equation2;//��������һ���򻯹���equation2
}


/***********************�沨��ʽ******************/
string TranChar(string s)//ͨ�����ȼ��������沨��ʽ
{
	int mark = 0;//�ж� -
	string InverseEquation;//�沨���ַ������ڴ���仯���ʽ��
	stack<char> CharStack;//��������ջ�������ķ�������ȷ����½��в���
	if (s[0] == '-')
	{
		string ZeroEquation = "0";
		s = ZeroEquation + s;
	}
	for (int i = 0; i <s.size(); i++)//�Ե�ʽ���б��� ��ÿ��Ԫ�ض������á��ں��ʵ�λ��
	{
		if (s[i] == '-' && s[i - 1] == '(');
		if (s[i] == '(' && s[i + 1] == '-')// ��- ����� - ѹ��ջ����¼ǰ�ø���
		{
			InverseEquation.push_back(' ');
			InverseEquation.push_back('-');
			mark++;
		}
		else//�������
		{
			if (s[i] != ')')
			{
				if (s[i] == '(')//�������ֱ�ӽ�ջ
				{
					InverseEquation.push_back(' ');
					CharStack.push('(');
				}
				else if (priority(s[i]) == -1 || s[i] == '.')//���ֺ�С����ֱ�ӽ�����ʽ
				{
					InverseEquation.push_back(s[i]);
				}
				else//�������
				{
					InverseEquation.push_back(' ');
					if (CharStack.empty())///��ջ����ֱ�ӽ�ջ
						CharStack.push(s[i]);
					else
					{
						if (priority(s[i]) > priority(CharStack.top()))//���ȼ�����ջ��Ԫ�����ȼ�ֱ��ֱ��ѹջ
						{
							InverseEquation.push_back(' ');
							CharStack.push(s[i]);
						}
						else if (priority(s[i]) == priority(CharStack.top()))//���ȼ���ȵĻ�ջ��Ԫ�ؽ����沨��ʽ s��i������ѹջ
						{
							InverseEquation.push_back(CharStack.top());
							CharStack.pop();
							InverseEquation.push_back(' ');
							CharStack.push(s[i]);
						}
						else//s��i�����ȼ�С��ջ��Ԫ��ֱ��׷�ӵ��沨��ʽ��
						{//ֱ�������� ����֮��ѹջ
							while (CharStack.size() != 0)
							{
								if (CharStack.top() == '(')   break;
								InverseEquation.push_back(' ');
								InverseEquation.push_back(CharStack.top());
								CharStack.pop();
							}
							InverseEquation.push_back(' ');
							CharStack.push(s[i]);
						}
					}
				}
			}

			else//  ��s[i]==')'
			{
				if (mark != 0)//�ж�����ǰΪ��������ǰ�÷�������ʱ��ջ��Ԫ�ص���
				{
					mark--;
				}
				else
				{
					while (CharStack.top() != '(')
					{
						InverseEquation.push_back(' ');
						InverseEquation.push_back(CharStack.top());
						CharStack.pop();
					}
					CharStack.pop();
				}
			}
		}
	}

	//ѭ������
	while (CharStack.size() != 0)
	{
		InverseEquation.push_back(' ');
		InverseEquation.push_back(CharStack.top());
		CharStack.pop();
	}
	return InverseEquation;
}



/**********�ַ�ת������********/
double exchange(string a)
{
	istringstream NumberString(a);
	double num;
	NumberString >> num;
	return num;
}
//����+
void Add()
{
	number = NumberStack.top();
	NumberStack.pop();
	number += NumberStack.top();
	NumberStack.pop();
	NumberStack.push(number);
}
//-
void Minus()
{
	number = NumberStack.top();
	NumberStack.pop();
	number = NumberStack.top() - number;
	NumberStack.pop();
	NumberStack.push(number);
}
//*
void Mul()
{
	number = NumberStack.top();
	NumberStack.pop();
	number *= NumberStack.top();
	NumberStack.pop();
	NumberStack.push(number);
}
///
void Div()
{
	number = NumberStack.top();
	NumberStack.pop();
	number = NumberStack.top() / number;
	NumberStack.pop();
	NumberStack.push(number);
}
//�˷�
void Pow()
{
	number = NumberStack.top();
	NumberStack.pop();
	number = pow(NumberStack.top(), number);
	NumberStack.pop();
	NumberStack.push(number);
}
//����
void Sin()
{
	number = sin(NumberStack.top());
	NumberStack.pop();
	NumberStack.push(number);
}
//����
void Cos()
{
	number = cos(NumberStack.top());
	NumberStack.pop();
	NumberStack.push(number);
}
//����
void Tan()
{
	number = tan(NumberStack.top());
	NumberStack.pop();
	NumberStack.push(number);
}
//log
void LogFunction()
{
	number = log(NumberStack.top());
	NumberStack.pop();
	NumberStack.push(number);
}
//lg
void LgFunction()
{
	number = log10(NumberStack.top());
	NumberStack.pop();
	NumberStack.push(number);
}
//   | |
void abs()
{
	number = abs(NumberStack.top());
	NumberStack.pop();
	NumberStack.push(number);
}


