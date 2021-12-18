// transacion.h initilizes transaction functions and member variables for the purpose of creating (and modifying) transaction objects.
#pragma once
#include "account.h"
#include <iostream>
using namespace std;

class Transaction
{
public:
	Transaction(string transaction, char type);

	char getType();
	string getFirstName();
	string getLastName();
	int getID();

	int getAccountType();
	int getAmount();

	int getIDFrom();
	int getAccountTypeFrom();
	int getIdTo();
	int getAccountTypeTo();

	string getTransactionString();
	void appendTransactionString(string transaction_str);
	void setTransactionString(string transact);
	
private:
	string transaction_string;
	char type_;

	string first_name_;
	string last_name_;
	int id_;
	
	int account_type_ = NULL;
	int amount_;

	int id_from_;
	int account_type_from_;
	int id_to_;
	int account_type_to_;

	vector<string> elems;
};

