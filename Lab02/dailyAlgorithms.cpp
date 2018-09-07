/*
 * dailyAlgorithms.cpp
 * ELEC 3150 Lab 02
 * Matt Bennett (bennetts4@wit.edu)
 */
#include <iostream>
#include <string>
using namespace std;

void badInputResponse(){
	cout << "You aren't following instructions" << endl;
	//cin.ignore();
	cin.clear();
	return;
}
bool validInput( string dayWeek, string strTime ){
	if( ( dayWeek != "Sunday" ) &&
	    ( dayWeek != "Monday" ) &&
	    ( dayWeek != "Tuesday" ) &&
	    ( dayWeek != "Wednesday" ) &&
	    ( dayWeek != "Thursday" ) &&
	    ( dayWeek != "Friday" ) &&
	    ( dayWeek != "Saturday" ) ){
		return false;
	}
	
	if( (strTime.length()) != 7 ){
		return false;
	}
	
    char sep = strTime[ 2 ];
	if( sep != ':' ){
		return false;
	}
	
	string dayNight = strTime.substr( 5, 2 );
	if( ( dayNight != "am" ) && ( dayNight != "pm" ) ){
	    return false;
	}
	
	string strHour = strTime.substr( 0, 2 );
	string strMin = strTime.substr( 3, 2 );
	try{
		int hour = stoi( strHour );
	 	int min = stoi( strMin );
                if( (hour > 12) || (min > 59) ){
            		return false;
        	}
	} catch( int e ){
		return false;
	}
	return true;
}

int main(){
	while( 1 ){ //Do Until Break
		// Prompt and get user input
		string dayWeek;
		string strTime;
		cout << "Enter day and time [Day HH:MMam/pm] or q to quit: ";
		cin >> dayWeek;
		if( dayWeek == "q" ){
		    break;
		}
		cin >> strTime;
		cout << endl;
        if( !validInput( dayWeek, strTime ) ){
            badInputResponse();
            continue;
        }
        string strHour = strTime.substr( 0, 2 );
    	int hour = stoi( strHour );
            string strMin = strTime.substr( 3, 2 );
    	int min = stoi( strMin );
            string dayNight = strTime.substr( 5, 2 );
    	if( (dayNight == "pm") && (hour != 12) ){
    		hour = hour + 12;
    	}else if( (dayNight == "am") && (hour == 12) ){
    		hour = hour + 12;
    	}
    	cout << "On " << dayWeek << " between ";
    	if( (hour >= 23) || (hour < 8) ){
    		cout << "11:00pm and 7:59am I am sleeping." << endl;
    	}else if( (hour >= 12) && (hour < 13) ){
    		cout << "12:00pm and 12:59pm I am eating." << endl;
    	}else if( (hour >= 18) && (hour < 19) ){
    		cout << "6:00pm and 6:59pm I am eating." << endl;
    	}else if( (dayWeek == "Sunday") && (dayWeek == "Saturday") ){
    		cout << "8:00am and 10:59pm I am wasting time." << endl;
    	}else if( (hour >= 9) && (hour < 17) ){
    		cout << "9:00am and 3:00pm I am in school." << endl;
    	}else{
    		cout << strHour << ":" << strMin << dayNight << " I am wasting time." << endl;
    	}
	}
}
