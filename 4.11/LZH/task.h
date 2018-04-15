#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

template <class T>
class Stack
{
	private :
		struct Node
		{
			T data;
			Node *next;
		};
		Node *Stacktop;
		int size;
	public :
		Stack();
		~Stack();
		void push(const T &node);
		void pop();
		T top();
		bool empty();
		void clear();
};

template <class T>
Stack<T>::Stack()
{
	Stacktop=NULL;
	size=0;
}

template <class T>
Stack<T>::~Stack()
{
	clear();
}

template <class T>
void Stack<T>::push(const T &node)
{
	Node *t=new Node;
	t->next=Stacktop;
	t->data=node;
	Stacktop=t;
	size++;
	return ;
}

template <class T>
void Stack<T>::pop()
{
	Node *t=Stacktop;
	T data;
	data=Stacktop->data;
	Stacktop=Stacktop->next;
	delete(t);
	size--;
    return;
}

template <class T>
T Stack<T>::top()
{
	return Stacktop->data;
}

template <class T>
bool Stack<T>::empty()
{
	if(size==0)
		return true;
	return false ;
}

template <class T>
void Stack<T>::clear()
{
	while(Stacktop)
	{
		Node *t=Stacktop;
		Stacktop=Stacktop->next;
		delete t;
	}
	size=0;
}

int Priority(char ch)//定义优先级别 
{
    int i;
    switch(ch)
    {
        case'(':i=1;break;
        case'+':i=2;break;
        case'-':i=2;break;
        case'*':i=4;break;
        case'/':i=4;break;
        case')':i=5;break;
        default:i=-1;break;
    }
    return i; 
}

void Transfer(char *ch,char nibolan[100])//转化为逆波兰式
{
    Stack<char> st2;
    int i=0;
    while(*ch!='\0')
    {
        if(*ch>='0'&&*ch<='9')
        {
            nibolan[i++]=*ch;
        }
        else if(*ch=='(')//左括号直接入栈 
        {
            st2.push(*ch);
        }
        else if(*ch==')')
        {
            while(st2.top()!='(')//栈顶不为左括号
            {
                nibolan[i++]=st2.top();//入栈
                st2.pop();
            }
            if(st2.top()=='(')
            {
                st2.pop();
            }

        }
        else if(st2.empty()||Priority(*ch)>Priority(st2.top()))//如果当前字符优先级高于栈顶
        {
            st2.push(*ch);
        }
        else 
        {
            while(Priority(*ch)<=Priority(st2.top()))
            {
                nibolan[i++]=st2.top();
                st2.pop();
                if(st2.empty())
                {
                    break;
                }   
            }
            st2.push(*ch);
        }   
        ch++;  //遍历字符串
    }

    while(!st2.empty())
    {
        nibolan[i++]=st2.top();
        st2.pop();  
    }

 } 

 //计算逆波兰表达式的值

 int calcval(char *nibolan)
 {

    Stack<char> st1;
    while(*nibolan!='\0')
    {
        if(*nibolan>='0'&&*nibolan<='9')
        {
            st1.push(*nibolan);
         }
        else
         {
             switch(*nibolan)
             {
                case'+':
                    {
                        char a=st1.top();
                        st1.pop();
                        char b=st1.top();
                        st1.pop();
                        st1.push(((a-'0')+(b-'0')+'0'));//注意类型的运算 
                        break;
                    }
                case'-':
                    {
                        char a=st1.top();
                        st1.pop();
                        char b=st1.top();
                        st1.pop();
                        st1.push(((b-'0')-(a-'0'))+'0');
                        break;
                    }   
                case'*':
                    {
                        char a=st1.top();
                        st1.pop();
                        char b=st1.top();
                        st1.pop();
                        st1.push(((b-'0')*(a-'0'))+'0');
                        break;
                    }
                case'/':
                    {
                        char a=st1.top();
                        st1.pop();
                        char b=st1.top();
                        st1.pop();
                        if(a!='0')
                        {
                            st1.push((((b-'0')/(a-'0'))+'0'));
                         }
                         else
                         {
                            cout<<"除数为0错误"<<endl; 
                         }
                        break;
                    }                   
              }  
         }
        nibolan++;
     }


     return st1.top()-'0';
  } 