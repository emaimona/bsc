#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Prequisites:
1) Filename should be the following:	prog2_neptuncode
2) In the first part of the file (as a comment), please write your full name and your neptun code once again.

	Name: Maimona Emanuel Nzinga
    Neptun code: SVBIIC;

    Environments on which the program was tested:
    -> VsCode:  extension_id: danielpinto8zz6.c-cpp-compile-run
    OS: macOS monterey 12.3

Write a C++ program that follows the concepts of CRUD.
Through the application, you need to pass references to functions whenever you can!
You are allowed to use everything from the classes, folder 06, 07 and 08 can be useful.

The topic of the application can be anything. 

Example: Employee Manager System

When the application starts up, the following MENU should be displayed

	Welcome to the >your-app-title< application!
	
	Please select a menu point:
	A) Add new employee
	L) List all employees
	S) Search employee name
	U) Update employee name
	D) Delete employee
	E) Exit
	

Explanation of menu points
General rules: 
1) When the application finished with a logical part (listing/updating/etc), display the MENU again.
2) The application must handle both lowercase and uppercase characters when you select a menu point (u/U).
3) Comment your code.


A) The user can add new employees until the input is a given special character (*). Inputs must be stored as strings.
The employee name cannot be more than 15 characters. If so, print out the error message and ask the user again.
The input should be able to handle spaces. (John Johnny is a valid name)

L) Print out all employee names based on the following structure:
1 - John
2 - Jane
3 - And_so_on

S) Search if a given employee name have been stored. If not, print out an error message, if yes, print out the following:
Johnny found at index 3!

U) Use the search method to find a given employee. 
If the element is found, display: 

	"What is the new name of Johnny?"
	Input: John

D) Use the search method to delete a given employee. 
	After you found the employee, ask the user:

	"Are you sure you want to delete Johnny? (Y/N)"

If the user input is "n" or "N", go back to the MENU.
If the user input is "y" or "Y", delete the element.

E) Exit from the application

Don't forget to use pointers and references (especially when you display all elements).

If you are struggling with pointers, two possible usages:
The search method can return a POINTER, so you can print out the value at that address with another function.
You can dynamically create the array/vector in the HEAP as well.

Good luck!

Deadline: 2022.04.26, 18:00 on Teams as an Assignment.


class Patient{
public:
	string name;
	int age;

	Patient (string name) {
		this->name = name;
	}

	Patient (string name, int age) {
		this->name = name;
		this->age = age;
	}

};

*/

class Patient{
public:
	vector<string> patient;

	void addNewPatient(string name) {
		patient.push_back(name);
	}

	void listAllPacient() {

		for(int i=0; i<patient.size(); i++) {
			cout<<i+1 <<" - "<< patient[i]<<endl;
		}
	}

	int searchPatient(string patientname) {
		for(int i=0; i<patient.size(); i++) {
			if(patient[i] == patientname)
				return i;
		}
		return -1;
	}

	void deletePatient(int index) {
		patient.erase(patient.begin(),patient.begin()+index);
	}

	void updatePatient(string new_name, int index) {
		patient.erase(patient.begin(),patient.begin()+index);
		patient.push_back(new_name);
	}
};


void writeMenu(Patient *patient);
void selectOption(string optin, Patient *patient);
void addPatients(Patient *patient);
void searchPatient(Patient *patient);
void updatePatients(Patient *patient);
void deletePatients(Patient *patient);

int main(){
	Patient patient;

	writeMenu(&patient);

	return 0;
}


void updatePatients(Patient *patient) {
	string name;
	cout<< "\nInput the name of the Patients."<< endl;
	cin >> name;

	int index = patient->searchPatient(name);

	if (index != -1){
		cout<< "\nInput the new name of the Patients."<< endl;
		cin>> name;
		patient->updatePatient(name, index);
		cout<<"Patient updated successfully";
	
	}
	else	
		cout<< "Not found"<<endl;

	writeMenu(patient);
	
}




void deletePatients(Patient *patient) {
	string name;
	cout<< "\nInput the name of the Patients."<< endl;
	cin >> name;

	int index = patient->searchPatient(name);

	if (index != -1){
		cout<<"Are you sure you want to delete Johnny? (Y/N)";
		string option;
		cin>> option;
		if(option == "N" || option == "n"){
			writeMenu(patient);
		}
		else if (option == "Y" || option == "y") {
			patient->deletePatient(index);
			cout<<"Patient deleted successfully";
		} else {
			cout<< "Wrong option"<< endl;
			deletePatients(patient);
		}
	}
	else	
		cout<< "Not found"<<endl;

	writeMenu(patient);
	
}

void searchPatient(Patient *patient) {
	cout<< "\nInput the name of the Patients."<< endl;
	string name;
	cin>> name;
	int index = patient->searchPatient(name);
	if( index != -1)
		cout<<name << " found at index "<< index<<endl;
	else	
		cout<< "Not found"<<endl;

	writeMenu(patient);
}


void addPatients(Patient *patient) {
	cout<< "\nInput the name of the Patients, or '*' to finish..."<< endl;
	cout<<"The name cannot have more than 15 characters"<<endl;

	string name;
	cin.ignore();

	do {
		cout<<"Input the name of patient: ";
		char n[2000];
		cin.getline(n, sizeof(n));

		string n1(n);
		name = n1;

		if (name.size() > 15) 
			cout<< "The name cannot have more than 15 characters, try please again...\n";
		
		 if (name != "*") 
			patient->addNewPatient(name);
	} 
	while(name != "*");
	
	writeMenu(patient);
}



void selectOption(string option, Patient *patient) {

	if (option == "A" || option == "a") {
		addPatients(patient);
	} else if (option == "L" || option == "l") {
		cout<< "Listing all patients"<<endl;
		patient->listAllPacient();
		cout<<endl;
		writeMenu(patient);
	} else if (option == "S" || option == "s") {
		searchPatient(patient);
	} else if (option == "U" || option == "u") {
		updatePatients(patient);
	} else if (option == "D" || option == "d") {
		deletePatients(patient);
	} else if (option == "E" || option == "e") {
		cout<<"Exit successfully"<<endl;
	} else {
		cout<< "Option incorrect, please try again!\n";
		writeMenu(patient);
	}

}

void writeMenu(Patient *patient) {
	cout<< "\n\nWelcome to the Patient Management System application! \n Please select a menu point: "<<endl;
	cout<< " A) Add new patient"<<endl;
	cout<< " L) List all patient"<<endl;
	cout<< " S) Search patient name"<<endl;
	cout<< " U) Update patient name"<<endl;
	cout<< " D) Delete patient"<<endl;
	cout<< " E) Exit"<<endl;

	string option;
	cin>> option;
	selectOption(option, patient);
}