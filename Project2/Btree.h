#pragma once
#include<iostream>
#include "LibraryDataStructure.h"
using namespace std;

template<class T>
class BTree : public LibraryDataStructure<T>
{
private:
	class BNode
	{
	public:
		//sadot
		int m;		//max num of records in node +1
		T* records;
		BNode** sons;
		BNode* parent;
		int numOfRecords;
		int numOfSons;
		//methods
		BNode(int _m);
		~BNode();
		bool isLeaf();
		void insert(T record);
		void remove(T record);
		void printKeys();
	};
	int m;
	BNode* root;

	void clear(BNode* current);
	void inorder(BNode* current);
	BNode* findAddNode(BNode* current, T record);
	void split(BNode* current);
	T* search(BNode* current, int key, int& counter);
public:
	BTree(int degree);
	~BTree();
	void inorder();
	void insert(T record);
	T* search(int key);


};
////////////////////////////////////////////////////////////////

template<class T>
BTree<T>::BNode::BNode(int _m)
{
	this->m = _m;		//max num of records in node +1
	T* records = new T[m];
	BNode** sons = new BNode[][m + 1];
	BNode* parent = nullptr;
	int numOfRecords = 0;
	int numOfSons = 0;
	//TODO: fix
}

template<class T>
BTree<T>::BNode::~BNode()
{
	delete[] records;
	for (int i = 0; i < numOfRecords; i++)
	{
		delete sons[i];
	}
	delete[] sons;

	//TODO: fix
}

template<class T>
bool BTree<T>::BNode::isLeaf()
{
	if (numOfSons == 0) return true;
	return false;
	//TODO: fix
}

template<class T>
void BTree<T>::BNode::insert(T record)
{
	for (int i = 0; i < numOfRecords; i++)
	{
		if (records[i] > record)
		{

			T temp = records[i];
			records[i] = record;
			for (int j = i + 1; j < numOfRecords + 1; j++)
			{
				T temp2 = records[j];
				records[j] = temp;
				temp = temp2;
			}
			numOfRecords++;
			return;
		}
	}
	records[numOfRecords] = record;
	numOfRecords++;
	//TODO: fix
}

template<class T>
void BTree<T>::BNode::remove(T record)
{
	for (int i = 0; i < this->numOfRecords; i++)
	{
		if (records[i] == record)
		{
			int j = i;
			while (j < this->numOfRecords - 1)
			{
				records[j] = records[j + 1];
				j++;
			}
			numOfRecords--;
			return;
		}
	}

	//TODO: fix
}

template<class T>
void BTree<T>::BNode::printKeys()
{
	cout << '(';
	for (int i = 0; i < numOfRecords - 1; i++)
	{
		cout << records[i].getKey() << ",";
	}
	cout << records[numOfRecords - 1].getKey() << ')' << endl;
}


template<class T>
BTree<T>::BTree(int degree) :m(degree), root(nullptr) {}


template<class T>
void BTree<T>::insert(T record)
{
	// TODO: fix
}


//private recursive help fuctions
template<class T>
void BTree<T>::clear(BNode* current)
{
	if (current == nullptr)
		return;
	if (current->isLeaf()) //whithout sons
	{
		current->~BNode();
		return;
	}
	for (int i = 0; i < current->numOfSons; i++) //because postorder is: left-right-current
	{
		clear(current->sons[i]);
	}

	current->~BNode(); //in the end delete this b-node

	// TODO: fix
}

template<class T>
BTree<T>::~BTree()
{
	clear(this->root);
	// TODO: fix
}


template<class T>
void BTree<T>::inorder(BNode* current)
{
	if (current == nullptr)
		return;
	if (current->isLeaf())
	{
		current->printKeys();
		return;
	}

	for (int i = 0; i < current->numOfSons; i++) //inorder: left-current-right
	{
		inorder(current->sons[i]);
		current->printKeys();
	}

	// TODO: fix
}

template<class T>
void BTree<T>::inorder()
{
	inorder(this->root);
	// TODO: fix
}

template<class T>
typename BTree<T>::BNode* BTree<T>::findAddNode(BNode* current, T record)
{
	if (current == nullptr)
		return nullptr;

	if (current->isLeaf())
		return current;

	for (int i = 0; i < current->numOfRecords; i++)
	{
		if (record < current->records[i]) //record smallest 
		{
			return findAddNode(current->sons[i], record);
		}
	}

	//if record biggest 
	return findAddNode(current->sons[current->numOfRecords], record);

	// TODO: fix
}

template <class T>
void BTree<T>::split(BNode* current)
{
	int num;
	if ((this->m) % 2 == 0) //if m is zugi
		num = (this->m) / 2;
	else // if m is ei-zugi
		num = (this->m) / 2 + 1;


	BNode* ptr = new BNode();
	ptr = current->records[num - 1];
	ptr->parent = current->parent;

	for (int i = 0; i < current->numOfRecords; i++)
	{
		if (i < num - 1)
		{
			ptr->sons[i] = current->records[i];


		}
		else if (i > num - 1)
		{
			ptr->sons[i - 1] = current->records[i];


		}
	}

	delete[] current;
	current = ptr; //current now point on new tree.
	for (int i = 0; i < ptr->numOfSons; i++)
	{


	}

	// TODO: fix
}


template<class T>
T* BTree<T>::search(BNode* current, int key, int& counter)
{
	counter++;
	for (int i = 0; i < current->numOfRecords; i++)
	{
		if (key == current->records[i].getKey())
		{
			T* ptr = (T*)current;
			return ptr;
		}
		if (key < current->records[i].getKey())
		{
			return search(current->sons[i], key, counter);
		}
	}
	//if key not exiest in this node. 
	return search(current->sons[current->numOfRecords], key, counter);
	// TODO: fix
	return nullptr;
}

template<class T>
T* BTree<T>::search(int key) {

	int counter = 0;
	T* ptr = search(this->root, key, counter);

	cout << "The search involved scanning " << counter << " nodes" << endl;


	if (ptr == nullptr)
		return nullptr;
	return ptr;

	// TODO: fix

}

