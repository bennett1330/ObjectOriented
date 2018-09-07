/* factorial.cpp
 * 
 * Author: Matt Bennett
 * Description: Takes a positive integer input and returns
 *              the factorial of that integer or an error
 *              message if the value is too large.
 */

#include <iostream>
using namespace std;

unsigned int factorial( unsigned int number );

int main(){
    unsigned int number;
    cout << "Factorial of what number: ";
    cin >> number;
    if( number > 12 ){
        cout << "WAYYYY TOOO BIGGG" << endl;
    }else{
        cout << "Answer: " << factorial( number ) << endl;
    }
}

unsigned int factorial( unsigned int number ){
    if( number != 1 )
        number = number * factorial( number - 1 );
    return number;
}
