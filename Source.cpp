#include <iostream>
using namespace std;

struct Node
{
public:
	int info;
	Node* next;
	Node()
	{
		info = 0;
		next = nullptr;
	}
	Node(int info_)
	{
		info = info_;
		next = nullptr;
	}
	Node(int info_, Node* next_)
	{
		info = info_;
		next = next_;
	}
};

class list {

private:
	Node* head;
	int size;
public:
	list()
	{
		head = nullptr;
		size = 0;
	}
	~list()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}

	void push_front(int info)
	{
		if (size == 0)
		{
			head = new Node(info);
			size++;
			return;
		}
		else
		{
			Node* tmp = head;
			head = new Node(info, tmp);
		}
		size++;
	}

	void push_back(int info)
	{
		if (size == 0)
		{
			head = new Node(info);
			size++;
			return;
		}
		Node* cur = head;

		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = new Node(info);
		size++;
	}
	void insert(int index, int info) {
		if ((index < 0) or (index >= size)) {
			throw "wrong index";
		}
		if (size == 0)
		{
			push_front(info);
		}
		if (index != 0) 
		{
			Node* cur = head;
			for (int i = 0; i < index - 1; i++)
			{
				cur = cur->next;
			}
			Node* tmp = cur->next;
			cur->next = new Node(info, tmp);
			size++;
		}
		else
		{
			push_front(info);
		}
	}
	void pop_front()
	{
		if (size == 0)
		{
			return;
		}
		if (size == 1)
		{
			delete head;
			size--;
			return;
		}
		Node* cur = head->next;
		delete head;
		head = cur;
		size--;
	}
	void pop(int index) 
	{
		if ((index < 0) || (index >= size))
		{
			throw "wrong index";
		}
		else
		{
			if (index == 0)
			{
				pop_front();
			}
			else
			{
				Node* cur = head;
				for (int i = 0; i < index - 1; i++)
				{
					cur = cur->next;
				}
				Node* tmp = cur->next->next;
				delete cur->next;
				cur->next = tmp;
				size--;
			}
		}
	}
	int get_info(int index) const
	{
		if ((index < 0) || (index >= size))
		{
			throw "out of range";
		}
		Node* cur = head;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		return cur->info;
	}
	void set_info(int index, int info_) const
	{
		if ((index < 0) || (index >= size))
		{
			throw "out of range";
		}
		Node* cur = head;
		for (int i = 0; i < index; i++)
		{
			cur = cur->next;
		}
		cur->info = info_;
	}
	int get_size() {
		return size;
	}
	void set_list(int size_)
	{
		for (int i = 0; i < size_; i++)
		{
			int info_ = 0;
			cout << "Enter element " << i + 1 << ": ";
			cin >> info_;
			push_back(info_);
		}
	}
	void print_list()
	{
		cout << "Your list:  ";
		Node* cur = head;
		for (int i = 0; i < size; i++)
		{
			cout << cur->info << " ";
			cur = cur->next;
		}
	}
};

void menu(list S) {
	int flag = 0;
	cout << "Functions:" << endl;
	cout << "1) New list" << endl;
	cout << "2) Push back" << endl;
	cout << "3) Push front" << endl;
	cout << "4) Insert" << endl;
	cout << "5) Delete" << endl;
	cout << "6) Set info" << endl;
	cout << "7) Get info" << endl;
	cout << "0) Exit" << endl;
	cout << "Enter:  ";
	cin >> flag;
	int info;
	int index;
	switch (flag)
	{
	case 1:
		cout << "Creating new list. Enter size: ";
		int size;
		cin >> size;
		if ((size < 1) or (size > 10))
		{
			cout << "out of range";
			break;
		}
		S = list();
		S.set_list(size);
		cout << "The operation's over" << endl;
		S.print_list();
		cout << "  What now?" << endl;
		menu(S);
	case 2:
		cout << "Enter element: ";
		cin >> info;
		S.push_back(info);
		cout << "The operation's over" << endl;
		S.print_list();
		cout << " What now?" << endl;
		menu(S);
	case 3:
		cout << "Enter element: ";
		cin >> info;
		S.push_front(info);
		cout << "The operation's over" << endl;
		S.print_list();
		cout << " What now?" << endl;
		menu(S);
	case 4:
		cout << "Enter index from 1 to " << S.get_size() << ": ";
		cin >> index;
		index--;
		if ((index < 0) or (index >= S.get_size()))
		{
			cout << "wrong index";
			break;
		}
		else 
		{
			cout << "Enter element: ";
			cin >> info;
			S.insert(index, info);
		}
		cout << "The operation's over" << endl;
		S.print_list();
		cout << " What now?" << endl;
		menu(S);
	case 5:
		cout << "Enter index from 1 to " << S.get_size() << ": ";
		cin >> index;
		index--;
		if ((index < 0) or (index >= S.get_size()))
		{
			cout << "wrong index";
			break;
		}
		else
		{
			S.pop(index);
		}
		cout << "The operation's over" << endl;
		S.print_list();
		cout << " What now?" << endl;
		menu(S);
	case 6:
		cout << "Enter index from 1 to " << S.get_size() << ": ";
		cin >> index;
		index--;
		if ((index < 0) or (index >= S.get_size()))
		{
			cout << "wrong index";
			break;
		}
		else
		{
			cout << "Enter info: ";
			cin >> info;
			S.set_info(index, info);
		}
		cout << "The operation's over" << endl;
		S.print_list();
		cout << " What now?" << endl;
		menu(S);
	case 7:
		cout << "Enter index from 1 to " << S.get_size() << ": ";
		cin >> index;
		index--;
		if ((index < 0) or (index >= S.get_size()))
		{
			cout << "wrong index";
			break;
		}
		else
		{
			cout << "Info by index " << index+1 << " is " << S.get_info(index) << endl;
		}
		cout << "The operation's over" << endl;
		S.print_list();
		cout << " What now?" << endl;
		menu(S);
	case 0:
		S.print_list();
		cout << endl << "Exit";
		break;
	default:
		cout << "No func";
		break;
	}
}

void main() {
	list S = list();
	cout << "Create your list. Enter size: ";
	int size;
	cin >> size;
	if ((size < 1) or (size > 10))
	{
		cout << "out of range";
	}
	else {
		S = list();
		S.set_list(size);
		menu(S);
	}
}