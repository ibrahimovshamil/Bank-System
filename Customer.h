#pragma once
#include<string>
#include <iostream>
using namespace std;
#include "Account.h"

class Customer
{
public:
	int id;
	string name;
	string surname;
	int size;
public:
	Customer();
	Customer(int id, string name, string surname);
	~Customer();
	Customer(const Customer &);
	void operator =(const Customer &);
};

