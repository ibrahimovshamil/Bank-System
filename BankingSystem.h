#pragma once
#include "Customer.h"
class BankingSystem
{
public:
	BankingSystem();
	~BankingSystem();
	void addCustomer(const int customerId, const string firstName, const string lastName);
	void deleteCustomer(const int customerId);
	int addAccount(const int customerId, const double amount);
	void deleteAccount(const int accountId);
	void showAllAccounts();
	void showAllCustomers();
	void showCustomer(const int customerId);
public:
	struct Nodee
	{
		Account item;
		Nodee *next;
	};

public:
	struct Node
	{
		Customer item;
		Node *next;
		Nodee *head2 = NULL;
	};

	Node *head;

public:
	int size;
};


