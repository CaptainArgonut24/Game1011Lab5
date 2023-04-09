#pragma once
#ifndef __PANCAKE_H__
#define __PANCAKE_H__

#include <iostream>
#include "Customer.h"

// VERY important class, that has SO many uses
struct Pancake
{
	// Constructors!
	Pancake(bool syrup, bool butter);
	Pancake() = default;

	// Destructor + Other Functions
	~Pancake() = default;
	void OutputPancake();
	void PourSyrup();
	void AddButter();
private:
	bool hasSyrup;
	bool hasButter;
};

#endif // __PANCAKE_H__