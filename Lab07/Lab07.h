#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LL_Item{
    private:
        string firstName, lastName;
        int numWins = 0;
        int years[4];
        LL_Item *prev, *next;
    public:
        LL_Item( string firstName, string lastName, int year );
        ~LL_Item();

        string getFirstName();
        string getLastName();
        int getWins();
        int* getYears();
        LL_Item getPrev();
        LL_Item getNext();
        void setPrev( LL_Item newPrev );
        void setNext( LL_Item newNext );
        
        void addYear( int year );
        void print();
};

class LL_Frame{
    private:
        LL_Item *Head = 0;
        LL_Item *Tail = 0;
    public:
        LL_Frame( ifstream file );
        void addItem( string firstName, string lastName, int year );
        ~LL_Frame();
        
        LL_Item getHead();
        LL_Item getTail();
        void setHead( LL_Item *newHead );
        void setTail( LL_Item *newTail );
        
        LL_Item searchName( string firstName, string lastName );
        LL_Item* searchYear( int year );
        void searchWins( int wins );
        void removeItem( LL_Item *entry );
        void removeName( string firstName, string lastName );
        void print();
};
