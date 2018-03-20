#include "BankingSystem.h"
#include "Customer.h"
#include "Account.h"
using namespace std;
#include <string>
#include <iostream>
#include <stdlib.h>


BankingSystem::BankingSystem()
{
	head = NULL;
	size = 0;
}


BankingSystem::~BankingSystem()
{
	while (head != NULL)
	{
		Node *cur = head;
		head = head->next;
		cur->next = NULL;
		delete cur;
		cur = NULL;
	}
}


void BankingSystem::addCustomer(const int customerId, const string firstName, const string lastName)
{
	int i = 0;
	bool flag2 = true;
	bool flag3 = true;

	for (Node* newCurr = head; newCurr != NULL; newCurr = newCurr->next)
	{
		if (newCurr->item.id == customerId)
			flag2 = false;
	}


	for (Node* newCurr = head; newCurr != NULL; newCurr = newCurr->next)
	{
		if (newCurr->item.name == firstName && newCurr->item.surname == lastName)
			flag3 = false;
	}



	if (flag2 == true && flag3 == true)
	{
		for (Node* newCurr = head; newCurr != NULL; newCurr = newCurr->next)
		{
			if (newCurr->item.surname == lastName)
			{
				if (firstName > newCurr->item.name)
				{
					
						Customer A;
						A.id = customerId;
						A.name = firstName;
						A.surname = lastName;

						Node *newPtr = new Node;
						newPtr->next = newCurr->next;
						newCurr->next = newPtr;
						newPtr->item = A;
						cout << "Customer  " << customerId << " has been added" << endl;
						return;
				}

			}


		}
		cout << "Customer  " << customerId << " has been added" << endl;
		bool flag = true;

		if (head == NULL)
		{
			Customer A;
			A.id = customerId;
			A.name = firstName;
			A.surname = lastName;

			Node *newPtr = new Node;
			newPtr->next = head;
			head = newPtr;
			newPtr->item = A;
		}
		else if (size == 1)
		{
			if (lastName > head->item.surname)
			{
				Customer A;
				A.id = customerId;
				A.name = firstName;
				A.surname = lastName;

				Node *newPtr = new Node;
				newPtr->item = A;
				head->next = newPtr;
				newPtr->next = NULL;
			}
			else
			{
				Customer A;
				A.id = customerId;
				A.name = firstName;
				A.surname = lastName;

				Node *newPtr = new Node;
				newPtr->next = head;
				head = newPtr;
				newPtr->item = A;
			}


		}
		else if (size > 1)
		{
			Node*cur = head;

			while (cur->next != NULL)
			{
				//cout << "whilin ici" << endl;

				if (lastName > cur->item.surname && lastName < cur->next->item.surname)
				{
					//cout << "burdayam" << endl;
					Customer A;
					A.id = customerId;
					A.name = firstName;
					A.surname = lastName;

					Node *newPtr = new Node;
					newPtr->next = cur->next;
					cur->next = newPtr;
					newPtr->item = A;

					flag = false;
					return;
					//cout << "falg false" << endl;

				}
				cur = cur->next;
			}

			if (flag == true)
			{
				Node *cur = head;
				int i = 0;
				int b = 0;
				for (Node *newCur = head; newCur != NULL; newCur = newCur->next)
					b++;

				while (i  < b - 1)
				{
					cur = cur->next;
					i++;
				}

				Customer A;
				A.id = customerId;
				A.name = firstName;
				A.surname = lastName;


				Node *newPtr = new Node;
				newPtr->item = A;
				Node *prev = cur;
				newPtr->next = prev->next;
				prev->next = newPtr;
			}

		}

		size++;
	}
	else if (flag2 == false)
	{
		cout << "Customer " << customerId << " already exists" << endl;
		return;
	}

	else if (flag3 == false)
	{
		cout << "Customer " << firstName << " " << lastName << " already exists" << endl;
		return;
	}
}


