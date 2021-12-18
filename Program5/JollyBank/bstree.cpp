// bstree.cpp creates a binary search tree, and can inert, retrieve, flush, and display accounts in the tree. It can also check if the BSTree is empty and utilizes a destructor to delete BSTree when process is complete

#include "bstree.h"
#include <iostream>
#include <string>
using namespace std;

BSTree::BSTree()
{
	root = new Node;
	root->p_account = nullptr;
	root->right = nullptr;
	root->left = nullptr;
}

BSTree::~BSTree()
{
	Flush();

	root = NULL;
	delete root;
}

bool BSTree::Insert(Account* the_account) // Inserts account into tree sorted by account ID
{
	
	if (isEmpty()) {
		root->p_account = the_account;
		return true;
	}
	else 
	{
		Node* nNode = new Node;
		nNode->p_account = the_account;
		nNode->right = nullptr;
		nNode->left = nullptr;

		Node* curr = root;
		Node* parent = nullptr;

		// traverse the tree and find parent node of key
		while (curr != nullptr)
		{
			// update parent node as current node
			parent = curr;

			// if given key is less than the current node, go to left subtree
			if (the_account->getID() == curr->p_account->getID()) {
				cout << "ERROR: Account " + to_string(the_account->getID()) +
					" is already open. Transaction refused." << endl;
				nNode = NULL;
				delete nNode;
				return false;
			}
			else if (the_account->getID() < curr->p_account->getID()) { // go left
				curr = curr->left;
			}
			else // go right
			{
				curr = curr->right;
			}
		}

		// assign nNode to appropirate parent pointer
		if (the_account->getID() < parent->p_account->getID()) {
			parent->left = nNode;
		}
		else
		{
			parent->right = nNode; 
		}
	}
	return true;
}

bool BSTree::Retrieve(int acct_number, Account *&the_account) // retrives account as the_account
{
	return Retrieve(root, acct_number, the_account); 
}

bool BSTree::Retrieve(Node* curr, int acct_number, Account*& the_account)
{	
	if (curr == nullptr) // handles Error: account not found in tree
	{
		cout << "ERROR: Account " << acct_number << " not found. Transferal refused." << endl;
		return false;
	}
	else if (curr->p_account->getID() == acct_number) // retrieve
	{
		the_account = curr->p_account;
		return true;
	}
	
	if (curr->p_account->getID() < acct_number) // look right
	{
		Retrieve(curr->right, acct_number, the_account);
	}
	else // look left
	{
		Retrieve(curr->left, acct_number, the_account);
	}
}


void BSTree::Display()  
{
	Display(root); // runs Display recursive function
}

void BSTree::Display(Node *curr) // displays all accounts in sorted tree from left to right
{
	if (root != nullptr) 
	{
		if (curr->left != nullptr) 
		{
			Display(curr->left);
		}

		curr->p_account->printAccount();

		if (curr->right != NULL) 
		{
			Display(curr->right);
		}
	}
	else
	{
		cout << "The tree is empty" << endl;
	}
}

// delete all information in AccountTree
void BSTree::Flush() 
{
	Flush(root);
}

void BSTree::Flush(Node* curr)
{
	if (curr == nullptr) return;

	Flush(curr->left);
	Flush(curr->right);
	
	curr = NULL;
	delete curr;
	
}

bool BSTree::isEmpty() const
{
	return root->p_account == nullptr;
}