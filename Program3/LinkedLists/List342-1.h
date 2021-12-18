//This is my List342.h file that holds all of my code with the exception of main, which is commented out in the .cpp file.

#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< List342.h <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// List342.h contains the blueprints for my singily linked list, which can be manuplated and is templatized to allow for different types of objects.

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include <iostream>
using namespace std;

template <class ItemType>
struct Node
{
	ItemType *value;
	Node* next;
};

template<class ItemType>
class List342
{
	template<class ItemType>
	friend ostream& operator<<(ostream& out_stream, const List342<ItemType>& the_stack);

public:
	List342();
	List342(const List342& rhs);
	~List342();

	bool BuildList(string fileName);
	bool Insert(ItemType *newEntry);
	bool Remove(ItemType target, ItemType& result);
	bool Peek(ItemType target, ItemType& result) const;
	bool isEmpty() const;
	void DeleteList();
	bool Merge(List342& list1);

	List342& operator+(const List342& rhs);
	List342& operator+=(const List342& rhs);
	List342& operator=(const List342& rhs);
	bool operator==(const List342& rhs);
	bool operator!=(const List342& rhs);

private:
	Node<ItemType>* head_;
};

#endif


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CHILD.H <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// This is a class that holds the blueprints for the Child object. This object can be compared with other objects of the same type using operators.

class Child
{
	friend ostream& operator<<(ostream& out_stream, const Child& rhs);
	friend istream& operator>>(istream& in_stream, Child& rhs);

public:
	Child();
	Child(string first, string last, int age);

	bool operator<(Child& rhs);
	bool operator<=(Child& rhs);
	bool operator==(Child& rhs);
	bool operator!=(Child& rhs);

private:
	string first_name_;
	string last_name_;
	int age_ = 9;
};

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< List342.cpp <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// This list contains the implimentaion for List342.h. It allows for objects to be created from a file, to be inserted, removed, peeked, lists to be deleted, lists checked to see if its empty, and lists to be merged
// The operators allow for comparisons between various lists. It contains a copy constructor and a destructor for dynamically created objects.
template <class ItemType>
bool List342<ItemType>::BuildList(string fileName)
{
	ifstream in_file;

	in_file.open(fileName);
	if (in_file.is_open())
	{
		while (!in_file.eof()) // not at end of file
		{
			ItemType item;
			in_file >> item;
			this->Insert(item);
		}
		in_file.close();
		return true;
	}
	else
	{
		cout << "File: " << fileName << " not found" << endl;
		return false;
	}
	return true;
}


template <class ItemType>
bool List342<ItemType>::Insert(ItemType *value)
{
	Node<ItemType>* newNode = new Node<ItemType>;
	newNode->value = value;
	newNode->next = nullptr;

	if (head_ == nullptr) // case 1 - empty list
	{
		head_ = newNode;
		return true;
	}

	if (*value < *head_->value) // Case 2 insert at first node
	{
		if (*head_->value == *value) // no duplicates
		{
			return false;
		}
		Node<ItemType>* ins_node = new Node<ItemType>;
		ins_node->value = value;
		ins_node->next = head_;
		head_ = ins_node;
		return true;
	}
	Node<ItemType>* p_node = head_;
	while ((p_node->next != nullptr) && (*p_node->next->value < *value))
	{
		p_node = p_node->next;
	}
	if ((p_node->next != nullptr) && (*p_node->next->value == *value))
	{
		return false;
	}
	Node<ItemType>* ins_node = new Node<ItemType>;
	ins_node->value = value;
	ins_node->next = p_node->next;
	p_node->next = ins_node;
	return true;

}

template <class ItemType>
bool List342<ItemType>::Remove(ItemType target, ItemType& result)
{
	bool deleted = false;

	if (head_ == nullptr) // Case 1 - if list is empty
	{
		return false;
	}
	if (*head_->value == target) // Case 2 - check first item in list
	{
		Node<ItemType>* temp = head_;
		head_ = head_->next;

		result = *temp->value;
		delete temp;
		temp = NULL;
		return true;
	}
	Node<ItemType>* p_node = head_;
	while (p_node->next != nullptr && (*p_node->next->value < target)) // Case 3 - check the rest of the list.
	{
		p_node = p_node->next;
	}
	if ((p_node->next == nullptr) || (*p_node->next->value != target))// no duplicates
	{
		return false;
	}
	Node<ItemType>* temp = p_node->next;

	result = *p_node->next->value;

	p_node->next = p_node->next->next;
	delete temp;
	temp = NULL;
	return true;
}

template <class ItemType>
bool List342<ItemType>::Peek(ItemType target, ItemType& result) const
{
	Node<ItemType>* curr = new Node<ItemType>;
	curr = head_;

	bool deleted = false;

	if (head_ == nullptr) // Case 1 - if list is empty
	{
		return false;
	}
	else
	{
		while (curr != nullptr) // Case 2 - check list         
		{
			if (*curr->value == target)
			{
				result = *curr->value;
				return true;
			}
			else
			{
				curr = curr->next;
			}
		}
	}
	return false;
}

