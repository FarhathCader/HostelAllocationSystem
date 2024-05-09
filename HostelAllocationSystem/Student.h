#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void validateInput2(int& k);
void validateInputdouble2(double& k);


//StudentNode class consisting with the next and previous StudentNode pointers to point next and previous studentnode.

class StudentNode {

public:
	string firstName, lastName, District, regNo;
	int siblingsCountinSchool, siblingsCountinUniversity;
	double distance, parentsIncome, score;
	StudentNode* next, * prev;

	StudentNode();

	double getScore();


};

//Overridden default constructor
StudentNode::StudentNode() {

	next = NULL;
	prev = NULL;
	firstName = " ";
	lastName = " ";
	regNo = " ";
	siblingsCountinSchool = 0;
	siblingsCountinUniversity = 0;
	distance = 0;
	parentsIncome = 0;
	score = 0;




}

//definition of the getscore function to give score according to a selected criteria
double StudentNode::getScore() {
	score = 0;

	double income = parentsIncome / (1 + siblingsCountinSchool + siblingsCountinUniversity);

	if (income <= 50000)score += 7;
	else if (income <= 75000)score += 6.5;
	else if (income <= 100000)score += 6;
	else if (income <= 150000)score += 5;
	else if (income <= 200000)score += 4;
	else if (income <= 250000)score += 3;
	else if (income <= 350000)score += 2;
	else score += 1;

	if (distance >= 450)score += 3;
	else {
		score += distance / 150;
	}
	return score;
}


//declaration of the doubley linkedlist called StudentList
class StudentList {
private:
	StudentNode* head;
	StudentNode* tail;
	int size;

public:
	StudentList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	//insert function to add a new student at tail end
	void insert() {
		StudentNode* ptr = new StudentNode;

		int opt = 0;

		cout << "1)To enter a student details : " << endl;
		cout << "2)Back to main menu" << endl;
		validateInput2(opt);

		if (opt == 1) {
			cout << "Enter the first Name of the student : " << endl;
			cin >> ptr->firstName;

			cout << "Enter the last Name of the student : " << endl;
			cin >> ptr->lastName;

			cout << "Registration Number : " << endl;
			cin >> ptr->regNo;

			cout << "Enter the District of the student : " << endl;
			cin >> ptr->District;

			cout << "Enter the distance from student's home to the faculty in kms: " << endl;
			validateInputdouble2(ptr->distance);

			cout << "Siblings Count at school" << endl;
			validateInput2(ptr->siblingsCountinSchool);

			cout << "Siblings Count at university" << endl;
			validateInput2(ptr->siblingsCountinUniversity);

			cout << "Parents annual income: " << endl;
			validateInputdouble2(ptr->parentsIncome);

			ptr->score = ptr->getScore();

			if (head == NULL) {
				head = ptr;
				tail = ptr;
				size++;
			}
			else {
				tail->next = ptr;
				ptr->prev = tail;
				tail = ptr;
				size++;
			}
		}


	}


	//modify function to modify the entered student details 
	void modify(string regx) {
		StudentNode* current = head;
		bool notfound = true;
		int opt = 1;
		for (int i = 0; i < size; i++) {
			if (current->regNo == regx) {
				notfound = false;
				while (opt != 0) {
					cout << "Please Select an modify option to proceed : " << endl;
					cout << "1)Change the first name : " << endl;
					cout << "2)Change the last name : " << endl;
					cout << "3)Change the regNo : " << endl;
					cout << "4)Change the District : " << endl;
					cout << "5)Change the distance to the facluty from home : " << endl;
					cout << "6)Change the parent's annual income : " << endl;
					cout << "7)Change the Siblings Count at school : " << endl;
					cout << "8)Change the Siblings Count at university : " << endl;
					cout << "0)Back : " << endl;

					validateInput2(opt);


					switch (opt)
					{

					case 1:
						cout << "Enter the first Name of the student : " << endl;
						cin >> current->firstName;
						break;

					case 2:
						cout << "Enter the last Name of the student : " << endl;
						cin >> current->lastName;
						break;

					case 3:
						cout << "Registration Number : " << endl;
						current->regNo;
						break;
					case 4:
						cout << "Enter the District of the student : " << endl;
						cin >> current->District;
						break;

					case 5:
						cout << "Enter the distance from student's home to the faculty in kms: " << endl;
						validateInputdouble2(current->distance);
						break;

					case 6:
						cout << "Parents annual income: " << endl;
						validateInputdouble2(current->parentsIncome);
						break;

					case 7:
						cout << "Siblings Count at school" << endl;
						validateInput2(current->siblingsCountinSchool);
						break;

					case 8:
						cout << "Siblings Count at university" << endl;
						validateInput2(current->siblingsCountinUniversity);
						break;
					case 0:
						break;

					default:
						cout << "Invalid Input!!!" << endl;
						break;


					}
					current->score = current->getScore();
				}
			}

			current = current->next;
		}
		if (notfound) cout << "Student with given regNo is not existed!!!" << endl << endl;
		cout << endl;
	}

