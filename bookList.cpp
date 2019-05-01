#include "book.cpp"

class bookList
{
private:
	book* head; //start of the list
	book* cursor; //current item of the list
public:
	bookList()
	{
		head = NULL;
		cursor = NULL;
	}

	void insert(const book& newItem)
	{
		book* t = new book(newItem.id, newItem.title, newItem.price, newItem.next);
		if (head == NULL)
		{
			head = t;
			cursor = t;
		}
		else
		{
			book* cur = head;
			while (cur->next != NULL)
			{
				cur = cur->next;
			}
			cur->next = t;
			cursor = t;
		}
	}

	void remove()
	{
		if (head == nullptr)
			cout << "Sorry! List is empty\n";
		else if (cursor->next == nullptr)
		{
			book* t = head;
			book* a = nullptr;
			while (t->next != nullptr)
			{
				a = t; //To keep record of previous entry in LL
				t = t->next; // To move forward in LL
			}
			if (t->next == cursor->next)
			{
				delete cursor;
				cursor = a;
				cursor->next = nullptr;
				cout << "Last Element Deleted\n";
			}

		}
		else if (cursor->next != nullptr && cursor != head)
		{
			book* cur = head;
			while (cur->next != cursor)
				cur = cur->next;
			book * temp = cursor;
			cur->next = cursor->next;
			cursor = cursor->next;
			delete temp;
			cout << "Middle Element Deleted\n";
		}
		else if (cursor->next != nullptr && cursor == head)
		{
			head = cursor->next;
			delete cursor;
			cursor = head;
			cout << "First Element Deleted\n";
		}
	}

	void showStructure() const
	{
		if (head == NULL)
		{
			cout << "EMPTY LIST!!!\n";
		}
		else
		{
			book* t = head;
			while (t->next != NULL)
			{
				cout << t->id << "\t" << t->price << "\t" << t->title << endl;
				t = t->next;
			}
			cout << t->id << "\t" << t->price << "\t" << t->title << endl;
		}
	}

	void search(string title)const
	{
		if (head == NULL)
		{
			cout << "EMPTY LIST!!!\n";
		}
		else
		{
			book* t = head;
			while (t!=NULL&&t->title!=title)
			{
				t = t->next;
			}
			if (t == NULL)
			{
				cout << "BOOK NOT FOUND!!!\n";
			}
			else
			{
				cout << t->id << "\t" << t->price << "\t" << t->title << endl;
			}
		}
	}

	void replace(const book& newItem)
	{
		cursor->id = newItem.id;
		cursor->price = newItem.price;
		cursor->title = newItem.title;
	}

	bool isEmpty()
	{
		return(head == NULL);
	}

	void goToBeginning()
	{
		cursor = head;
	}

	void goToEnd()
	{
		book* cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cursor = cur;
	}

	book getCursor()
	{
		return *cursor;
	}

	bool gotoNext()
	{
		if (cursor->next == NULL)
		{
			return false;
		}
		else
		{
			cursor = cursor->next;
		}
	}

	bool gotoPrior()
	{
		if (cursor == head)
		{
			return false;
		}
		else
		{
			book* cur = head;
			book* prev = head;
			while (cur->next != cursor)
			{
				prev = cur;
				cur = cur->next;
			}
			cursor = prev;
		}
	}
};