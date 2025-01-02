#pragma once
#include<iostream>
using namespace std;
class Book
{
private:
	int catalogNumber;
	int shelf;
	bool available;
public:
	int getKey() { return catalogNumber; }
	int getShelf() { return shelf; }
	Book(int catalog = 0, int _self = 0);
	bool borrowBook(int numBook);
	bool returnBook(int numBook);
	// TODO: fix operators
	bool operator<(Book b)
	{
		if (this->catalogNumber < b.getKey())
			return true;
		return false;

	} // TODO: fix
	bool operator>(Book b)
	{
		if (this->catalogNumber > b.getKey())
			return true;
		return false;
	} // TODO: fix
	bool operator<=(Book b)
	{
		if (this->catalogNumber <= b.getKey())
			return true;
		return false;
	} // TODO: fix
	bool operator==(Book b)
	{
		if (this->getKey() == b.getKey())
			return true;
		return false;
	} // TODO: fix
	bool operator!=(Book b)
	{
		if (this->getKey() != b.getKey())
			return true;
		return false;
	} // TODO: fix
	Book& operator=(const Book& other) {
		if (this == &other) {
			return *this;
		}

		// Copy fields from the other book
		this->catalogNumber = other.catalogNumber;
		this->shelf = other.shelf;
		this->available = other.available;

		return *this;
	}

	friend ostream& operator<<(ostream& os, Book b);
	friend istream& operator>>(istream& is, Book& b);
};

