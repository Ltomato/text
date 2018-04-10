Linkstack::Linkstack()
{
	Top = NULL;
	num = 0;
}

Linkstack::~Linkstack()
{
	stack *p = NULL;
	while (Top != NULL)
	{
		p = Top;
		Top = Top->next;
		delete p;
	}
}

void Linkstack::addTop(int e)
{
	stack *p = new stack;
	p->date = e;
	p->next = Top;
	Top = p;
	num++;
}

int Linkstack::stackTop()
{
	stack *p;
	int x;
	if (Top == NULL)
		cout << "无法出栈" << endl;
	else
	{
		x = Top->date;
		p = Top;
		Top = p->next;
		num--;
		delete p;
		return x;
	}
}

bool Linkstack::nullTop()
{
	if (Top == NULL)
		return 1;
	else 
		return 0;
}

void Linkstack::writeTop()
{
	int x;
	stack *p;
	if (Top == NULL)
		cout << "无法打印" << "\n";
	else
		while (Top != NULL)
		{
			p = Top;
			x = p->date;
			cout << x << "\n";
			Top = p->next;
		}
}
