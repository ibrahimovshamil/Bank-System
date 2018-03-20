#pragma once
class Account
{
public:
	int id;
	int deposit;
public:
	Account();
	Account(int id, int deposit);
	~Account();
	void operator =(const Account &right);
};

