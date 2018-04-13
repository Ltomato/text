template<class T>
class ChainNode//����ڵ�
{
public:
	T data;
	ChainNode<T> *next;
};

template<class T>
class Chain//������
{
public:
	Chain();//���캯��
	~Chain();//��������

	bool IsEmpty();//�ÿպ���
	int Length();//���س��Ⱥ���
	bool Find(int index, T &t);//��ѯλ�ú���Ѱ��
	int Search(T value);//��ѯԪ�غ���
	Chain<T>& Insert(int index, const T &t);//���뺯��
	Chain<T>& Delete(int index, T &t);//ɾ������
	Chain<T>& Reverse(void);//��ת����
	void Output();//�������

private:
	ChainNode<T> *head;
	int len;
};


#include <iostream>
using namespace std;

template<class T>
Chain<T>::Chain()
{
	head = NULL;
	len = 0;
}

template<class T>
Chain<T>::~Chain()
{
	
	ChainNode<T> *next=NULL;

	while (head)
	{
		next = head->next;
		delete head;
		head = next;
	}
}

template<class T>
bool Chain<T>::IsEmpty()//��ͷ���ڿ�ֱ�ӷ��ؼ���
{
	return (head == NULL);
}

template<class T>//���س���
int Chain<T>::Length()
{
	return len;
}

template<class T>
bool Chain<T>::Find(int index, T &t)
{
	ChainNode<T> *p = head;

	if (index < 1 || index > len + 1)
	{
		return false;
	}

	for (int i = 1; i < index && p; i++)
	{
		p = p->next;
	}

	if (p)
	{
		t = p->data;
		return true;
	}

	return false;
}

template<class T>
int Chain<T>::Search(T t)//���� �������ֱ���ҵ�λ��
{
	ChainNode<T> *p = head;
	int postion = 1;

	while (p && p->data != t)
	{
		p = p->next;
		postion++;
	}

	if (p)
	{
		return postion;
	}
	else {
		cout << "error" << endl;
	}
	return 0;
}

template<class T>//����
Chain<T>& Chain<T>::Insert(int pos, const T &t)
{
	ChainNode<T> *p = head;

	if (pos < 0 || pos > len + 1)
	{
		cout << "Insert error" << endl;
	}

	for (int i = 1; i < pos && p; i++)
	{
		p = p->next;
	}

	if (pos > 0 && !p)
	{
		cout << "Insert Failed" << endl;
	}

	ChainNode<T> *newNode = new ChainNode<T>;
	newNode->data = t;

	if (pos)//���벽��
	{
		newNode->next = p->next;
		p->next = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}

	len++;
	return *this;
}

template<class T>
Chain<T>& Chain<T>::Delete(int pos, T &t)//ɾ��
{
	ChainNode<T> *p = head;

	if (pos < 1 || pos > len)
	{
		cout << "Delete Failed" << endl;
	}

	if (pos == 1)
	{
		head = p->next;
	}
	else
	{
		ChainNode<T> *prev = head;//ɾ������ Խ����ɾ��Ԫ��
		for (int i = 1; i < pos - 1 && prev; i++)
		{
			prev = prev->next;
		}
		p = prev->next;
		prev->next = p->next;//�ؼ�
	}
	t = p->data;
	delete p;

	len--;

	return *this;
}

template<class T>
void Chain<T>::Output()//ѭ����� ֱ��Ϊ��
{
	ChainNode<T> *p = head;

	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
}

template<class T>//��ת����
Chain<T>& Chain<T>::Reverse(void)
{
	ChainNode<T> *p1 = head;
	ChainNode<T> *p2 = p1->next;
	ChainNode<T> *p3 = p2->next;

	p1->next = NULL;
	while (p3 != NULL)//��ν��ת����ʵ���Ͼ��ǰ������ָ��ת����
	{
		p2->next = p1;//������ 
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}
	p2->next = p1;
	head = p2;

	return *this;
}

