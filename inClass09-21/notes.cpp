#include <iostream>
using namespace std;

int passByValue( int value ){
	value = 10;
	return value;
}

int main(){
	int initialValue = 5;
	cout << initialValue << endl;
	initialValue = passByValue( initialValue );
	cout << initialValue << endl;
}
