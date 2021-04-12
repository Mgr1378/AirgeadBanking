/*
Project Two: Airgead Banking
Michael Richards
CS-210
04/04/2021

*/
#pragma once
#include <iostream>
#include<iomanip>

#include "Banking.h"

using namespace std;

class Displays : public Banking {

public:
	
	void openingMenu();
	void withDeposits();
	void withoutDepositsMenu();
	void verifyOpeningMenu();
	
private:
	int i;
	int choice = 3;
	float openAmount;
	float opening;
	float deposit;
	float interest;
	float rate;
	float balance;
	float endTotal;
	int years;
	bool loop = true;
};





