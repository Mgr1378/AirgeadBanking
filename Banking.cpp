/*
Project Two: Airgead Banking
Michael Richards
CS-210
04/04/2021

*/
#include<iostream>
#include "Banking.h"
//Those are the getters and setters 
void Banking::SetInitialAmount(float initialInvestment) {
	initialAmount = initialInvestment;
}

void Banking::SetMonthlyDeposit(float deposit) {
	monthlyDeposit = deposit;
}

void Banking::SetAnnualInterest(float interest) {
	annualInterest = interest;
}

void Banking::SetNumYears(int years) {
	numYears = years;
}

float Banking::GetAnnualInterest() {
	return annualInterest ;
}

float Banking::GetInitialAmount() {
	return initialAmount;
}

float Banking::GetMonthlyDeposit() {
	return monthlyDeposit;
}

int Banking::GetNumYears() {
	return numYears;
}
// This is the function to get the closing total 
float Banking::GetClosingBalance() {
	return ((GetInitialAmount() + GetMonthlyDeposit()) + interestRate());
}
//This is the function to get the monthly interest instead of yearly
float Banking::interestRate() {
	rate = ((GetInitialAmount() + GetMonthlyDeposit()) * (annualInterest / 100.00) / 12.00);
	return rate;
}
// This is the fuction to change years into months
int Banking::yearsToMonths() {
	months = GetNumYears() * 12;
	return months;
}

 