template <class ItemType>
bool List342<ItemType>::isEmpty() const
{
	if (head_ == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class ItemType>
void List342<ItemType>::DeleteList()
{
	while (!isEmpty())
	{
		Node<ItemType>* temp = head_;
		head_ = head_->next;
		delete temp;
		temp = NULL;
	}

}

template <class ItemType>
bool List342<ItemType>::Merge(List342& list1)
{
	bool wasList = false;

	if (list1.head_ == nullptr) // if inserting an empty list
	{
		return false;
	}
	if (*this == list1) // if both lists are equal
	{
		return this;
	}
	while (list1.head_ != nullptr) // go through list inserting to *this
	{
		wasList = true;
		Node<ItemType>* temp = list1.head_;
		this->Insert(list1.head_->value);
		list1.head_ = list1.head_->next;
		free(temp);
	}
	if (wasList == true)
	{
		return true;
	}
	return false;
}



template <class ItemType>
List342<ItemType>::List342()
{
	head_ = nullptr;
}

template <class ItemType>
List342<ItemType>::List342(const List342& rhs)
{
	head_ = nullptr;
	*this = rhs;
}

template <class ItemType>
List342<ItemType>::~List342()
{
	this->DeleteList();
}

template <class ItemType>
ostream& operator<<(ostream& out_stream, const List342<ItemType>& the_stack)
{
	
	Node<ItemType>* pNode;
	pNode = the_stack.head_;

	if (pNode != nullptr)
	{
		out_stream << *pNode->value;
	}
	while (pNode->next != nullptr)
	{
		pNode = pNode->next;
		out_stream <<  *pNode->value;
		
	}
	return out_stream;
}


template<class ItemType>
List342<ItemType>& List342<ItemType>::operator+(const List342& rhs)
{
	List342<ItemType>* result = new List342<ItemType>;
	*result += *this;
	*result += rhs;
	return *result;
}

template<class ItemType>
List342<ItemType>& List342<ItemType>::operator+=(const List342& rhs)
{
	Node<ItemType>* traverse = rhs.head_;
	while (traverse != nullptr)
	{
		this->Insert(traverse->value);
		traverse = traverse->next;
	}
	return *this;
}


template <class ItemType>
List342<ItemType>& List342<ItemType>::operator=(const List342& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	
	this->DeleteList(); // Clear out all items in *this

	Node<ItemType>* s_node = nullptr; // makes a deep copy
	Node<ItemType>* d_node = nullptr;
	Node<ItemType>* ins_node = nullptr;
	if (rhs.head_ == nullptr)
	{
		return *this;
	}
	d_node = new Node<ItemType>;
	d_node->value = (rhs.head_)->value;
	this->head_ = d_node;

	s_node = (rhs.head_)->next;
	while (s_node != nullptr)
	{
		ins_node = new Node<ItemType>;
		ins_node->value = s_node->value;
		d_node->next = ins_node;
		d_node = d_node->next;
		s_node = s_node->next;
		ins_node->next = nullptr;
	}
	return *this;
}

template<class ItemType>
bool List342<ItemType>::operator==(const List342& rhs)
{
	Node<ItemType>* p_one = this->head_;
	Node<ItemType>* p_two = rhs.head_;
	bool check_list;

	if (this->isEmpty() && rhs.isEmpty())
	{
		return true;
	}
	
	while ((p_one != nullptr) || (p_two != nullptr))
	{
		if (((p_one == nullptr) && (p_two != nullptr)) || ((p_one != nullptr) && (p_two == nullptr))) // if one node of same position is empty while the other is not
		{
			return false;
		}
		
		if (p_one->value == p_two->value)
		{
			check_list = true;
		}
		else
		{
			return false;
		}

		p_one = p_one->next;
		p_two = p_two->next;
	}

	return check_list;
}

template<class ItemType>
bool List342<ItemType>::operator!=(const List342& rhs)
{
	if (*this == rhs)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CHILD.CPP <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Child.cpp contains the implementation for the child.h file. It can compare Child obects, initilize them, take them in as input as istream, and print them using ostream


ostream& operator<<(ostream& out_stream, const Child& rhs)
{
	out_stream << rhs.first_name_ << "" << rhs.last_name_ << "" << rhs.age_;
	return out_stream;
}

istream& operator>>(istream& in_stream, Child& rhs)
{
	in_stream >> rhs.first_name_;
	in_stream >> rhs.last_name_;
	in_stream >> rhs.age_;
	return in_stream;
}


Child::Child(string first, string last, int age)
{
	first_name_ = first;
	last_name_ = last;
	age_ = age;
}

Child::Child()
{
	first_name_;
	last_name_;
	age_;
}

bool Child::operator<(Child& rhs) // order of importance: last_name > first_name > age
{
	if (last_name_ < rhs.last_name_)
	{
		return true;
	}
	if (last_name_ == rhs.last_name_)
	{
		if (first_name_ == rhs.first_name_)
		{
			if (age_ < rhs.age_)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (first_name_ < rhs.first_name_)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Child::operator<=(Child& rhs)
{
	if (first_name_ <= rhs.first_name_)
	{
		if (last_name_ <= rhs.last_name_)
		{
			if (age_ <= rhs.age_)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Child::operator==(Child& rhs)
{
	if ((first_name_ == rhs.first_name_) && (last_name_ == rhs.last_name_) && (age_ == rhs.age_))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Child::operator!=(Child& rhs)
{
	if ((first_name_ == rhs.first_name_) && (last_name_ == rhs.last_name_) && (age_ == rhs.age_))
	{
		return false;
	}
	else
	{
		return true;
	}
}