
#include "Book.h"
#include "BTree.h"

Book::Book(int catalog, int _shelf)
{
	this->catalogNumber = catalog;
	this->shelf = _shelf;
	this->available = true;
	// TODO: fix
}

bool Book::borrowBook(int numBook)
{
	if (this->getKey() == numBook) //if the book exised
	{

		if (this->available == true) //if it is not borrowed
		{
			this->available = false; //became the book to be borrowed.
			cout << "Successfully found the book " << this->getKey() << " on shelf " << this->getShelf() << " and borrowed it" << endl;
		}

		else //if it is  already borrowed.
		{
			cout << "Error! The book " << this->getKey() << " is already borrowed!" << endl;
		}
		return true;
	}
	return false;
	// TODO: fix.

}

bool Book::returnBook(int numBook)
{
	//Book* ptr = BTree<Book>::search(numBook);
	//if (ptr != nullptr) //if the book exised
	if (this->getKey() == numBook) //if the book exised
	{

		if (this->available == false) //if it is borrowed
		{
			this->available = true; //became the book to be not borrowed.
			cout << "Successfully returned the book " << this->getKey() << " to shelf " << this->getShelf() << endl;
		}

		else //if it is not already borrowed.
		{
			cout << "Error! The book " << this->getKey() << " is not borrowed!" << endl;
		}

	}

	// TODO: fix.	
	return true;
}

ostream& operator<<(ostream& os, Book b)
{
	os << "{" << b.catalogNumber << ", " << b.shelf << ", ";
	os << (b.available ? "available" : "borrowed") << "}";
	return os;
}

istream& operator>>(istream& is, Book& b)
{
	is >> b.catalogNumber >> b.shelf;
	return is;
}
