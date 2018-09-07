#include <iostream>
using namespace std;

void cardCounter( int val, int &ref );

int main(){
	int cardCount = 0;
	cardCounter( 9, cardCount );
	cout << "The current card count is: " << cardCount << endl;
	cardCounter( 2, cardCount );
	cout << "The current card count is: " << cardCount << endl;
	cardCounter( 10, cardCount );
	cout << "The current card count is: " << cardCount << endl;
	cardCounter( 13, cardCount );
	cout << "The current card count is: " << cardCount << endl;
	cardCounter( 7, cardCount );
	cout << "The current card count is: " << cardCount << endl;
}

void cardCounter( int val, int &ref ){
        if( val > 9 ){
                ref--;
        }else{
                ref++;
        }
}

