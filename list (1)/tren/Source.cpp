#include <iostream>
#include <cstring>
using namespace std;

struct link
{
	int data;
	int index;
	link* next;
};
class Linklist
{
private:
	link* first, *current;
	link* findprev(link* &tmp, int d);
	link* cngindex(link* tmp, bool a);
	int count = 0;
public:
	Linklist()
	{
		first = NULL;
	}
	~Linklist()
	{
		delete first;
		delete current;
	}
	void push(int d);
	void show();
	void remove(int a);
	void insert(int data, int d);
	void pop();
	int size();
};
void Linklist::push(int d)
{
	if (first == NULL)
	{
		first = new link;
		first->data = d;
		first->index = count++;
		first->next = NULL;
		current = first;
	}
	else
	{
		link* newlink = new link;
		newlink->data = d;
		newlink->index = count++;
		newlink->next = NULL;

		current->next = newlink;
		current = newlink;
	}
}
void Linklist::show()
{
	current = first;
	while (current)
	{
		cout << current->data << "\t" << current->index << endl;
		current = current->next;
	}
}
void Linklist::remove(int a)
{
	link* tmp = first;
	link* prev = findprev(tmp, a);

	prev->next = tmp->next;
	cngindex(tmp,true);

	delete tmp;
}
void Linklist::insert(int data, int d)
{
	int count = d - 1;
	link* newlink = new link;
	link* tmp = first;
	link* prev = findprev(tmp, d);
	
	newlink->data = data;
	newlink->index = d;
	newlink->next = tmp;

	prev->next = newlink;
	cngindex(tmp, false);
}
void Linklist::pop()
{
	link* last = first;
	link* prev = findprev(last, size());
	prev->next = NULL;
	delete last;
	count--;
	current = prev;
}
int Linklist::size()
{
	const int size_ = current->index;
	return current->index;
}
link* Linklist::findprev(link* &tmp, int d)
{
	int count = 0;
	link* prev = new link;
	while (tmp->index != d)
	{
		if (++count == d)
		{
			prev = tmp;
		}
		tmp = tmp->next;
	}
	return prev;
}
link* Linklist::cngindex(link* tmp, bool a)
{
	if (a == true)
	{
		while (tmp != NULL)
		{
			tmp->index--;
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp != NULL)
		{
			tmp->index++;
			tmp = tmp->next;
		}
	}
	return nullptr;
}

int main()
{
	Linklist li;
	for (int i = 0; i <= 50;)
	{
		li.push(i);
		i += 10;
	}
	cout << li.size() << endl;
	li.pop(); //- ALRIGHT
	li.push(234); //- ALRIGHT
	li.insert(23, 2); //- ALRIGHT
	li.remove(2); //- ALRIGHT
	cout << li.size() << endl; //- ALRIGHT
	li.show(); //- ALRIGHT
	system("pause");
}