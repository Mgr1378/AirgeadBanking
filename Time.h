/*
Project One: Chada Tech Clocks
Michael Richards
CS-210
03/25/2021

*/


#pragma once
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
using namespace std;

//Class declartion 
class Time {
	
	//making the constructor
	public:
		
		void menu();
		void Set12_Hour(int hour12);
		void Set24_Hour(int hour24);
		void Set12_Minute(int minute12);
		void Set24_Minute(int minute24);
		void Set12_Second(int second12);
		void Set24_Second(int second24);
		int Get12_Hour();
		int	Get24_Hour();
		int	Get12_Minute();
		int	Get24_Minute();
		int	Get12_Second();
		int	Get24_Second();
		void displayTwoClocks();
		void Update12_Hour();
		void Update24_Hour();
		void Update12_Minute();
		void Update24_Minute();
		void Update12_Second();
		void Update24_Second();
		void SetTime();
		void AddTime();
private:
		int _12hour;
		int _12minute;
		int _12second;
		int _24hour;
		int _24minute;
		int _24second;

}; 

//The setters allow for the user to be able to set the time before the clock starts moving..
void Time::Set12_Hour(int hour12) {
	_12hour = hour12;
}

void Time::Set24_Hour(int hour24) {
	_24hour = hour24;
}

void Time::Set12_Minute(int minute12) {
	_12minute = minute12;
}

void Time::Set24_Minute(int minute24) {
	_24minute = minute24;
}

void Time::Set12_Second(int second12) {
	_12second = second12;
}

void Time::Set24_Second(int second24) {
	_24second = second24;
}

//The getter functions are what I use to get the time for the displayTwoClocks() function later on. 

int Time::Get12_Hour() {
	if (_12hour == 13) {
		_12hour = 1;
	}
	
	return _12hour;
}

int Time::Get24_Hour() {
	if (_24hour == 24) {
		_24hour = 0;
	}
	return _24hour;
}

int Time::Get12_Minute() {
	if (_12minute == 60) {
		_12minute = 0;
		_12hour += 1;
	}
	return _12minute;
}

int Time::Get24_Minute() {
	if (_24minute == 60) {
		_24minute = 0;
		_24hour += 1;
	}
	return _24minute;
}

int Time::Get12_Second() {
	if (_12second == 60) {
		_12second = 0;
		_12minute += 1;
	}
	return _12second;
}

int Time::Get24_Second() {
	if (_24second == 60) {
		_24second = 0;
		_24minute += 1;
	}
	return _24second;
}

// Those functions are how I get the time to update after a user picks an option from the menu..
void Time::Update12_Hour() {
	_12hour = _12hour + 1;
	Set12_Hour(_12hour);
}

void Time::Update24_Hour() {
	_24hour = _24hour + 1;
	Set24_Hour(_24hour);
}

void Time::Update12_Minute() {
	_12minute = _12minute + 1;
	Set12_Minute(_12minute);
}

void Time::Update24_Minute() {
	_24minute = _24minute + 1;
	Set24_Minute(_24minute);
}

void Time::Update12_Second() {
	_12second = _12second + 1;
	Set12_Second(_12second);
}

void Time::Update24_Second() {
	_24second = _24second + 1;
	Set24_Second(_24second);
}


//This is where the user sets the time they want.
void Time::SetTime() {
	int x;
	int y;
	int z;
	cout << "Please input the time: " << endl;
	cout << "Set the hour you want:" << endl;
	cin >> x;
	Set12_Hour(x);
	Set24_Hour(x);
	cout << "Set the minute you want: " << endl;
	cin >> y;
	Set12_Minute(y);
	Set24_Minute(y);
	cout << "Set the second you want: " << endl;
	cin >> z;
	Set12_Second(z);
	Set24_Second(z);

}
//This is the function that puts the clocks on the screen for the user.
void Time::displayTwoClocks() {

	cout << "*************************** ***************************\n";

	cout << "*     12-Hour Clock       * *      24-Hour Clock      *\n";

	cout << "*     "; if (Get12_Hour() < 10) cout << "0"; cout << Get12_Hour() << ":";

	if (Get12_Minute() < 10) cout << "0"; cout << Get12_Minute() << ":";

	if (Get12_Second() < 10) cout << "0"; cout << Get12_Second();

	if (Get24_Hour() < 12) cout << " A M"; else cout << " P M";

	cout << "        * *         ";

	if (Get24_Hour() < 10) cout << "0"; cout << Get24_Hour() << ":";

	if (Get24_Minute() < 10) cout << "0"; cout << Get24_Minute() << ":";

	if (Get24_Second() < 10) cout << "0"; cout << Get24_Second();

	cout << "        *\n";

	cout << "*************************** ***************************\n";

}
//This is the function that gives the user the option to add time to the clock then it continues to run the clock after the user picks how much time to add.
void Time::AddTime() {
	menu();
	int choice;

	cin >> choice;

	if (choice == 1) {
		system("cls");
		cout << "Ok adding one hour:" << endl;
		Update12_Hour();
		Update24_Hour();
		while (!_kbhit()) {
			system("cls");
			displayTwoClocks();
			Update12_Second();
			Update24_Second();
			menu();
			Sleep(1000);
		}

	}
	else if (choice == 2) {
		system("cls");
		cout << "Ok adding one minute:" << endl;
		Update12_Minute();
		Update24_Minute();
		while (!_kbhit()) {
			system("cls");
			displayTwoClocks();
			Update12_Second();
			Update24_Second();
			menu();
			Sleep(1000);
		}

	}
	else if (choice == 3) {
		system("cls");
		cout << "ok adding one second:" << endl;
		Update12_Second();
		Update24_Second();
		while (!_kbhit()) {
			system("cls");
			displayTwoClocks();
			Update12_Second();
			Update24_Second();
			menu();
			Sleep(1000);
		}

	}

	else if (choice == 4) {
		exit(1);
	}
	else if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
		cout << "Invalid Entry: Please try again:" << endl;

	}
	else {
		cout << "Please try again: " << endl;
	}
}

// This is the function that displays the menu with the options to add time.
void Time::menu() {

	cout << setfill(' ') << setw(25) << "         Menu        \n";
	cout << setfill(' ') << setw(25) << " --------------------------\n";
	cout << setfill(' ') << setw(1);
	cout << "|    " << setfill(' ') << setw(2) << "1. Add One Hour." << "     |\n";
	cout << "|    " << setfill(' ') << setw(2) << "2. Add One Minute." << "   |\n";
	cout << "|    " << setfill(' ') << setw(2) << "3. Add One Second." << "   |\n";
	cout << "|    " << setfill(' ') << setw(2) << "4. Quit" << "              |\n";
	cout << setfill(' ') << setw(25) << " --------------------------\n";

}



