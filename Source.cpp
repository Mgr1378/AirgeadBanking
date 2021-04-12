/*
Project One: Chada Tech Clocks
Michael Richards
CS-210
03/25/2021

*/


#include<iostream>
#include"Time.h"
#include<conio.h>
#include<Windows.h>
using namespace std;


int main() {
	Time t;
	
	//Allows the user to set the time.
	t.SetTime();

	//This while loop runs until the user press a key on the key broad
	while (!_kbhit()) {
		system("cls");
		t.displayTwoClocks();
		t.menu();
		cout << "Clock will run until you press a key:" << endl;
		t.Update12_Second();
		t.Update24_Second();
		Sleep(1000);
	}
	// This while loop is the main loop in the clock project, it adds time and it also keeps the clock running after adding time. It will run until the user presses 4 to quit. 
	while (true) {
		t.AddTime();
	}
	
	
	
	

	
}

