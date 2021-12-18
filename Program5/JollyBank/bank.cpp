// bank.cpp processes a transaction file, by creating transaction objects and using them to open accounts, deposit funds, withdraw funds, transfer funds, and display fund history
#include "bank.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Bank::Bank(string file_name)
{
	fileName = file_name;
}

void Bank::proccessTransactionFile() // Processes Transaction File and prints output
{
	ifstream MyReadFile;
	MyReadFile.open(fileName);

	if (MyReadFile.is_open()) {
		cout << "Read file: " << fileName << endl;
		string line;

		while (getline(MyReadFile, line)) { // Reads all transactions into the queue
			transaction_type = char(line[0]);
			Transaction transaction(line, transaction_type);			
			transactions.push(transaction);
		}
		MyReadFile.close();
		
		// transaction_manager
		while (!transactions.empty()) {
			Transaction transaction = transactions.front();
			
			if (transaction.getType() == 'O') // Open Account
			{ 
				open(transaction.getFirstName(), transaction.getLastName(), transaction.getID());
			}
			else if (transaction.getType() == 'D') // Deposit money
			{ 
				deposit(transaction.getID(), transaction.getAccountType(), transaction.getAmount());
			}
			else if (transaction.getType() == 'W') // Withdraw money 
			{
				withdraw(transaction.getID(), transaction.getAccountType(), transaction.getAmount());
			}
			else if (transaction.getType() == 'T') // Transfer money
			{
				Account* fromAccount;
				Account* toAccount;
				if (accounts.Retrieve(transaction.getIDFrom(), fromAccount) && accounts.Retrieve(transaction.getIdTo(), toAccount))
				{
					transfer(fromAccount, toAccount, transaction.getAccountTypeFrom(), transaction.getAccountTypeTo(), transaction.getAmount());
				}
			}
			else if (transaction.getType() == 'H') // Print History
			{ 
				Account* account;
				accounts.Retrieve(transaction.getID(), account);
				if (transaction.getAccountType() == NULL) // there is no account_type, so it needs to print all account history
				{
					account->printHistory();
				}
				else // there is accoun_type, so print the account_type fund of account
				{
					account->printSpecificHistory(transaction.getAccountType());
				}
			}

			transactions.pop();              
		}

		cout << "\n\n\n";
		output_Result(); // Print all accounts and their funds
	}
	else // file_name didn't work
	{
	cout << "Failed to open the file: " << fileName;
	}
}

bool Bank::exception(int account_type, Account* account, int amount) // allows withdraws from paired fund types (01 or 23)
{
	bool wasException = false;
	int total;
	if (account_type == 0) {
		if (amount > account->getFunds(0) + account->getFunds(1)) {
			return wasException;
		}
		else {
			total = account->getFunds(1) + account->getFunds(0) - amount; // updates both funds
			account->setFunds(1, total);
			account->setFunds(account_type, 0);
			
			Transaction t1 = transactions.front(); //update fund 0's transaction
			string line1 = "W " + to_string(t1.getID()) + to_string(t1.getAccountType()) + " " + to_string(account->getFunds(0));
			transactions.front().setTransactionString(line1);
			account->setHistory(0, line1);
			
			string line2 = "W " + to_string(account->getID()) + "1 " + to_string(total); // update fund 1's transaction
			account->setHistory(1, line2);

			wasException = true;
		}
	}
	else if (account_type == 1) {
		if (amount > account->getFunds(1) + account->getFunds(0)) {
			return wasException;
		}
		else {
			total = account->getFunds(0) - (amount - account->getFunds(1)); // updates both funds
			account->setFunds(0, total);
			account->setFunds(account_type, 0);

			Transaction t1 = transactions.front(); //update fund 1's transaction
			string line1 = "W " + to_string(t1.getID()) + to_string(t1.getAccountType()) + " " + to_string(account->getFunds(1));
			transactions.front().setTransactionString(line1);
			account->setHistory(1, line1);
			
			string line = "W " + to_string(account->getID()) + "0 " + to_string(total); // update fund 0's transaction
			account->setHistory(0, line);

			wasException = true;
		}
	}
	else if (account_type == 2) {
		if (amount > account->getFunds(2) + account->getFunds(3)) {
			return wasException;
		}
		else {
			total = account->getFunds(2) - (amount - account->getFunds(3)); // updates both funds
			account->setFunds(3, total);
			account->setFunds(account_type, 0);
			
			Transaction t1 = transactions.front(); //update fund 2's transaction
			string line1 = "W " + to_string(t1.getID()) + to_string(t1.getAccountType()) + " " + to_string(account->getFunds(0));
			transactions.front().setTransactionString(line1);
			account->setHistory(2, line1);
			
			string line = "W " + to_string(account->getID()) + "3 " + to_string(total); // update fund 3's transaction
			account->setHistory(3, line);

			wasException = true;
		}
	}
	else if (account_type == 3)
	{
		if (amount > account->getFunds(2) + account->getFunds(3)) {
			return wasException;
		}
		else {
			total = account->getFunds(2) - (amount - account->getFunds(3)); // updates both funds
			account->setFunds(2, total);
			account->setFunds(account_type, 0);
			
			Transaction t1 = transactions.front(); //update fund 3's transaction history
			string line1 = "W " + to_string(t1.getID()) + to_string(t1.getAccountType()) + " " + to_string(account->getFunds(0));
			transactions.front().setTransactionString(line1);
			account->setHistory(3, line1);
			
			string line = "W " + to_string(account->getID()) + "2 " + to_string(total); // update fund 2's transaction history
			account->setHistory(2, line);

			wasException = true;
		}
	}
	else // fund was 4-9
	{
		return false;
	}
	return wasException;
}

