/*
Project Two: Airgead Banking
Michael Richards
CS-210
04/04/2021

*/
#pragma once
class Banking {
public:
	void SetInitialAmount(float initialInvestment);
	void SetMonthlyDeposit(float deposit);
	void SetAnnualInterest(float interest);
	void SetNumYears(int years);
	float GetInitialAmount();
	float GetMonthlyDeposit();
	float GetAnnualInterest();
	int GetNumYears();
	float GetClosingBalance();
	float interestRate();
	int yearsToMonths();
private:
	float initialAmount;
	float monthlyDeposit;
	float annualInterest;
	float numYears;
	float choice;
	float monthlyInterestRate;
	float months;
	float closingBalance;
	float rate;
};


