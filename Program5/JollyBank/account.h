//account.h holds the blueprint for the account object. Each has a name and id, with vectors that hold fund amounts and fund history.

#pragma once
#include "fund.h"
#include <iostream>
#include <vector>
using namespace std;

class Account
{
public:
	Account(string first_name, string last_name, int id);
	
	string getFirstName();
	string getLastName();
	int getID();

	int getFunds(int accountType) const;
	string getFundNames(int accountType) const;

	void setFirstName(string first_name);
	void setLastName(string last_name);
	void setID(int id);

	void setFunds(int accountType, int value);
	void setHistory(int accountType, string transactionString);


	void printSpecificHistory(int account_type);
	void printHistory() const;
	void printAccount() const;

private:
	string first_name_;
	string last_name_;
	int id_;

	// checks if account has had transactions
	bool noTransactions = true;

	// corrosponds to funds (0-9)
	int accountType; 

	// Initializes Fund object
	Fund fund;
};