// Open: creates new account and inserts it into BSTree 
void Bank::open(string first_name, string last_name, int id)
{
	if ((id >= 1000) && (id <= 9999)) // handles Error: id is not 4 digits (when converted from a string, it must result in a 4 digit number)  
	{
		Account* newAccount = new Account(first_name, last_name, id); // inserts new account
		accounts.Insert(newAccount);
	}
	else
	{
		cout << "ERROR: ID is not the correct size" << endl; // executes error handling
	}
}

// Deposits money into a fund
void Bank::deposit(int id, int account_type, int amount)
{
	Account* account;
	int& number = id; // int -> int&
	accounts.Retrieve(number, account);
	
	if (amount < 0) // handles Error: deposit cannot be negative
	{
		cout << "ERROR: Deposit cannot be negative" << endl; // updates history
		transactions.front().appendTransactionString(" (failed)");
		account->setHistory(account_type, transactions.front().getTransactionString()); 
	}
	else // deposit money
	{
		int total = account->getFunds(account_type) + amount; // updates money
		account->setFunds(account_type, total);

		account->setHistory(account_type, transactions.front().getTransactionString()); // updates history
	}
}

void Bank::withdraw(int id, int account_type, int amount)
{
	Account* account;
	int& number = id; // int -> int&
	accounts.Retrieve(number, account);

	if (amount > account->getFunds(account_type)) // checks if fund doesn't have enought money 
	{
		if (exception(account_type, account, amount) == false) // checks if withdrawl can't be shared with a pair fund, if it can, exception has alread run and withdrawl has succeeded
		{
			transactions.front().appendTransactionString(" (failed)"); 
			cout << "ERROR: Not enough funds to withdraw " << amount << " from " << account->getFirstName() << " " << account->getLastName() << " " << account->getFundNames(account_type) << endl;
			account->setHistory(account_type, transactions.front().getTransactionString()); 
		}
	}
	else // withdrawl as normal
	{
		int total = account->getFunds(account_type) - amount; // updates money
		account->setFunds(account_type, total);
		account->setHistory(account_type, transactions.front().getTransactionString()); // updates history
	}
}

// Transfers money from one fund to another fund (can be same or multiple accounts)
void Bank::transfer(Account* fromAccount, Account* toAccount, int account_type_from, int account_type_to, int amount) 
{
	int from_acc = fromAccount->getID();
	int& id1 = from_acc;
	int to_acc = toAccount->getID();
	int& id2 = to_acc;
	Account* acc1;
	Account* acc2;

	if (accounts.Retrieve(id1, acc1) == false) // handeles Error: Account does not exist
	{
		cout << "Error: Account: " << id1 << " not found. Transferal refused" << endl;
		return;
	}
	if (accounts.Retrieve(id2, acc2) == false)
	{
		cout << "Error: Account: " << id2 << " not found. Transferal refused" << endl;
		return;
	}
	else // Transfer
	{
		int total1 = fromAccount->getFunds(account_type_from) - amount; // updates money for fund one
		fromAccount->setFunds(account_type_from, total1);

		int total2 = toAccount->getFunds(account_type_to) + amount; // updates money for fund two
		toAccount->setFunds(account_type_to, total2);

		fromAccount->setHistory(account_type_from, transactions.front().getTransactionString()); // updates history for both funds
		toAccount->setHistory(account_type_to, transactions.front().getTransactionString());
	}
}

void Bank::output_Result()
{
	cout << "Processing Done. Final Balances" << endl;
	accounts.Display();
}