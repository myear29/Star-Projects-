#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void printMenu(int& option);
void getInfo(string& fName, string& lName, string& studentID, float& midtermGrade, float& finalGrade);
void studentGradeValidation(float student_Grade);
void displayById(string id[], string fname[], string lname[], float midtermGrade[], float finalGrade[], int size);
void displayAll(string fname[], string lname[], string id[], float midtermGrade[], float finalGrade[], int counter);
void editStudentRecord(string fName[], string lName[], string studentID[], float midtermGrade[], float finalGrade[], int SIZE);
void deleteStudentRecord(string fname[], string lname[], string id[], float midtermGrade[], float finalGrade[], int SIZE);
void addStudentInfo(string fName[], string lName[], string studentID[], float midtermGrade[], float finalGrade[], int& counter, int SIZE);

int main()
{
	int choice, counter = 0;
	const int SIZE = 20;
	string firstName[SIZE], lastName[SIZE], ID[SIZE];
	float Midterm[SIZE], Final[SIZE];


	printMenu(choice);



	do
	{
		switch (choice)
		{
		case 1:
			cout << "You  choose to add a new student record " << endl;

			addStudentInfo(firstName, lastName, ID, Midterm, Final, counter, SIZE);
			cout << "You have entered Student information successfully." << endl;


			break;

		case 2:
			cout << "You choose to delete a student record " << endl;

			deleteStudentRecord(firstName, lastName, ID, Midterm, Final, SIZE);

			cout << "You have successfully deleted a student record" << endl;


			break;

		case 3:
			cout << "You choose to display all student records " << endl;

			displayAll(firstName, lastName, ID, Midterm, Final, counter);


			cout << "You have successfully displayed a student record." << endl;
			break;

		case 4:
			cout << "You choose to show a student record by ID" << endl;

			displayById(ID, firstName, lastName, Midterm, Final, counter);

			cout << "You have successfully showed a student record by Id" << endl;

			break;

		case 5:
			cout << "You choose to edit a student record " << endl;

			editStudentRecord(firstName, lastName, ID, Midterm, Final, SIZE);
			break;

		default:
			cout << "Exit" << endl;
			break;
		}

		printMenu(choice);

	} while (choice != 6);



	system("pause");
	return 0;



}

// Printing the menu

void printMenu(int& option)

{


	cout << "===========================================================================" << endl;

	cout << "Please choose the following options: " << endl;

	cout << " [1] : Add a new student record." << endl;
	cout << " [2] : Delete student record." << endl;
	cout << " [3] : Display all student records." << endl;
	cout << " [4] : Show a student record by ID." << endl;
	cout << " [5] : Edit a student record." << endl;
	cout << " [6] : Exit." << endl;

	cout << "Choose an option from 1 to 6: ";
	cin >> option;

}

// User enters the information

void getInfo(string& fName, string& lName, string& studentID, float& midtermGrade, float& finalGrade)
{


	cout << "===========================================================================" << endl;
	cout << "Please enter the following information to add a new student record: " << endl;

	cout << "Enter your First name: ";
	cin >> fName;
	cout << "Enter your Last name: ";
	cin >> lName;
	cout << "Enter your student ID: ";
	cin >> studentID;
	cout << "Enter your midterm grade: ";
	cin >> midtermGrade;
	studentGradeValidation(midtermGrade);
	cout << "Enter your final grade: ";
	cin >> finalGrade;
	studentGradeValidation(finalGrade);

}

//Saves the student info to the array
void addStudentInfo(string fName[], string lName[], string studentID[], float midtermGrade[], float finalGrade[], int& counter, int SIZE)
{
	string fname, lname, studentId;
	float midterm, final;


	getInfo(fname, lname, studentId, midterm, final);


	if (counter < SIZE)
	{
		fName[counter] = fname;
		lName[counter] = lname;
		studentID[counter] = studentId;
		midtermGrade[counter] = midterm;
		finalGrade[counter] = final;
	}
	else
	{
		cout << "Not enough space" << endl;
	}

	counter++;
}

// Validation for the grades between 0 to 100

void studentGradeValidation(float student_Grade)
{
	while (student_Grade < 0 || student_Grade > 100)
	{


		cout << "Enter a valid midterm grade: ";
		cin >> student_Grade;
	}


}

//delete a satudent record



void deleteStudentRecord(string fname[], string lname[], string id[], float midtermGrade[], float finalGrade[], int SIZE)
{
	int studentRecord;
	cout << "Enter a record (1-20):" << endl;
	cin >> studentRecord;

	fname[studentRecord - 1] = " ";
	lname[studentRecord - 1] = " ";
	id[studentRecord - 1] = " ";
	midtermGrade[studentRecord - 1] = 0;
	finalGrade[studentRecord - 1] = 0;


}

//Displays student record

void displayAll(string fname[], string lname[], string id[], float midtermGrade[], float finalGrade[], int counter)
{
	cout << "=============================================================================" << endl;
	cout << "Student Record : " << endl;

	cout << "First Name " << setw(18) << "Last Name " << setw(16) << "ID " << setw(20) << "Midterm Grade " << setw(18) << "Final Grade " << endl;

	for (int i = 0; i < counter; i++)
	{

		cout << fname[i] << setw(18) << lname[i] << setw(16) << id[i] << setw(20) << midtermGrade[i] << setw(18) << finalGrade[i] << endl;
	}


}

void displayById(string id[], string fname[], string lname[], float midtermGrade[], float finalGrade[], int size)
{
	cout << "===========================================================================" << endl;

	string studentID;
	cout << "Enter a valid student ID: " << endl;
	cin >> studentID;


	bool found = false;

	cout << "ID " << setw(18) << "First Name " << setw(18) << "Last Name " << setw(20) << "Midterm Grade " << setw(18) << "Final Grade " << endl;

	for (int i = 0; i < size; i++)
	{
		if (id[i] == studentID)
		{

			cout << id[i] << setw(18) << fname[i] << setw(16) << lname[i] << setw(20) << midtermGrade[i] << setw(18) << finalGrade[i] << endl;

			found = true;

		}
	}

	if (found == false)
	{
		cout << "Could not find student record" << endl;
	}
	else
	{
		cout << "Student record was able to be found" << endl;
	}
}

// Student record editied

void editStudentRecord(string fName[], string lName[], string studentID[], float midtermGrade[], float finalGrade[], int SIZE)
{
	string id;
	cout << "=============================================================================" << endl;

	cout << "Enter a student Id you wish to change: ";
	cin >> id;



	bool found = false;
	for (int i = 0; i < SIZE; i++)
	{
		if (studentID[i] == id)
		{
			cout << "The student record was found, you may now enter the information." << endl;
			cout << "Enter your Fisrt name: ";
			cin >> fName[i];
			cout << "Enter your Last name: ";
			cin >> lName[i];
			cout << "Enter your stduent ID: ";
			cin >> studentID[i];
			cout << "Enter your midterm greade: ";
			cin >> midtermGrade[i];

			found = true;

		}
	}

	if (found = false)
	{
		cout << "Could not find student record" << endl;
	}
	else
	{
		cout << "Student record was successfully changed" << endl;
	}
}
