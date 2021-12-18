// fund.cpp holds the Fund object. Fund holds a vector with 10 funds, and a vector for transaction history for each fund. It uses getter and setter functions to modify the object, and can display history and funds 

#include "fund.h"
using namespace std;
Fund::Fund()
{
	for (int i = 0; i < 10; i++) // Initialize each vector's size
	{
		funds.push_back(0);
		history.push_back("\t");
		fundHadTransaction.push_back(false);
	}

	// Initialize fundNames vector (doesn't change
	fundNames =
	{
		"Money Market", "Prime Money Market", "Long Term Bond", "Short Term Bond", "500 Index Fund",
		"Capital Value Fund", "Growth Equity Fund", "Growth Index Fund", "Value Fund", "Value Stock Index"
	};
}

// Getters

int Fund::getFunds(int accountType) const
{
	return funds[accountType];
}

string Fund::getFundNames(int accountType) const
{
	return fundNames[accountType];
}

string Fund::getHistory(int accountType) const
{
	return history[accountType];
}

bool Fund::getFundHadTransactions(int accountType)
{
	return fundHadTransaction[accountType];
}

// Setters

void Fund::setFunds(int accountType, int value)
{
	funds[accountType] = value;
	noTransactions = false;
	fundHadTransaction[accountType] = true;
}

void Fund::setHistory(int accountType, string transactionString) // updates history vector
{
	history[accountType].append("\n  ");
	history[accountType].append(transactionString);
}

void Fund::printSpecificFundHistory(int account_type)
{
	cout << history[account_type] << endl;
}

void Fund::printFundHistory() const
{
	for (int i = 0; i < 10; i++)
	{
		if (fundHadTransaction[i])
		{
			cout << fundNames[i] << ": $" << funds[i];
			cout << history[i] << endl;
		}
	}
}

void Fund::printAllFundHistory() const
{
	for (int i = 0; i < 10; i++)
	{
		cout << "\n    " << fundNames[i] << ": $" << funds[i];
	}
	cout << "\n\n";
}

bool Fund::noTransactons()
{
	return noTransactions;
}