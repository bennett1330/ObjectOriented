#include <iostream>
#include <string>

using namespace std;

struct student{
    string firstName, lastName;    
    int grade;    
    student *next, *prev;
};

student *List = NULL;

void addName(){
	
	if( List ){
		student *temp = List;
		for( ; temp->next != 0; temp = temp->next ){
		}
		student *nextSave = temp->next;
		temp->next = new student;
		cout << "Enter a name [first last]: ";
		cin >> temp->next->firstName >> temp->next->lastName;
		cout << "Enter a grade [integer]: ";
		cin >> temp->next->grade;
		temp->next->next = nextSave;
		temp->next->prev = temp;
	}else {
		List = new student;
		cout << "Enter a name [first last]: ";
		cin >> List->firstName >> List->lastName;
		cout << "Enter a grade [integer]: ";
		cin >> List->grade;
		List->next = 0;
		List->prev = 0;
	}
	cout << "Student added to list. \n";
}

void removeName(){	
	string firstName, lastName;
	cout << "Enter a name [first last]: ";
	cin >> firstName >> lastName;

	for( student *temp = List; temp != 0; temp = temp->next ){
		if( (temp->firstName == firstName) && (temp->lastName == lastName) ){ 
			if( temp == List )
				List = temp->next;
			if( temp->next != 0 )
				temp->next->prev = temp->prev;
			if( temp->prev != 0 )
				temp->prev->next = temp->next;
			delete temp;
			temp = 0;
			cout << "Entry removed. \n";
			return;
		}
	}
	cout << "No entry " << firstName << " " << lastName << " found. \n";
}

void printNames(){
	for( student *temp = List; temp != 0; temp = temp->next ){
		cout << temp->firstName << " " << temp->lastName << 
		        " recieved a grade of " << temp->grade << ". \n"; 	
	}
}

void deleteList(){
	if( List ){
		student *tempDelete = List;
		student *tempHolder = tempDelete->next;
		while( tempDelete != 0 ){
			delete tempDelete;
			tempDelete = tempHolder;
			if( tempHolder )
				tempHolder = tempHolder->next;
		}
		cout << "List has been deleted. \n";	
	}
}

int main(){
	int choice = 0;
	while( 1 ){
		cout << "What function would you like? \n" << 
		        " 1: add student \n" << 
		        " 2: remove student \n" << 
		        " 3: print list \n" << 
		        " 4: exit \n";
	
		cin >> choice;
	
		switch( choice ){
			case 1: addName(); break;
			case 2: removeName(); break;
			case 3: printNames(); break;
			case 4: deleteList(); break;
			default: cout << "Invalid number.";
		}
		if( choice == 4 ){
			break;
		}
	}
	return 0;
}
