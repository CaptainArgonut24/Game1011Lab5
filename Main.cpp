#include "Stack.h"
#include "Queue.h"
#include "Pancake.h"
#include "CustomExceptions.h"

#include <iostream>
#include <cstdlib>


// Const variables :D
constexpr int MAX_PANCAKES = 5;
constexpr int MAX_CUSTOMERS = 30;

// Prototypes
void CookPancakes(DynamicStack<Pancake>& pancakes);
void AddCustomers(DynamicQueue<Customer>& customers);
int GetRandomInt();
using namespace std;

int main()
{
	// rand() initializer
	srand(time(nullptr));

	// Variables!
	DynamicQueue<Customer> customers;
	DynamicStack<Pancake> pancakes;
	int numOfPancakes;
	int customerCount = 1;

	// Cooking pancakes and adding customers to the queue!
	CookPancakes(pancakes);
	AddCustomers(customers);


	// Ssssshowtime!
	while (!customers.IsEmpty())
	{
		system("CLS");
		cout << "Looks Like A New Customer Has Entered! Welcome To Papa's Pancakeria!\n\n";
		cout << "You Are Customer Number: " << customerCount << " of " << MAX_CUSTOMERS << "!\n\n";
		bool isValid = false;
		do
		{
			cout << "How many pancakes do you want? (Max 3): ";
			cin.clear(); 
			cin >> numOfPancakes;
			if (numOfPancakes == 0 || numOfPancakes == 1 || numOfPancakes == 2 || numOfPancakes == 3)
			{
				isValid = true;
			} else
			{
				cout << "\n An Error Has Occurred. Please Try Again With Numbers Between 0 & 3!\n";
			}
		} while (!isValid);

		if (numOfPancakes == 0) 
		{
			cout << "\n Wait, Hold on a sec? You came to a pancake shop and did not order any pancakes? GET TF OUT.\n";
		} else
		{
			cout << "\nAlright! " << numOfPancakes << "  orders of pancakes coming right up in a min or so!\n";
		}

		for (int i = 0; i < numOfPancakes; i++)
		{
			try
			{
				if (pancakes.IsEmpty())
				{
					throw OutOfPancake{};
				}
			} catch (OutOfPancake& error)
			{
				std::cout << error.what() << std::endl;

				CookPancakes(pancakes);
			}

			pancakes.Pop().OutputPancake();
		}

		customerCount++;
		customers.Dequeue().ExitCustomer();
		system("pause");
	}

	std::cout << "\n\n All Done For The Day! Thank you for visiting Papa's Pancakeria! \n";
	return 0;
}

void CookPancakes(DynamicStack<Pancake> &pancakes)
{
		for (int i = 0; i < MAX_PANCAKES; i++)
		{
			pancakes.Push(Pancake(static_cast<bool>(GetRandomInt()), static_cast<bool>(GetRandomInt())));
		}
}

void AddCustomers(DynamicQueue<Customer>& customers)
{
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		customers.Enqueue(Customer());
	}
}

int GetRandomInt()
{
	return rand() % 2;
}