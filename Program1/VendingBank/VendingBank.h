#pragma once
#include <iostream>
using namespace std;

class VendingBank
{

public:
	VendingBank(double money); 
	VendingBank();
	

	int GetVendingBankID() const; 
	int GetBankTotalMoney() const;

	int GetCustomerID() const;
	int GetCustomerPayment() const;
	int GetAllItemsCost() const;
	
	bool SetCustomerID(int customer_id); 
	int SetCustomerPayment(int customer_payment);
	
	
	bool CheckPaymentAmount() const; 

	bool operator==(const VendingBank&); 
	bool operator!=(const VendingBank&);
	VendingBank operator+(const VendingBank&);
	VendingBank operator-(const VendingBank&);
	VendingBank operator+=(const VendingBank&); 
	VendingBank operator-=(const VendingBank&);

	friend ostream& operator<<(ostream& out_stream, const VendingBank& vending_bank);
	friend istream& operator>>(istream& in_stream, VendingBank& vending_bank);

private:
	int customer_payment_;
};