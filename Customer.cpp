#include "Customer.h"
#include "Account.h"
#include "BankingSystem.h"


Customer::Customer()
{
	id = 0;
	name = "";
	surname = "";
	//headd = NULL;
	size = 0;
}

Customer::Customer(int id, string name, string surname)
{
	this->id = id;
	this->name = name;
	this->surname = surname;
	//headd = NULL;
	size = 0;
}


Customer::~Customer()
{
	//cout << "customer destructor" << endl;
}

Customer::Customer(const Customer &)
{
}

void Customer::operator =(const Customer &right)
{
	if (&right != this)
	{

		id = right.id;
		name = right.name;
		surname = right.surname;
	}

}

