// List342_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include <string>
//#include "List342.h"
//using namespace std;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LIST342.CPP <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//// This list contains the implimentaion for List342.h. It allows for objects to be created from a file, to be inserted, removed, peeked, lists to be deleted, lists checked to see if its empty, and lists to be merged
//// The operators allow for comparisons between various lists. It contains a copy constructor and a destructor for dynamically created objects.
//template <class ItemType>
//bool List342<ItemType>::BuildList(string fileName)
//{
//	ifstream in_file;
//
//	in_file.open(fileName);
//	if (in_file.is_open())
//	{
//		while (!in_file.eof()) // not at end of file
//		{
//			ItemType item;
//			in_file >> item;
//			this->Insert(item);
//		}
//		in_file.close();
//		return true;
//	}
//	else
//	{
//		cout << "File: " << fileName << " not found" << endl;
//		return false;
//	}
//	return true;
//}
//
//
//template <class ItemType>
//bool List342<ItemType>::Insert(ItemType* value)
//{
//	Node<ItemType>* newNode = new Node<ItemType>;
//	newNode->value = value;
//	newNode->next = nullptr;
//
//	if (head_ == nullptr) // case 1 - empty list
//	{
//		head_ = newNode;
//		return true;
//	}
//
//	if (*value < *head_->value) // Case 2 insert at first node
//	{
//		if (*head_->value == *value) // no duplicates
//		{
//			return false;
//		}
//		Node<ItemType>* ins_node = new Node<ItemType>;
//		ins_node->value = value;
//		ins_node->next = head_;
//		head_ = ins_node;
//		return true;
//	}
//	Node<ItemType>* p_node = head_;
//	while ((p_node->next != nullptr) && (*p_node->next->value < *value))
//	{
//		p_node = p_node->next;
//	}
//	if ((p_node->next != nullptr) && (*p_node->next->value == *value))
//	{
//		return false;
//	}
//	Node<ItemType>* ins_node = new Node<ItemType>;
//	ins_node->value = value;
//	ins_node->next = p_node->next;
//	p_node->next = ins_node;
//	return true;
//
//}
//
//template <class ItemType>
//bool List342<ItemType>::Remove(ItemType target, ItemType& result)
//{
//	bool deleted = false;
//
//	if (head_ == nullptr) // Case 1 - if list is empty
//	{
//		return false;
//	}
//	if (*head_->value == target) // Case 2 - check first item in list
//	{
//		Node<ItemType>* temp = head_;
//		head_ = head_->next;
//
//		result = *temp->value;
//		delete temp;
//		temp = NULL;
//		return true;
//	}
//	Node<ItemType>* p_node = head_;
//	while (p_node->next != nullptr && (*p_node->next->value < target)) // Case 3 - check the rest of the list.
//	{
//		p_node = p_node->next;
//	}
//	if ((p_node->next == nullptr) || (*p_node->next->value != target))// no duplicates
//	{
//		return false;
//	}
//	Node<ItemType>* temp = p_node->next;
//
//	result = *p_node->next->value;
//
//	p_node->next = p_node->next->next;
//	delete temp;
//	temp = NULL;
//	return true;
//}
//
//template <class ItemType>
//bool List342<ItemType>::Peek(ItemType target, ItemType& result) const
//{
//	Node<ItemType>* curr = new Node<ItemType>;
//	curr = head_;
//
//	bool deleted = false;
//
//	if (head_ == nullptr) // Case 1 - if list is empty
//	{
//		return false;
//	}
//	else
//	{
//		while (curr != nullptr) // Case 2 - check list         
//		{
//			if (*curr->value == target)
//			{
//				result = *curr->value;
//				return true;
//			}
//			else
//			{
//				curr = curr->next;
//			}
//		}
//	}
//	return false;
//}
//
//template <class ItemType>
//bool List342<ItemType>::isEmpty() const
//{
//	if (head_ == nullptr)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//template <class ItemType>
//void List342<ItemType>::DeleteList()
//{
//	while (!isEmpty())
//	{
//		Node<ItemType>* temp = head_;
//		head_ = head_->next;
//		delete temp;
//		temp = NULL;
//	}
//
//}
//
//template <class ItemType>
//bool List342<ItemType>::Merge(List342& list1)
//{
//	bool wasList = false;
//
//	if (list1.head_ == nullptr) // if inserting an empty list
//	{
//		return false;
//	}
//	if (*this == list1) // if both lists are equal
//	{
//		return this;
//	}
//	while (list1.head_ != nullptr) // go through list inserting to *this
//	{
//		wasList = true;
//		Node<ItemType>* temp = list1.head_;
//		this->Insert(list1.head_->value);
//		list1.head_ = list1.head_->next;
//		free(temp);
//	}
//	if (wasList == true)
//	{
//		return true;
//	}
//	return false;
//}
//
//
//
//template <class ItemType>
//List342<ItemType>::List342()
//{
//	head_ = nullptr;
//}
//
//template <class ItemType>
//List342<ItemType>::List342(const List342& rhs)
//{
//	head_ = nullptr;
//	*this = rhs;
//}
//
//template <class ItemType>
//List342<ItemType>::~List342()
//{
//	this->DeleteList();
//}
//
//template <class ItemType>
//ostream& operator<<(ostream& out_stream, const List342<ItemType>& the_stack)
//{
//
//	Node<ItemType>* pNode;
//	pNode = the_stack.head_;
//
//	if (pNode != nullptr)
//	{
//		out_stream << *pNode->value;
//	}
//	while (pNode->next != nullptr)
//	{
//		pNode = pNode->next;
//		out_stream << *pNode->value;
//
//	}
//	return out_stream;
//}
//
//
//template<class ItemType>
//List342<ItemType>& List342<ItemType>::operator+(const List342& rhs)
//{
//	List342<ItemType>* result = new List342<ItemType>;
//	*result += *this;
//	*result += rhs;
//	return *result;
//}
//
//template<class ItemType>
//List342<ItemType>& List342<ItemType>::operator+=(const List342& rhs)
//{
//	Node<ItemType>* traverse = rhs.head_;
//	while (traverse != nullptr)
//	{
//		this->Insert(traverse->value);
//		traverse = traverse->next;
//	}
//	return *this;
//}
//
//
//template <class ItemType>
//List342<ItemType>& List342<ItemType>::operator=(const List342& rhs)
//{
//	if (this == &rhs)
//	{
//		return *this;
//	}
//
//	this->DeleteList(); // Clear out all items in *this
//
//	Node<ItemType>* s_node = nullptr; // makes a deep copy
//	Node<ItemType>* d_node = nullptr;
//	Node<ItemType>* ins_node = nullptr;
//	if (rhs.head_ == nullptr)
//	{
//		return *this;
//	}
//	d_node = new Node<ItemType>;
//	d_node->value = (rhs.head_)->value;
//	this->head_ = d_node;
//
//	s_node = (rhs.head_)->next;
//	while (s_node != nullptr)
//	{
//		ins_node = new Node<ItemType>;
//		ins_node->value = s_node->value;
//		d_node->next = ins_node;
//		d_node = d_node->next;
//		s_node = s_node->next;
//		ins_node->next = nullptr;
//	}
//	return *this;
//}
//
//template<class ItemType>
//bool List342<ItemType>::operator==(const List342& rhs)
//{
//	Node<ItemType>* p_one = this->head_;
//	Node<ItemType>* p_two = rhs.head_;
//	bool check_list;
//
//	if (this->isEmpty() && rhs.isEmpty())
//	{
//		return true;
//	}
//
//	while ((p_one != nullptr) || (p_two != nullptr))
//	{
//		if (((p_one == nullptr) && (p_two != nullptr)) || ((p_one != nullptr) && (p_two == nullptr))) // if one node of same position is empty while the other is not
//		{
//			return false;
//		}
//
//		if (p_one->value == p_two->value)
//		{
//			check_list = true;
//		}
//		else
//		{
//			return false;
//		}
//
//		p_one = p_one->next;
//		p_two = p_two->next;
//	}
//
//	return check_list;
//}
//
//template<class ItemType>
//bool List342<ItemType>::operator!=(const List342& rhs)
//{
//	if (*this == rhs)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CHILD.CPP <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// Child.cpp contains the implementation for the child.h file. It can compare Child obects, initilize them, take them in as input as istream, and print them using ostream
//
//ostream& operator<<(ostream& out_stream, const Child& rhs)
//{
//	out_stream << rhs.first_name_ << "" << rhs.last_name_ << "" << rhs.age_;
//	return out_stream;
//}
//
//istream& operator>>(istream& in_stream, Child& rhs)
//{
//	in_stream >> rhs.first_name_;
//	in_stream >> rhs.last_name_;
//	in_stream >> rhs.age_;
//	return in_stream;
//}
//
//Child::Child(string first, string last, int age)
//{
//	first_name_ = first;
//	last_name_ = last;
//	age_ = age;
//}
//
//Child::Child()
//{
//	first_name_;
//	last_name_;
//	age_;
//}
//
//bool Child::operator<(Child& rhs) // order of importance: last_name > first_name > age
//{
//	if (last_name_ < rhs.last_name_)
//	{
//		return true;
//	}
//	if (last_name_ == rhs.last_name_)
//	{
//		if (first_name_ == rhs.first_name_)
//		{
//			if (age_ < rhs.age_)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		if (first_name_ < rhs.first_name_)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Child::operator<=(Child& rhs)
//{
//	if (first_name_ <= rhs.first_name_)
//	{
//		if (last_name_ <= rhs.last_name_)
//		{
//			if (age_ <= rhs.age_)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		else
//		{
//			return false;
//		}
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Child::operator==(Child& rhs)
//{
//	if ((first_name_ == rhs.first_name_) && (last_name_ == rhs.last_name_) && (age_ == rhs.age_))
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Child::operator!=(Child& rhs)
//{
//	if ((first_name_ == rhs.first_name_) && (last_name_ == rhs.last_name_) && (age_ == rhs.age_))
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< MAIN <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//int main()
//{
//    
//    Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8),
//        c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
//    Child c5("Piqi", "Tangi", 7), c6("Pete", "Rose", 13),
//        c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
//    Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
//    List342<Child> class1, class2, soccer, chess;
//    int a = 1, b = -1, c = 13;
//    
//    class1.Insert(&c1);     // Important: I had to take out the & part for all of these
//    class1.Insert(&c2);
//    class1.Insert(&c3);
//    class1.Insert(&c4);
//    class1.Insert(&c5);
//    class1.Insert(&c6);
//    class1.Insert(&c5);
//    cout << "class1: " << class1 << endl;
//    
//    if (class1.Insert(&c1)) 
//    { 
//        cout << "ERROR::: Duplicate" << endl; 
//    }
//
//    class2.Insert(&c4);
//    class2.Insert(&c5);
//    class2.Insert(&c6);
//    class2.Insert(&c7);
//    class2.Insert(&c10);
//    cout << "Class2: " << class2 << endl;
//
//    class1.Merge(class2);
//    class2.Merge(class1);
//    class1.Merge(class2);
//    class1.Merge(class1);
//    cout << "class1 and 2 Merged: " << class1 << endl;
//
//
//    if (!class2.isEmpty())
//    {
//        cout << "ERROR:: Class2 should be empty empty" << endl;
//    }
//
//    class1.Remove(c4, c11);
//    class1.Remove(c5, c11);
//    class1.Remove(c11, c11);
//    if (class1.Remove(c1, c11))
//    {
//        cout << "Removed from class1, student " << c11 << endl;
//    }
//    cout << "class1:" << class1 << endl;
//
//    soccer.Insert(&c6);
//    soccer.Insert(&c4);
//    soccer.Insert(&c9);
//    cout << "soccer:" << soccer << endl;
//    soccer += class1;
//    cout << "soccer += class1 : " << soccer << endl;
//
//    List342<Child> football = soccer;
//    
//    if (football == soccer)
//    {
//        cout << "football:" << football << endl;
//    }
//
//    if (football.Peek(c6, c11))
//    {
//        cout << c11 << " is on the football team" << endl;
//    }
//    
//
//    soccer.DeleteList();
//    if (!soccer.isEmpty())
//    {
//        cout << "ERROR:  soccer should be empty" << endl;
//    } 
//
//    List342<int> numbers;
//    numbers.Insert(&a);
//    numbers.Insert(&b);
//    numbers.Insert(&c);
//    cout << "These are the numbers: " << numbers << endl;
//    numbers.DeleteList();
//    return 0;
//}