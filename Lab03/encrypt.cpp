/*
 * encrypt.cpp
 * ELEC3150: Lab03
 * Matt Bennett (bennetts4@wit.edu)
 */
 
#include <iostream>
#include <string.h>
using namespace std;
 
char* encrypt( char *cryptChars );
 
int main(){
     char origChars[ 100 ];
     string cryptStr;
     string yesNo;
     while( true ){
         cout << "Enter a string to encrypt: ";
         cin.getline( origChars, 100 );
         cryptStr = (string) encrypt( origChars );
         cout << "Encrypted: " << cryptStr << endl;
         cout << "Encrypt another string? (Y/N) ";
         cin >> yesNo;
         if( (yesNo == "y") || (yesNo == "Y") ){
             memset( origChars, 0, 100 );
             cin.ignore();
             cin.clear();
             continue;
         }else{
             break;
         }
     }
}
 
char* encrypt( char *cryptChars ){
     for( int i = 0; i < 100; i++ ){
         if( cryptChars[ i ] == '\0' ){
             return cryptChars;
         }
         char curr = cryptChars[ i ];
         if( (curr >= 32) && (curr <= 121)){
            cryptChars[ i ] = curr + 5;
         }else if( curr <= 126 ){
            cryptChars[ i ] = curr - 90;     
         }
         
     }
     //cout << "No null detected." << endl;
     return cryptChars;
}
