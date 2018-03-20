#include "Account.h"
#include "BankingSystem.h"
#include "Customer.h"



Account::Account()
{
	id = 0;
	deposit = 0;
}

Account::Account(int id, int deposit)
{
	this->id = id;
	this->deposit = deposit;
}

Account::~Account()
{
	//cout << "account destr" << endl;
}


void Account::operator =(const Account &right)
{
	if (&right != this)
	{

		id = right.id;
		deposit = right.deposit;
	}

}