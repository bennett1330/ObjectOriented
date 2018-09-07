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
		return 0;
	}
	switch( letter ){
        	case 'A' :
                	cout << "A is 100 to 90" << endl;
        		break;
		case 'B' :
                	cout << "B is 89 to 80" << endl;
			break;
		case 'C' :
                	cout << "C is 79 to 70" << endl;
        		break;
		case 'D' :
                	cout << "D is 69 to 60" << endl;
        		break;
		case 'F' :
                	cout << "F is under 60" << endl;
			break;
		default :
			cerr << "ERROR: ENTER A LETTER GRADE {A, B, C, D, or F}" << endl;
	}
        return 0;
}
