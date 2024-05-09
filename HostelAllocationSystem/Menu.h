#pragma once
#include <iostream>
#include "Student.h"
#include <Windows.h>

using namespace std;

void addStudent();
void display();
void deleteStudent();
void modifyStudent();
void sort();
void validateInput(int& k);
void validateInputdouble(double& k);


//declare the StudentList as nm
StudentList nm;

//Main Menu
void menu() {
	int opt = 1;
	while (opt) {
		system("cls");
		cout << endl << "=============================================================================================" << endl << endl;
		cout << "Welcome to the Hostel Allocation System" << endl << endl;
		cout << "Please select an option to proceed : " << endl;
		cout << "1)Add a student detail: " << endl;
		cout << "2)Modify a student detail: " << endl;
		cout << "3)Delete a student detail: " << endl;
		cout << "4)Display entered student details:" << endl;
		cout << "5)Sort the student list according to the score" << endl;
		cout << "0)Quit" << endl;
		cout << endl << "Enter the option number : " << endl;

		validateInput(opt);
		switch (opt) {
		case 0:
			opt = 0;
			cout << "Thank You!!!!!" << endl;
			cout << "=============================================================================" << endl;
			break;
		case 1:
			system("cls");
			addStudent();
			break;
		case 2:
			system("cls");
			modifyStudent();
			break;
		case 4:
			system("cls");
			display();
			system("pause");
			break;
		case 3:
			system("cls");
			deleteStudent();
			break;
		case 5:
			system("cls");
			sort();
			system("pause");
			break;

		default:
			cout << endl << "Please enter a valid input!!!!" << endl;
			break;

		}

	}
}


//addstudent submenu
void addStudent() {
	StudentNode* ptr = new StudentNode();
	cout << "===========================================================" << endl << endl;
	cout << "\t\t\t\tStudent Details\t\t\t\t" << endl << endl;
	nm.insert();


}


//display submenu
void display() {

	nm.print();

}


//modify submenu
void modifyStudent() {
	string x;
	int opt = 0;
	while (opt != 2) {
		cout << "1)To enter the Registration number of the student to be modified : " << endl;
		cout << "2)Back to main menu" << endl;
		validateInput(opt);
		if (opt == 2)break;
		else if (opt == 1) {
			cout << "Enter the Registration Number of the student : " << endl;
			cin >> x;
			nm.modify(x);
		}
		else {
			cout << "Invalid Input!!!" << endl;
		}


	}



}


//deleteLast student submenu
void deleteStudent() {
	int sub = 0;
	string reg;

	int opt = 2;
	while (opt != 0) {
		cout << "Select a delete option : " << endl;
		cout << "1)Delete the last entered student details" << endl;
		cout << "2)Delete a specific student " << endl;
		cout << "0)Back to main menu " << endl;
		validateInput(opt);
		if (opt == 0)break;
		else if (opt == 1) {
			nm.deleteLastStudent();
		}
		else if (opt == 2) {
			cout << "Enter the student Registration number to delete : " << endl;
			cin >> reg;
			nm.deleteWith(reg);
		}
		else {
			cout << "Invalid Input!!!" << endl;
		}


	}






}


//sorting submenu
void sort() {
	cout << "===========================================================" << endl << endl;
	cout << "\t\t\t\tFinal Sorted List\t\t\t\t" << endl << endl;
	nm.changeToSortedLinkedList();
	nm.print();
}



// here we use a function to validate user input as integer
void validateInput(int& k) {
	while (1) {
		if (cin >> k) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid Input! Please input a numerical value." << endl;
			cin.clear();
			while (cin.get() != '\n'); // empty loop
		}
	}


}

// here we use a function to validate user input as double
void validateInputdouble(double& k) {
	while (1) {
		if (cin >> k) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid Input! Please input a numerical value." << endl;
			cin.clear();
			while (cin.get() != '\n'); // empty loop
		}
	}


}
#pragma once
