/*
Project Two: Airgead Banking
Michael Richards
CS-210
04/04/2021

*/
#include "Displays.h"
#include<iostream>

#include<Windows.h>
using namespace std;


//This is the first menu displayed to the user
void Displays::openingMenu() {
	
	cout << "***************************************\n";
	cout << "***************Data Input**************\n";
	cout << "Enter Initial Investment Amount: \n";
	cin >> opening;
	openAmount = opening;
	//The if statements are to make sure that the user input is a positve number and if it is not have the user try again
	if (opening < 0) {
		system("cls");
		cout << "Invalid Entry: Try Again." << endl;
		openingMenu();
	}
	Banking::SetInitialAmount(opening);
	cout << "Enter Monthly Deposit: \n";
	cin >> deposit;
	if (deposit < 0) {
		system("cls");
		cout << "Invalid Entry: Try Again." << endl;
		openingMenu();
	}
	Banking::SetMonthlyDeposit(deposit);
	cout << "Enter Annual Interest: \n";
	cin >> interest;
	if (interest < 0) {
		system("cls");
		cout << "Invalid Entry: Try Again." << endl;
		openingMenu();
	}
	Banking::SetAnnualInterest(interest);
	cout << "Enter Number of Years: \n";
	cin >> years;
	if (years < 0) {
		system("cls");
		cout << "Invalid Entry: Try Again." << endl;
		openingMenu();
	}
	Banking::SetNumYears(years);
	verifyOpeningMenu();
}
// This menu is to verify the users input, if it is wrong they can go back and change it here.
void Displays::verifyOpeningMenu() {
	cout << "******************************************\n";
	cout << "***************Data Inputted**************\n";
	cout << "The Initial Investment Amount: $" << Banking::GetInitialAmount() << endl;
	
	cout << "The Monthly Deposit: $" << Banking::GetMonthlyDeposit() << endl;
	
	cout << "The Annual Interest: " << Banking::GetAnnualInterest() << "% Interest" << endl;
	
	cout << "Years you inputted: " << Banking::GetNumYears() << " years" << endl;
	cout << "******************************************\n";
	cout << "******************************************\n";

	cout << "Press 1 if infomation is accurate or Press 2 if you need to make changes.\n";
	while (loop) {
		cin >> choice;

		switch (choice) {
		case 1:
			system("cls");
			withoutDepositsMenu();
			withDeposits();
			loop = false;
			break;
		case 2:
			system("cls");
			openingMenu(); 
				loop = false;
			break;
		default:
			cout << "Press 1 if infomation is accurate or Press 2 if you need to make changes.\n";
			loop = true;
		}
	}
	
}
// This is the display without Additional monthly deposits
void Displays::withoutDepositsMenu() {

	
	cout << setfill(' ') << setw(90) << " Balance and Interest Without Additional Monthly Deposits        \n";
	cout << setfill(' ') << setw(25) << " **********************************************************************************************************************\n";
	cout << setfill(' ') << setw(1);
	cout << "|    " << setfill(' ') << setw(2) << "Month " << "   ||  " << setfill(' ') << setw(2) << "Opening Balanace $ " << "|";
	cout << "|  " << setfill(' ') << setw(2) << "Monthly Deposit $" << "  ||    " << setfill(' ') << setw(3) << "Total $ ";
	cout << "||  " << setfill(' ') << setw(2) << "Monthly Interest $" << "  || " << setfill(' ') << setw(2) << "Closing Balance $" << "|\n";
	cout << setfill(' ') << setw(25) << " **********************************************************************************************************************\n";

	// For loop to output all of the years into months the user inputted
	for (i = 0; i < Banking::yearsToMonths(); ++i) {
		opening = GetInitialAmount();
		rate = ((opening + 0) * (GetAnnualInterest() / 100.00) / 12.00);
		balance = opening + rate;
		
		cout << setprecision(2) << fixed << "|    " << setfill(' ') << setw(2) << (i + 1) << "       ||"  << setfill(' ') << setw(12) << opening << "         |";
		cout << "| " << setfill(' ') << setw(10) << 0 << "          || " << setfill(' ') << setw(8) << (opening + 0) << "   |";
		cout << "| " << setfill(' ') << setw(10) <<  rate << "           ||" << setfill(' ') << setw(10) << balance << "        |"<< endl;
		SetInitialAmount(balance);
	}
	cout << setfill(' ') << setw(25) << " *****************************************************************************************************************\n";
}
//This is the display that has the monthly deposits 
void Displays::withDeposits() {

	
	cout << setfill(' ') << setw(90) << " Balance and Interest With Additional Monthly Deposits        \n";
	cout << setfill(' ') << setw(25) << " ***********************************************************************************************************************\n";
	cout << setfill(' ') << setw(1);
	cout << "|    " << setfill(' ') << setw(2) << "Month " << "   ||  " << setfill(' ') << setw(2) << "Opening Balanace $ " << "|";
	cout << "|  " << setfill(' ') << setw(2) << "Monthly Deposit $" << "  ||    " << setfill(' ') << setw(3) << "Total $ ";
	cout << "||  " << setfill(' ') << setw(2) << "Monthly Interest $" << "  ||  " << setfill(' ') << setw(2) << "Closing Balance $" << "|\n";
	cout << setfill(' ') << setw(25) << " ***********************************************************************************************************************\n";

	SetInitialAmount(openAmount);
	//For loop to output all of the years into months the user inputted
	for (i = 0; i < Banking::yearsToMonths(); ++i) {
		opening = GetInitialAmount();
		rate = ((opening + deposit) * (GetAnnualInterest() / 100.00) / 12.00);
		balance = opening + deposit + rate;

		cout << setprecision(2) << fixed << "|    " << setfill(' ') << setw(2) << (i + 1) << "       ||" << setfill(' ') << setw(12) << opening << "           |";
		cout << "| " << setfill(' ') << setw(10) << deposit << "          || " << setfill(' ') << setw(8) << (opening + deposit) << "   |";
		cout << "| " << setfill(' ') << setw(10) << rate << "           ||" << setfill(' ') << setw(10) << balance << "       |" << endl;
		SetInitialAmount(balance);
	}
	cout << setfill(' ') << setw(25) << " *********************************************************************************************************************\n";
	cout << setfill(' ') << setw(25) << " *********************************************************************************************************************\n";
	cout << "" << endl;
	cout << "Press 1 to change Initial Data or Press 2 to exit:\n";
	//This is a while loop that ask the user if they would like to change the initial data or quit the programO
	while (loop == true) {
		cin >> choice;

		switch (choice) {
		case 1:
			system("cls");
			openingMenu();
			loop = false;
			break;
		case 2:
			exit(1);
		default:
			cout << "Press 1 to change Initial Data or Press 2 to exit:\n";
			loop = true;
		}
	}
}