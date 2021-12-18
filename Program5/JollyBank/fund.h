// fund.h holds the blueprint for the Fund object. It uses getter and setter functions to modify the object, and can display history and funds 
#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Fund
{
public:
	Fund();

	int getFunds(int accountType) const;
	string getFundNames(int accountType) const;
	string getHistory(int accountType) const;
	bool getFundHadTransactions(int accountType);

	void setFunds(int accountType, int value);
	void setHistory(int accountType, string transactionString);

	void printSpecificFundHistory(int account_type);
	void printFundHistory() const;
	void printAllFundHistory() const;

	bool noTransactons();


private:
	int accountType;
	bool noTransactions = true;

	vector<int> funds;
	vector<string> fundNames;
	vector<bool> fundHadTransaction;
	vector<string> history;
};