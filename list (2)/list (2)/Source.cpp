#include <iostream>
using namespace std;

struct Link
{
	int data;
	int index;
	Link* next;
	Link* prev;
};
class Linklist
{
private:
	Link* first;
	Link* current;
	Link* cngindex(Link* tmp, bool a);
	Link* find(Link* tmp, int d);
	int count;
	int size = 0;
public:
	Linklist()
	{
		count = 0;
		first = NULL;
	}
	~Linklist()
	{
		delete first;
		delete current;
	}

	void push_back(int d);
	void push_front(int d);
	void pop_back();
	void pop_front();
	void insert(int data, int d);
	void erase(int d);
	void swapall();
	int getsize();
	void show();
};

void Linklist::push_back(int d)
{
	if (first == NULL)
	{
		first = new Link;
		first->index = count++;
		first->data = d;
		first->prev = NULL;
		first->next = NULL;
		current = first;
		size++;
	}
	else
	{
		Link* newlink = new Link;
		newlink->data = d;
		newlink->index = count++;
		newlink->prev = current;
		newlink->next = NULL;

		current->next = newlink;
		current = newlink;
		size++;
	}
}
void Linklist::push_front(int d)
{
	if (first == NULL)
	{
		first = new Link;
		first->index = count++;
		first->data = d;
		first->prev = NULL;
		first->next = NULL;
		current = first;
		size++;
	}
	else
	{
		Link* newlink = new Link;
		newlink->data = d;
		newlink->index = 0;
		newlink->next = first;
		newlink->prev = NULL;

		first = newlink;
		current = first;
		cngindex(current->next, true);
		size++;
	}
}
void Linklist::pop_back()
{
	Link* tmp = find(first, size-1);
	Link* prev = tmp->prev;
	prev->next = NULL;
	size--;
	delete tmp;
}
void Linklist::pop_front()
{
	Link* tmp = first;
	first = tmp->next;
	first->prev = NULL;
	cngindex(tmp, false);
	size--;
	delete tmp;
}
void Linklist::insert(int data, int d)
{
	Link* newlink = new Link;
	Link* tmp = find(first, d);
	Link* previous = tmp->prev;

	newlink->data = data;
	newlink->index = d;
	newlink->prev = previous;
	newlink->next = tmp;

	previous->next = newlink;
	cngindex(tmp, true);
	size++;
}
void Linklist::erase(int d)
{
	Link* tmp = find(first, d);
	Link* prev = tmp->prev;
	prev->next = tmp->next;
	tmp->next->prev = prev;
	cngindex(tmp, false);
	size--;
	delete tmp;
}
Link* Linklist::find(Link* tmp, int d)
{
	Link* result = new Link;
	while (tmp->index != d)
	{
		tmp = tmp->next;
	}
	result = tmp;
	return result;
}
Link* Linklist::cngindex(Link* tmp, bool a)
{
	if (a == true)
	{
		while (tmp != NULL)
		{
			tmp->index++;
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp != NULL)
		{
			tmp->index--;
			tmp = tmp->next;
		}
	}
	return 0;
}
void Linklist::show()
{
	current = first;
	while (current != NULL)
	{
		cout << current->data << "\t" << current->index << endl;
		current = current->next;
	}
}
int Linklist::getsize()
{
	return size;
}
void Linklist::swapall()
{
	Link* tmp = first;
	while (tmp != NULL)
	{
		int temp_data = tmp->data;
		tmp->data = tmp->next->data;
		tmp->next->data = temp_data;

		tmp = tmp->next;
	}
}

int main()
{
	Linklist li;
	for (int i = 0; i <= 22;)
	{
		li.push_back(i);
		i += 11;
	}
	//li.push_front(2); //- ALLRIGHT
	//li.insert(22, 2); //- ALLRIGHT
	//li.erase(2); //- ALRIGHT
	//li.pop_front(); //- ALLRIGHT
	//cout << li.getsize() << endl; //- ALLRIGHT
	//li.pop_back(); //- ALLRIGHT
	li.swapall();
	li.show(); //- ALLRIGHT

	system("pause");
}