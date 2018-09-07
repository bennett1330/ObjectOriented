#ifndef LL_H_
#define LL_H_

#include "Lab07.h"

using namespace std;


LL_Item::LL_Item( string firstName, string lastName, int year ){
    this->firstName = firstName;
    this->lastName = lastName;
    this->years[ 0 ] = year;
}

LL_Item::~LL_Item(){

}

string LL_Item::getFirstName(){
    return firstName;
}
string LL_Item::getLastName(){
    return lastName;
}
int LL_Item::getWins(){
    return numWins;
}
int* LL_Item::getYears(){
    return years;
}
LL_Item LL_Item::getPrev(){
    return *prev;
}
LL_Item LL_Item::getNext(){
    return *next;
}
void LL_Item::setPrev( LL_Item newPrev ){
    *prev = newPrev;
}
void LL_Item::setNext( LL_Item newNext ){
    *next = newNext;
}
void LL_Item::addYear( int year ){
    years[ numWins ] = year;
	numWins++;
}
void LL_Item::print(){
    cout << "Name: " << firstName << " " << lastName;
	cout << " Number of wins: " << numWins;
	cout << " Years: ";
	for( int i = 0; i < 4; i++ ){
    	if( years[ i ] != 0 )
        		cout << years[ i ] << " ";
	}
	cout << endl;
}



LL_Frame::LL_Frame( ifstream file ){
    string firstName, lastName;
    int year;
    while( file >> firstName ){
		if ( file.is_open() ){
			file >> lastName >> year;
			addItem( firstName, lastName, year );
        }else 
			cout << "Unable to open file. \n";
	}
}
void LL_Frame::addItem( string firstName, string lastName, int year ){
    if( Head ){
        LL_Item *temp = searchName( firstName, lastName );
        if( temp != 0 ){
            temp->addYear( year );
            return;
        }
        LL_Item *newItem = new LL_Item( firstName, lastName, year );
	    temp->setNext( *newItem );
        *Tail = temp->getNext();
	    Tail->setPrev( *temp );
        Tail->setNext( *Head );
        Head->setPrev( *Tail );
    }else{
        LL_Item *newItem = new LL_Item( firstName, lastName, year );
		*Head = *newItem;
        *Tail = *Head;
	    Head->setNext( *Head );
        Head->setPrev( *Tail );
    }
}

LL_Frame::~LL_Frame(){
    if( Head ){
        LL_Item *temp = *Head;
	    while( Head != Tail){
            *temp = *Head;
            *Head = temp->getNext();
            delete temp;
	    }
	    delete Head;
	}
    Head = 0;
    Tail = 0;
}

LL_Item LL_Frame::getHead(){
    return *Head;
}
LL_Item LL_Frame::getTail(){
    return *Tail;
}
void LL_Frame::setHead( LL_Item *newHead ){
    *Head = *newHead;    
}
void LL_Frame::setTail( LL_Item *newTail ){
    *Tail = *newTail;
}
LL_Item LL_Frame::searchName( string firstName, string lastName ){
    bool start = true;
	for( LL_Item *temp = *Head; (temp != Head) || (start == true); *temp = temp->getNext() ){
		if( (temp->getFirstName() == firstName) && (temp->getLastName() == lastName) ){
			temp->print();
		    return *temp;
		}
        start = false;
    }
    cout << "No matching entry found. \n";
    return *temp = &0;
}
LL_Item LL_Frame::searchYear( int year ){
    bool start = true;
	for( LL_Item *temp = *Head; (temp != Head) || (start == true); *temp = temp->getNext() ){
	    int* yrs = temp->getYears();
	    for( int i = 0; i < 4; i++){
		    if( yrs[ i ] == year ){ 
		    	temp->print();
			    return *temp;
        	}
    	}
		start = false;
	}
	cout << "No matching entry found. \n";
	return NULL;
}
void LL_Frame::searchWins( int wins ){
    bool start = true;
    bool found = false;
	for( LL_Item *temp = *Head; (temp != Head) || (start == true); *temp = temp->getNext() ){
        if( (temp->getWins >= wins ){
			temp->print();
		    found = true;
		}
		start = false;
	}
	if( found == false ){
	    cout << "No matching entry found. \n";
	}
}
void LL_Frame::removeItem( LL_Item* temp ){
	if( temp == Head )
        *Head = temp->getNext();
    if( temp == Tail )
        *Tail = temp->getPrev();
    if( temp->getPrev != 0 )
    	*( temp->getPrev() )->setNext( temp->getNext() );
    if( temp->getNext() != 0 )
    	*( temp->getNext() )->setPrev( temp->getPrev() );
    delete temp;
    temp = 0;
}
void LL_Frame::removeName( string firstName, string lastName ){
    *temp = searchName( firstName, lastName );
    removeItem( *temp );
}
void LL_Frame::print(){
    bool start = true;
    for( LL_Item *temp = *Head; (temp != Head) || (start == true) ; *temp = temp->getNext() ){
        temp->print();
        start = false;
    }
}


int main(){
    ifstream file1("Lab07_QB_List.txt");
    LL_Frame sports = new LL_Frame( file1 );
    file1.close();
    ifstream file2("Lab07_EM_List.txt");
    LL_Frame nerds = new LL_Frame( file2 );
    file2.close();
    sports.print();
    nerds.print();
    return 0;
}
#endif