#include <iostream>
#include <string>
#pragma once
using namespace std;

class book
{
	friend class bookList;

	int id;
	string title;
	float price;
	book* next;
public:
	book(int id, string title, float price, book* next)
	{
		this->id = id;
		this->title = title;
		this->price = price;
		this->next = next;
	}


private:

};
