/*
 * miniLab06.cpp
 * ELEC 3150 miniLab 06
 * Matt Bennett (bennetts4@wit.edu)
 */
#include <iostream>
#include <string>
using namespace std;

int main(){
     char charArray[ 8 ] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
     char *ptrChar = &charArray[ 0 ];
     for( int i = 0; i < 8; i++, ptrChar++ ){
         cout << *ptrChar << endl;
     }

     /*double doubArray[ 8 ] = { 1, 2, 3, 4, 5, 6, 7, 8 };
     double *ptrDoub = &doubArray[ 0 ];
     for( int i = 0; i < 8; i++, ptrDoub++ ){
         cout << *ptrDoub << endl;
     }*/
     return 0;
}
