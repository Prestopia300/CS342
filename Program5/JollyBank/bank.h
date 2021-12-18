//bank.h initializes bank functions and data members for the purpose of processing account transactions from a file
//to open accounts, deposit funds, withdraw funds, transfer funds, and display fund history

#pragma once
#include "account.h"
#include "bstree.h"
#include "transaction.h"
#include <iostream>
#include <queue>
using namespace std;
class Bank
{
public:
	Bank(string file_name);

	void open(string first_name, string last_name, int id);
	void deposit(int id, int account_type, int amount);
	void withdraw(int id, int account_type, int amount);
	void transfer(Account *fromAccount, Account *toAccount, int account_type_from, int account_type_to, int amount);
	
	void proccessTransactionFile();
	bool exception(int account_type, Account* accout, int amount);
	void output_Result();

private:
	string fileName;
	char transaction_type;
	
	queue<Transaction> transactions;

	vector<int> accountIds;

	BSTree accounts;
};

