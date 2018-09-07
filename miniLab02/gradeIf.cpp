/* */
#include <iostream>
using namespace std;
int main(){
	string input;
	cout << "Input a letter grade: ";
	cin >> input;
	char letter = input[ 0 ];
	if( letter > 'F' ){
		letter = letter - 0x20;
	}
	if( input.length() > 1 ){
                cerr << "ERROR: ENTER ONE CHARACTER" << endl;
	}else if( (letter < 'A') || (letter > 'F') || letter == 'E' ){
		cerr << "ERROR: ENTER A LETTER GRADE {A, B, C, D, or F}" << endl;
	}else if( letter == 'A' ){
		cout << "A is 100 to 90" << endl;
	}else if( letter == 'B' ){
        	cout << "B is 89 to 80" << endl;
	}else if( letter == 'C' ){
        	cout << "C is 79 to 70" << endl;
	}else if( letter == 'D' ){
        	cout << "D is 69 to 60" << endl;
	}else if( letter == 'F' ){
        	cout << "F is under 60" << endl;
	}

	return 0;
}
