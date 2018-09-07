#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
     srand( time(NULL) );
     vector<int> v;
     v.clear();
     for( int i = 0; i < 5; i++ ){
         v.push_back( rand() % 100 + 1 );
     }
     sort( v.begin(), v.end() );
     cout << "<";
     for( int i = 0; i < 5; i++ ){
         cout << v.at( i );
         if( i != 4 ){
             cout << ", ";
         }
     }
     cout << ">" << endl;
     return 0;
}
