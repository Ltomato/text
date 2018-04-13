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

/**********************************优先级*******************************/
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


/****************简化字符方便进栈****************/
string SimplyChar(string equation1)
{
	string equation2;
	for (int i = 0; i < equation1.size(); i++)
	{
		//将不需要简化的数字 （） dot 直接追加到equation2
		if (priority(equation1[i]) == -1 || priority(equation1[i]) >= 1 
			&& priority(equation1[i]) < 5 || equation1[i] == '(' || equation1[i] == ')'
			|| equation1[i] == '.')
		{
			equation2.push_back(equation1[i]);
		}
		else if (equation1[i] == 's' && equation1[i + 1] == 'i')//sin的话直接简化为 s
		{
			equation2.push_back('s');
		}
		else if (equation1[i] == 'c')//cos简化为c
		{
			equation2.push_back('c');
		}
		else if (equation1[i] == 't')//tan简化
		{
			equation2.push_back('t');
		}
		else if (equation1[i] == 'l' && equation1[i + 1] == 'g')//lg简化为l
		{
			equation2.push_back('l');
		}
		else if (equation1[i] == 'l' && equation1[i + 1] == 'o')//log简化为o
		{
			equation2.push_back('o');
		}
		else if (equation1[i] == 'p' && equation1[i + 1] == 'i')//pi简化为p
		{
			equation2.push_back('p');
		}
		else if (equation1[i] == 'e')//e直接返回e
		{
			equation2.push_back('e');
		}
		else if (equation1[i] == 'a' && equation1[i + 1] == 'b')//abs简化为a
		{
			equation2.push_back('a');
		}
		else;
	}
	return equation2;//函数返回一个简化过的equation2
}


/***********************逆波兰式******************/
string TranChar(string s)//通过优先级来进行逆波兰式
{
	int mark = 0;//判断 -
	string InverseEquation;//逆波兰字符串用于储存变化后的式子
	stack<char> CharStack;//建立符号栈将遇见的符号在正确情况下进行操作
	if (s[0] == '-')
	{
		string ZeroEquation = "0";
		s = ZeroEquation + s;
	}
	for (int i = 0; i <s.size(); i++)//对等式进行遍历 把每个元素都“安置”在合适的位置
	{
		if (s[i] == '-' && s[i - 1] == '(');
		if (s[i] == '(' && s[i + 1] == '-')// （- 情况把 - 压进栈并记录前置负号
		{
			InverseEquation.push_back(' ');
			InverseEquation.push_back('-');
			mark++;
		}
		else//正常情况
		{
			if (s[i] != ')')
			{
				if (s[i] == '(')//括号情况直接进栈
				{
					InverseEquation.push_back(' ');
					CharStack.push('(');
				}
				else if (priority(s[i]) == -1 || s[i] == '.')//数字和小数点直接进到等式
				{
					InverseEquation.push_back(s[i]);
				}
				else//符号情况
				{
					InverseEquation.push_back(' ');
					if (CharStack.empty())///空栈符号直接进栈
						CharStack.push(s[i]);
					else
					{
						if (priority(s[i]) > priority(CharStack.top()))//优先级大于栈顶元素优先级直接直接压栈
						{
							InverseEquation.push_back(' ');
							CharStack.push(s[i]);
						}
						else if (priority(s[i]) == priority(CharStack.top()))//优先级相等的话栈顶元素进到逆波兰式 s【i】符号压栈
						{
							InverseEquation.push_back(CharStack.top());
							CharStack.pop();
							InverseEquation.push_back(' ');
							CharStack.push(s[i]);
						}
						else//s【i】优先级小于栈顶元素直接追加到逆波兰式中
						{//直道遇见（ 遇到之后压栈
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

			else//  当s[i]==')'
			{
				if (mark != 0)//判断括号前为负数，当前置符号消除时候将栈的元素弹出
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

	//循环往复
	while (CharStack.size() != 0)
	{
		InverseEquation.push_back(' ');
		InverseEquation.push_back(CharStack.top());
		CharStack.pop();
	}
	return InverseEquation;
}



/**********字符转到数字********/
double exchange(string a)
{
	istringstream NumberString(a);
	double num;
	NumberString >> num;
	return num;
}
//运算+
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
//乘方
void Pow()
{
	number = NumberStack.top();
	NumberStack.pop();
	number = pow(NumberStack.top(), number);
	NumberStack.pop();
	NumberStack.push(number);
}
//正弦
void Sin()
{
	number = sin(NumberStack.top());
	NumberStack.pop();
	NumberStack.push(number);
}
//余弦
void Cos()
{
	number = cos(NumberStack.top());
	NumberStack.pop();
	NumberStack.push(number);
}
//正切
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


