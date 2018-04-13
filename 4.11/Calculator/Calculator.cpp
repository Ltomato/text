// Calculator.cpp: 定义控制台应用程序的入口点。
#include "stdafx.h"
#include"Calculator.h"
#include<iostream>
int main()
{
		stack< double > s;
		string equation;
		cout <<  "计算器" << endl;
		cout << "功能如下："<<endl<<"(1)可求解整数小数的四则运算 " <<"(2)绝对值运算"<<endl;
		cout <<                     "(3)sin cos tan 的三角运算" <<"   (4)lg log 的对数运算"<<endl;
		cout <<                     "(5)e 的科学表示法" <<"           (6)pow ^ 乘方运算" << endl;
		cout << "请输入算式 " << endl;
		while ( cin >> equation)
		{
			string sp;
			stringstream ss(TranChar(SimplyChar(equation)));
			while (ss >> sp)
			{
				if (int(sp[0]) > 47 && int(sp[0]) < 58)
				{
					NumberStack.push(exchange(sp));
				}
				else if (sp[0] == '-' && sp.size() != 1)
				{
					if (int(sp[1]) > 47 && int(sp[1]) < 58)
						NumberStack.push(exchange(sp));
					else if (sp[1] == 'p')
					{
						double pi = 3.14159265;
						NumberStack.push(-pi);
					}
					else if (sp[1] == 'e')
					{
						NumberStack.push(-2.71828182);
					}
				}
				else if (sp[0] == 'p')
				{
					double pi = 3.14159265;
					NumberStack.push(pi);
				}
				else if (sp[0] == 'e')
					NumberStack.push(2.71828182);
				else if (sp[0] == '+')
					Add();
				else if (sp[0] == '-')
					Minus();
				else if (sp[0] == '*')
					Mul();
				else if (sp[0] == '/')
					Div();
				else if (sp[0] == '^')
					Pow();
				else if (sp[0] == 's')
					Sin();
				else if (sp[0] == 'c')
					Cos();
				else if (sp[0] == 't')
					Tan();
				else if (sp[0] == 'l')
					LgFunction();
				else if (sp[0] == 'o')
					LogFunction();
				else if (sp[0] == 'a')
					abs();
				else;
			}
			if (NumberStack.top() > 0 && NumberStack.top() < pow(10.0, -8) || NumberStack.top() < 0 && NumberStack.top() > 0 - pow(10.0, -8))
				cout << "result:" << 0 << endl;
			else
				printf("result:%.8g\n", NumberStack.top());
			cout << endl;

		}
	
    return 0;
}

