#include "Pancake.h"
using namespace std;
Pancake::Pancake(bool syrup, bool butter)
{
	hasSyrup = syrup;
	hasButter = butter;
}


void Pancake::OutputPancake()
{
	cout << "Pancake has been eaten!\n";
	if (hasSyrup)
	{
		cout << "That was good but, it was sticky!\n";
	}
	if (hasButter)
	{
		cout << "It was super buttery good. But greasy salty. !\n";
	}
	cout << "And a heart attack!\n";
}

void Pancake::PourSyrup()
{
	hasSyrup = true;
}

void Pancake::AddButter()
{
	hasButter = true;
}

