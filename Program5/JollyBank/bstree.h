// bstree.h initializes bstree functions and member variables for the purpose of processing accounts in a binary search tree

#pragma once
#include <iostream>
#include "account.h"
using namespace std;
class BSTree
{
private:
	struct Node
	{
		Account* p_account;
		Node* right;
		Node* left;
	};
	Node* root = nullptr;

public:
	BSTree();
	~BSTree();

	bool Insert(Account* the_account);
	
	bool Retrieve(int acct_number, Account*& the_account);
	bool Retrieve(Node *curr, int acct_number, Account*& the_account);

	void Display();
	void Display(Node *curr);

	void Flush();
	void Flush(Node* curr);

	bool isEmpty() const;
};

