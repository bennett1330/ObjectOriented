#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct sports{
    	string firstName, lastName;
    	int numWins = 0;
    	int years[4];
    	sports *next;
    	sports *prev;
};

sports *Head = NULL;
sports *Tail = NULL;

void printEntry( sports *entry ){
    	cout << "Name: " << entry->firstName << " " << entry->lastName;
    	cout << " Number of wins: " << entry->numWins;
    	cout << " Years: ";
    	for( int i = 0; i < 4; i++ ){
        	if( entry->years[ i ] != 0 )
            		cout << entry->years[ i ] << " ";
    	}
    	cout << endl;
}

void printList(){
        bool start = true;
        for( sports *temp = Head; (temp != Head) || (start == true) ; temp = temp->next ){
                printEntry( temp );
                start = false;
        }
}

void addEntry( string firstName, string lastName, int year ){
	if( Head ){
        bool start = true;
		sports *temp = Head;
		for( ; (temp->next != Head) || (start == true); temp = temp->next ){
		    	if( (temp->firstName == firstName) && (temp->lastName == lastName) ){
		        	temp->years[ temp->numWins ] = year;
		        	temp->numWins++;
		        	return;
		    	}
                    	start = false;
		}
		temp->next = new sports;
                Tail = temp->next;
		temp->next->prev = temp;
                temp->next->next = Head;
                Head->prev = Tail;
		temp->next->firstName = firstName;
    	        temp->next->lastName = lastName;
	        temp->next->years[ temp->next->numWins ] = year;
	        temp->next->numWins = 1;
	}else{
		Head = new sports;
                Tail = Head;
		sports *temp = Head;
		temp->firstName = firstName;
	        temp->lastName = lastName;
	        temp->years[ temp->numWins ] = year;
	        temp->numWins = 1;
	        temp->next = Head;
                temp->prev = Tail;
        }
}

string populateList(){
	string firstName, lastName;
	int year;
	ifstream file("Lab06_QB_List.txt");
	while( file >> firstName ){
		if ( file.is_open() ){
			file >> lastName >> year;
			addEntry( firstName, lastName, year );
        	}else 
			cout << "Unable to open file. \n";
	}
	printList();
	file.close();
}

void removeEntryInput(){
	string firstName, lastName;
	cout << "Entry to remove [first last]: ";
	cin >> firstName >> lastName;
    bool start = true;
	for( sports *temp = Head; (temp != Head) || (start == true); temp = temp->next ){
		if( (temp->firstName == firstName) && (temp->lastName == lastName) ){
			if( temp == Head )
                        	Head = temp->next;
                    	if( temp == Tail )
                        	Tail = temp->prev;
		    	if( temp->prev != 0 )
                        	temp->prev->next = temp->next;
		    	if( temp->next != 0 )
                        	temp->next->prev = temp->prev;
		    	delete temp;
		    	temp = 0;
		    	return;
		}
                start = false;
        }
    	cout << "No matching entry found. \n";
}

void searchPrint(){
    	bool found;
    	while( 1 ){
        	sports *temp = Head;
        	bool start = true;
        	int choice = 0;
        	found = false;
        	string searchInput = "";
        	string searchInput2 = "";
        	cout << "Select an option. \n" <<
	        	" 1: name \n" <<
	        	" 2: year \n" <<
	        	" 3: minimum number of wins \n" <<
	        	" 4: exit menu \n";
        	cin >> choice;
        	if( choice == 4 ) 
			return;
        	cout << "Enter search term: ";
        	cin >> searchInput;
        	switch( choice ){
    			case 1: 
    		        	cin >> searchInput2;
    		        	for( ; (temp != Head) || (start == true); temp = temp->next ){
    		            		if( (temp->firstName == searchInput) && (temp->lastName == searchInput2) ){ 
    		                		printEntry( temp );
    	        	        		found = true;
    	       		     	}
               		     	start = false;
    	       		 	}
    	        		break;
    			case 2:
    				for( ; (temp != Head) || (start == true); temp = temp->next ){
    	        			for( int i = 0; i < 4; i++){
						if( temp->years[ i ] == stoi(searchInput) ){ 
							printEntry( temp );
							found = true;
    	                			}
    	            			}
                    			start = false;
    	        		}
    	        		break;
    			case 3:
    				for( ; (temp != Head) || (start == true); temp = temp->next ){
    	            			if( temp->numWins >= stoi(searchInput) ){ 
    	                			printEntry( temp );
    	                			found = true;
    		        		}
    	            			start = false;
                		}
    	        		break;
    			default: 
				cout << "Invalid input. \n";
    	}
    	if( found == false )
		    cout << "No matching entry found. \n";
    	}
}

void deleteList(){
	if( Head ){
                sports *temp = Head;
		while( Head != Tail){
                        temp = Head;
                	Head = temp->next;
                	delete temp;
		}
		delete Head;
	}
	Head = 0;
        Tail = 0;
}

int main(){
    	populateList();
        int choice = 0;
	while( 1 ){
		cout << "Select an option: \n" <<
		        " 1: search list \n" <<
		        " 2: remove entry \n" <<
		        " 3: print list \n" <<
			" 4: exit \n";
		cin >> choice;
		switch(choice){
			case 1: searchPrint(); break;
			case 2: removeEntryInput(); break;
			case 3: printList(); break;
			case 4: deleteList(); break;
			default: cout << "Invalid number.";
		}
		if(choice == 4){
			break;
		}
	}
	return 0;
}
