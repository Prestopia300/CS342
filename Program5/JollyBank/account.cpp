// account.cpp holds the account object. Accounts contain a name and id, and creates a fund object that contains the accounts funds. Uses setters to modify the created fund object. 

#include "account.h"
#include <iostream>
using namespace std;


Account::Account(string first_name, string last_name, int id)
{
	first_name_ = first_name;
	last_name_ = last_name;
	id_ = id;
}

// Getters 

string Account::getFirstName()
{
	return first_name_;
}

string Account::getLastName()
{
	return last_name_;
}

int Account::getID()
{
	return id_;
}

int Account::getFunds(int accountType) const
{
	return fund.getFunds(accountType);
}

string Account::getFundNames(int accountType) const
{
	return fund.getFundNames(accountType);
}


// Setters

void Account::setFirstName(string first_name)
{
	first_name_ = first_name;
}

void Account::setLastName(string last_name)
{
	last_name_ = last_name;
}

void Account::setID(int id)
{
	id_ = id;
}

void Account::setFunds(int accountType, int value)
{
	fund.setFunds(accountType, value);
}

void Account::setHistory(int accountType, string transactionString)
{
	fund.setHistory(accountType, transactionString);
}


// Algorithmic Functions

void Account::printHistory() const // Prints entire Account history  for all funds that have had transactions
{
	cout << "Transaction History for " << first_name_ << " " << last_name_ << " by fund." << endl;
	fund.printFundHistory();
}

void Account::printSpecificHistory(int account_type) // Prints one fund's history
{
	cout << "Transacton History for " << first_name_ << " " << last_name_ << " " << fund.getFundNames(account_type) << " $" << fund.getFunds(account_type);
	fund.getHistory(account_type);
	cout << endl;
}

void Account::printAccount() const // Prints all account funds
{
	cout << first_name_ << " " << last_name_ << " Account ID: " << id_;
	fund.printAllFundHistory();
}