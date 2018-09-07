#include <iostream>
#include <string>
using namespace std;
template <class T, int N>
class templateArray{
     private:
          T varArray[ N ];
     public:
          void setArray( T varsIn[ N ] ){
               for( int i = 0; i < N; i++ ){
                    varArray[ i ] = varsIn[ i ];
               }
          }
          void getArray(){
               return varArray;
          }
          T findAverage(){
               int sum = (int) varArray[ 0 ];
               for( int i = 1; i < N; i++ ){
                    sum = sum + (int) varArray[ i ];
               }
               T avg = sum/N;
               return avg;
          }
          T findMax(){
               T max = varArray[ 0 ];
               for( int i = 1; i < N; i++ ){
                    if( varArray[ i ] > max ){
                         max = varArray[ i ];
                    }
               }
               return max;
          }
          T findMin(){
               T min = varArray[ 0 ];
               for( int i = 1; i < N; i++ ){
                    if( varArray[ i ] < min ){
                         min = varArray[ i ];
                    }
               }
               return min;
          }
          void print(){
              cout << "[";
              for( int i = 0; i < N; i++ ){
                   cout << varArray[ i ];
                   if( i != N-1 ){
                        cout << ", ";
                   }
              }
              cout << "]" << endl;
          }
};

int main(){
     templateArray<int, 4> myIntArray;
     templateArray<char, 4> myCharArray;
     int intArray[ 4 ] = {1, 2, 4, 5};
     char charArray[ 4 ] = {'a', 'b', 'd', 'e'};
     myIntArray.setArray( intArray );
     myCharArray.setArray( charArray );
     cout << "Int Array" << endl;
     myIntArray.print();
     cout << "Char Array" << endl;
     myCharArray.print();
     cout << "Int Array Max " << myIntArray.findMax() << endl;
     cout << "Char Array Max " << myCharArray.findMax() << endl;
     cout << "Int Array Average " << myIntArray.findAverage() << endl;
     cout << "Char Array Average " << myCharArray.findAverage() << endl;
     cout << "Int Array Min " << myIntArray.findMin() << endl;
     cout << "Char Array Min " << myCharArray.findMin() << endl;
     return 0;
}
