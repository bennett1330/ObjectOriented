/* arrayReversal.cpp
 * ELEC 3150 Lab 01
 * Matt Bennett (bennetts4@wit.edu)
 */
#include <iostream>
using namespace std;

/*
 * Creates and returns integer array of constant integer length where element
 * value corresponds to element index.
 */
int* createArray( const int n ){
	int* A = new int[ n ];         // initialize array to store n integer values
	for ( int i = 0; i < n; i++ ){ // iterate over each array element index
		A[ i ] = i;            // populate array element with value of index
	}
	return A;                      // pass populated array of length n with each
	                               // integer element equal to the value of the index
}

/*
 * Reverses elements in integer array of constant integer length and returns the array
 */
int* reverseArray( const int n, int* A ){
	int temp;                      // temp is an iteger variable for storing values
                                       // while swapping element values so the value is
                                       // not lost when overwritten
	int elemHigh = n - 1;          // elemHigh is the greater index of the two that
                                       // will be swapped 
	int lowThresh = n/2;           // lowTresh is the point at which all of the values
                                       // have been swapped (half way point since moving
                                       // from outside in)
	for ( int elemLow = 0; elemLow < lowThresh; elemLow++){
                                       // iterate from 0 index element to halfway element
		temp = A[ elemLow ];   // store value at lesser element index so not lost
		A[ elemLow ] = A[ elemHigh ];
                                       // overwrite value at lesser element index with
                                       // value at higher element index
		A[ elemHigh ] = temp;  // overwrite value at higher element index with
                                       // temp value, value that was in lesser element
                                       // before it was overwritten
		elemHigh--;            // decrement the index of higher element to correspond
                                       // to the incrementing index of lower element
	}
	return A;                      // pass reversed array back
}
/*
 * Prints output to the console that displays the integer array index and value of
 * each element.
 */
void printArray( const int n, int* A ){
        for ( int i = 0; i < n; i++ ){ // iterate over each element of array A
                cout << "A[ " << i << " ] = " << A[ i ] << endl;
        }                              // print array A element to console
        cout << endl << endl;          // print line break for formatting
}

int main(){
        const int n = 20;              // n is a constant integer representing array length
                                       // n defaults to int 20
	int* A = createArray( n );     // call createArray function to populate array A
	printArray( n, A );            // print ordered array A elements to the console
	A = reverseArray( n, A );      // call reverseArray function to reorder array A elements
	printArray( n, A );            // print reordered array A elements to the console
        return 0;                      // exit 0 on success
}