void BankingSystem::deleteCustomer(const int customerId)
{
	//cout << "********" << endl;
	bool flag = true;
	bool flag2 = true;
	Node *prev = head;
	int a = 0;

	for (Node* newCurr = head; newCurr != NULL; newCurr = newCurr->next)
	{
		if (newCurr->item.id == customerId)
			flag = false;
	}

	if (flag == false)
	{
		for (Node *mainCur = head; mainCur->item.id != customerId; mainCur = mainCur->next)
			a++;

		//cout << a << size << "size" << endl;

		if (a == size - 1)
		{
			Node* currNode = head;
			while (currNode->next != NULL && currNode->next->next != NULL)
			{
				currNode = currNode->next;
			}
			delete currNode->next;
			currNode->next = NULL;
		}

		else if (a == 0)
		{
			cout << "burdayam" << endl;
			Node *newPtr = new Node;
			newPtr = head;
			head = head->next;
			newPtr->next = NULL;
			delete newPtr;
			newPtr = NULL;
		}

		else
		{
			//cout << "elsin icindeyem" << endl;
			Node* currNode = head->next;
			Node* prv = head;

			while (currNode->next != NULL && currNode->next->next != NULL)
			{
				if (currNode->item.id == customerId)
				{
					prv->next = currNode->next;
					Node *newOne = new Node;
					newOne = currNode;
					currNode = currNode->next;
					newOne->next = NULL;
					delete newOne;
					newOne = NULL;
				}

				currNode = currNode->next;
				prv = prv->next;
			}
			cout << "Customer  " << customerId << "has been deleted" << endl;
			return;
		}
		cout << "Customer  " << customerId << "has been deleted" << endl;
		return;
	}
	else if (flag == true)
	{
		cout << "Customer " << customerId << " does not exist" << endl;
		return;
	}

}
/*void BankingSystem::deletefirst()
{
	Node *newPtr = new Node;
	newPtr = head;
	head = head->next;
	newPtr->next = NULL;
	delete newPtr;
	newPtr = NULL;
}*/
int BankingSystem::addAccount(const int customerId, const double amount)
{
	Node* cur = head;
	bool flag = true;
	bool flag2 = true;

	for (Node* newCurr = head; newCurr != NULL; newCurr = newCurr->next)
	{
		if (newCurr->item.id == customerId)
			flag2 = false;
	}

	if (flag2 == false)
	{
		while (cur != NULL && cur->item.id != customerId)
			cur = cur->next;

		//cout<< cur->item.id << "ID si burda MAIN" << endl;//customeri taptim cur customer burda

		int iSecret = rand() % 1000000 + 1;
		Account A;
		A.deposit = amount;
		A.id = iSecret;

		if (cur->head2 == NULL) {
			//cout << "burda NULLdi" << endl;

			Nodee *newptr = new Nodee;
			cur->head2 = newptr;
			newptr->item = A;
			newptr->next = NULL;
			cur->item.size++; //ok
			cout << "Account " << iSecret << " added for customer " << cur->item.id << endl;
			return iSecret;
		}

		if (cur->item.size == 1)
		{
			cout << "sizim bir oldu" << endl;
			if (cur->head2->item.id < iSecret)
			{
				//cout << "brda deyilem" << endl;
				Nodee *newptr = new Nodee;
				newptr->item = A;
				cur->head2->next = newptr;
				newptr->next = NULL;
				cur->item.size++;
				cout << "Account " << iSecret << " added for customer " << cur->item.id << endl;
				return iSecret;
			}
			else
			{
				//cout << "elsedeyem baxxx" << endl;
				Nodee *newPtr = new Nodee;
				newPtr->next = cur->head2;
				cur->head2 = newPtr;
				newPtr->item = A;
				//newPtr->next->next = NULL;// sual atindan ????????????????????????
				cur->item.size++;
				cout << "Account " << iSecret << " added for customer " << cur->item.id << endl;
				return iSecret;
			}
		}

		if (cur->item.size > 1)
		{
			//cout << "aha birden boyuktu" << endl;

			Nodee *cure = cur->head2;
			while (cure->next != NULL)
			{
				//cout << "belke whilin icindeyem" << endl;

				//cout << cure->item.id << "ahaaa"<<endl;

				if (iSecret > cure->item.id  && iSecret < cure->next->item.id)
				{
			
					Nodee *newPtr = new Nodee;

					newPtr->next = cure->next;
					cure->next = newPtr;
					newPtr->item = A;
					flag = false;
					cur->item.size++;
					cout << "Account " << iSecret << " added for customer " << cur->item.id << endl;
					return iSecret;
				}

				
				cure = cure->next;
			}

			if (flag == true)
			{
				int i = 0;
				int b = 0;

				for (Nodee *newCur = cur->head2; newCur != NULL; newCur = newCur->next)
					b++;
				
				Nodee *cure = cur->head2;
				

				while (i < b - 1)
				{
					cure = cure->next;
					i++;
				}

				
				Nodee *newPtr = new Nodee;
				newPtr->item = A;
				cure->next = newPtr; 
				newPtr->next = NULL;
				cur->item.size++;
				
				cout << "Account " << iSecret << " added for customer " << cur->item.id << endl;
				return iSecret;
			}
		}
		return iSecret;
	}
	else
	{
		cout << "Customer " << customerId << " does not exist" << endl;
		return -1;
	}


}
void BankingSystem::deleteAccount(const int accountId)
{
	bool flag = true;

	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		
		if (cur->head2 != NULL)
		{
			//cout << "forun icindeki if" << endl;
			for (Nodee *cure = cur->head2; cure != NULL; cure = cure->next)
			{
				if (cure->item.id == accountId)
				{
					//flag = false;

					int i = 0;
							for (Nodee *cure = cur->head2; cure->item.id != accountId; cure = cure->next)
							{
								i++;
							}


							if (i + 1 == size)
							{
								//cout << "burdayam ??" << endl;
								Nodee *currNodee = cur->head2;

								while (currNodee->next != NULL && currNodee->next->next != NULL)
								{
									currNodee = currNodee->next;
								}
								delete currNodee->next;
								currNodee->next = NULL;
								cout << "Account " << accountId << " has been deleted" << endl;
								return;
							}

							else if (i == 0)
							{
								Nodee *newPtr = new Nodee;
								newPtr = cur->head2;
								cur->head2 = cur->head2->next;
								newPtr->next = NULL;
								delete newPtr;
								newPtr = NULL;
								cout << "Account " << accountId << " has been deleted" << endl;
								return;
							}

							else
							{
								//cout << "etaga burdayam" << endl;

								Nodee *cNodee = cur->head2->next;
								Nodee *prv = cur->head2;
								while (cNodee->next != NULL && cNodee->next->next != NULL)
								{
									if (cNodee->item.id == accountId)
									{
										prv->next = cNodee->next;
										Nodee *newOne = new Nodee;
										newOne = cNodee;
										cNodee = cNodee->next;
										newOne->next = NULL;
										delete newOne;
										newOne = NULL;
									}

									cNodee = cNodee->next;
									prv = prv->next;
								}
								cout << "Account " << accountId << " has been deleted" << endl;
								return;
							}
				}
			}
		}
	}

	if (flag == true)
		cout << "not such an account" << endl;
}
void BankingSystem::showAllAccounts()
{
	cout << "SHOWING ALL ACOUNTS HUHUHUHUHHUHUHHUHUHUH" << endl;
	cout << "Account id    Customer id     Customer name      Balance" << endl;

	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		if (cur->head2 != NULL)
		{
			
			for (Nodee *cure = cur->head2; cure != NULL; cure = cure->next)
			{
				cout << cure->item.id << "     " << cur->item.id << "    " <<cur->item.name<<"    "<<cur->item.surname <<"   "<< cure->item.deposit<< endl;
			}
		}
	
	}
}
void BankingSystem::showAllCustomers()
{
	cout << "Customer id        Customer name" << endl;

	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		cout << cur->item.id << "                " << cur->item.name << "  "<< cur->item.surname<< endl;
	}
}
void BankingSystem::showCustomer(const int customerId)
{
	bool flag = true;

	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		if (cur->item.id == customerId)
		{
			flag = false;
			cout << "Customer id  " << cur->item.id << "    Customer name: " << cur->item.name << " " << cur->item.surname << "      Number of accounts: " << cur->item.size-1 << endl;
			if (cur->item.size-1 > 0)
			{
				cout << "Accounts of this customer:" << endl;
				cout << "Account id     Balance" << endl;

				for (Nodee *cure = cur->head2; cure != NULL; cure = cure->next)
				{
					cout << cure->item.id << "              " << cure->item.deposit << endl;
				}
			}
		
		}

	}
	if (flag == true)
	{
		cout << "Customer  " << customerId << "  does not exist" << endl;
	}
}