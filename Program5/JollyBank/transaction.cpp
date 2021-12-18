// transaction.cpp processes a transaction string, and makes the appropriate member variables as a result of the type of transaction. Getters can return member variables, and the transaction string can be modified
#include "transaction.h"
#include "bstree.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Transaction::Transaction(string transaction, char type)
{	
	type_ = type;
	transaction_string = transaction;
	
	stringstream ss(transaction);
	string item;
	while (getline(ss, item, ' ')) // Uses ' ' to seperate elements of a transaction string into elems vector 
	{  
		elems.push_back(item);
	}


	if (type_ == 'O') // Creates Open Account Transaction data members
	{  
		last_name_ = elems[1];
		first_name_= elems[2];
		id_ = stoi(elems[3]);
	}
	else if (type_ == 'D') // Creates Deposit Transaction data members
	{
		
		id_ = stoi(elems[1].substr(0, 4));
		account_type_ = stoi(elems[1].substr(4));
		amount_ = stoi(elems[2]);
	}
	else if (type_ == 'W') // Creates Withdrawl Transaction data members
	{
		id_ = stoi(elems[1].substr(0, 4));
		account_type_ = stoi(elems[1].substr(4));
		amount_ = stoi(elems[2]);
	}
	else if (type_ == 'T') // Creates Transfer Transaction data members
	{
		id_from_ = stoi(elems[1].substr(0, 4));
		account_type_from_ = stoi(elems[1].substr(4));
		amount_ = stoi(elems[2]);
		id_to_ = stoi(elems[3].substr(0, 4));
		account_type_to_ = stoi(elems[3].substr(4));
	}
	else if (type_ == 'H') { // Creates History Transaction data members

		if (elems[1].length() == 4) // for displaying history for all funds
		{
			id_ = stoi(elems[1]);
		}
		else if (elems[1].length() == 5) // for displaying history for 1 fund
		{
			id_ = stoi(elems[1].substr(0,4));
			account_type_ = stoi(elems[1].substr(4));
		}
	}
}

// Getters

char Transaction::getType()
{
	return type_;
}

string Transaction::getFirstName()
{
	return first_name_;
}

string Transaction::getLastName()
{
	return last_name_;
}

int Transaction::getID()
{
	return id_;
}

int Transaction::getAccountType()
{
	return account_type_;
}

int Transaction::getAmount()
{
	return amount_;
}

int Transaction::getIDFrom()
{
	return id_from_;
}

int Transaction::getAccountTypeFrom()
{
	return account_type_from_;
}

int Transaction::getIdTo()
{
	return id_to_;
}

int Transaction::getAccountTypeTo()
{
	return account_type_to_;
}

string Transaction::getTransactionString()
{
	return transaction_string;
}

// Setters

void Transaction::appendTransactionString(string transaction_str)
{
	transaction_string = transaction_string + transaction_str;
}

void Transaction::setTransactionString(string transact)
{
	transaction_string = transact;
}
