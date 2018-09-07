/*
 * decrypt.cpp
 * ELEC3150: Lab03
 * Matt Bennett (bennetts4@wit.edu)
 */
 
#include <iostream>
#include <string.h>
using namespace std;
 
char* decrypt( char *origChars );
 
int main(){
     char cryptChars[ 100 ];
     string origStr;
     string yesNo;
     while( true ){
         cout << "Enter a string to decrypt: ";
         cin.getline( cryptChars, 100 );
         origStr = (string) decrypt( cryptChars );
         cout << "Decrypted: " << origStr << endl;
         cout << "Decrypt another string? (Y/N) ";
         cin >> yesNo;
         if( (yesNo == "y") || (yesNo == "Y") ){
             memset( cryptChars, 0, 100 );
             cin.ignore();
             cin.clear();
             continue;
         }else{
             break;
         }
     }
}
 
char* decrypt( char *origChars ){
     for( int i = 0; i < 100; i++ ){
         if( origChars[ i ] == '\0' ){
             return origChars;
         }
         char curr = origChars[ i ];
         if( (curr >= 37) && (curr <= 126)){
            origChars[ i ] = curr - 5;
         }else if( curr >= 32 ){
            origChars[ i ] = curr + 90;     
         }
         
     }
     //cout << "No null detected." << endl;
     return origChars;
}
