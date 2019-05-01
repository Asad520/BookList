#include "bookList.cpp"

int main()
{
	bookList l1;
	book b1(1, "aaa", 10, NULL);
	book b2(2, "bbb", 20, NULL);
	book b3(3, "ccc", 30, NULL);
	l1.insert(b1);
	l1.insert(b2);
	l1.insert(b3);
	l1.gotoPrior();
	l1.gotoPrior();
	l1.remove();
	//l1.showStructure();
	//l1.search("aaa");
	//l1.replace(b1);
	l1.showStructure();
}