	//deletelaststudent function to delete the last entered student details from the tail and update the new tail

	void deleteLastStudent() {

		int opt = 0;
		while (opt != 2) {
			cout << "1)To delete the last entered student details : " << endl;
			cout << "2)Back" << endl;
			validateInput2(opt);
			if (opt == 2)break;
			else if (opt == 1) {
				if (head == NULL)
					cout << "List is empty" << endl;
				else {
					StudentNode* temp = tail;
					if (size == 1) {
						delete temp;
						head = NULL;
						tail = NULL;
						size = 0;
					}
					else {
						tail = tail->prev;
						tail->next = NULL;
						delete temp;
						size--;
					}
				}
			}
			else {
				cout << "Invalid Input!!!" << endl;
			}


		}


	}

	// deletewith function to delete the specific student with the given registration number
	void deleteWith(string regNumber) {
		StudentNode* current = head;
		StudentNode* prev = NULL;
		bool notfound = true;
		while (current != NULL) {
			if (current->regNo == regNumber) {
				notfound = false;
				if (current == head) {
					StudentNode* temp = current;
					current = current->next;
					head = current;
					delete temp;
				}
				else if (current == tail) {
					StudentNode* temp = current;
					current = current->next;
					prev->next = current;
					tail = prev;
					delete temp;
				}
				else {
					StudentNode* temp = current;
					current = current->next;
					prev->next = current;
					delete temp;
				}
				size--;
				continue;
			}
			prev = current;
			current = current->next;
		}
		if (notfound) cout << "Student with given regNo is not existed!!!" << endl << endl;
	}


	//Print the entered student details  

	void print() {
		cout << endl << "=============================================================================================" << endl << endl;
		cout << "Final Student List" << endl << endl;
		int i = 1;
		if (size) {

			cout << left << setw(15) << "Student No"
				<< left << setw(25) << "Full Name"
				<< left << setw(15) << "Reg NO"
				<< left << setw(20) << "District"
				<< left << setw(20) << "Parents Income"
				<< left << setw(20) << "Distance"
				<< left << setw(15) << "Score"


				<< endl;

			cout << left << setw(15) << " "
				<< left << setw(25) << " "
				<< left << setw(15) << " "
				<< left << setw(20) << " "
				<< left << setw(20) << " "
				<< left << setw(20) << " "
				<< left << setw(15) << " "
				<< endl;

			StudentNode* current = head;

			while (current != NULL) {

				cout << left << setw(15) << i++
					<< left << setw(25) << current->firstName + " " + current->lastName
					<< left << setw(15) << current->regNo
					<< left << setw(20) << current->District
					<< left << setw(20) << current->parentsIncome
					<< left << setw(20) << current->distance
					<< left << setw(15);
				printf("%.2f\n", current->score);

				current = current->next;
			}
		}
		else {
			cout << "List is Empty!!!" << endl;
		}
		cout << endl << endl;
	}



	//sort the doubley linked list as according to the scores of the students 

	void changeToSortedLinkedList() {
		StudentNode* sortedHead = NULL;
		StudentNode* sortedTail = NULL;

		while (head != NULL) {
			StudentNode* current = head;
			head = current->next;

			if (sortedHead == NULL || current->score > sortedHead->score) {
				current->prev = NULL;
				current->next = sortedHead;
				if (sortedHead != NULL) {
					sortedHead->prev = current;
				}
				else {
					sortedTail = current;
				}
				sortedHead = current;
			}
			else {
				StudentNode* tempNode = sortedHead;
				while (tempNode->next != NULL && current->score <= tempNode->next->score) {
					tempNode = tempNode->next;
				}
				current->prev = tempNode;
				current->next = tempNode->next;
				if (tempNode->next != NULL) {
					tempNode->next->prev = current;
				}
				else {
					sortedTail = current;
				}
				tempNode->next = current;
			}
		}

		head = sortedHead;
		tail = sortedTail;
	}
};

/*
this is the previous sorting algorithm we used to sort the studentList. But here we failed to update the tail pointer. therefor we upgrade the sorting algorithm as above algorithm

		void changeToSortedLinkedList() {
			StudentNode* tempHead = NULL;

			while (head != NULL) {
				StudentNode* current = head;
				head = current->next;

				if (tempHead == NULL || current->score > tempHead->score) {
					current->next = tempHead;
					tempHead = current;
				}
				else {
					StudentNode* tempNode = tempHead;
					while (tempNode->next != NULL && current->score <= tempNode->next->score) {
						tempNode = tempNode->next;
					}
					current->next = tempNode->next;
					tempNode->next = current;
				}
			}

			head = tempHead;
		}

};
*/


// here we use a function to validate user input as integer
void validateInput2(int& k) {
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
void validateInputdouble2(double& k) {
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
