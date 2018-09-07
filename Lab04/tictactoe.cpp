/******************************************
*   Template by Aaron Carpenter
*   ELEC 3150 - OOPs
*   EET Dept., WIT
*   Tic-Tac-Toe Lab (#6)
******************************************/

#include <iostream>
using namespace std;

void printTTT( char (&TTTarray)[3][3] );
void insertX( char (&TTTarray)[3][3] );
void insertO( char (&TTTarray)[3][3] );
void checkForWin( char (&TTTarray)[3][3] ); // IGNORE THIS FOR NOW

int main( ){

    char TTTarray[3][3] = { {'-','-','-'},
                            {'-','-','-'},
                            {'-','-','-'}};
    insertX( TTTarray );
    printTTT( TTTarray );    

    char TTTarray2[3][3] = { {'-','X','-'},
                            {'-','X','-'},
                            {'-','-','O'}};

    insertX( TTTarray2 );
    printTTT( TTTarray2 );

    char TTTarray3[3][3] = { {'-','-','-'},
                            {'-','X','-'},
                            {'-','O','-'}};
    insertX( TTTarray3 );
    printTTT( TTTarray3 );

    char TTTarray4[3][3] = { {'X','-','X'},
                            {'-','-','-'},
                            {'O','-','-'}};

    insertX( TTTarray4 );
    printTTT( TTTarray4 );

    char TTTarray5[3][3] = { {'X','-','X'},
                            {'O','X','-'},
                            {'O','-','O'}};

    insertX( TTTarray5 );
    printTTT( TTTarray5 );

    char TTTarray6[3][3] = { {'X','-','-'},
                            {'O','X','-'},
                            {'O','-','O'}};

    insertX( TTTarray6 );
    printTTT( TTTarray6 );


    //insertX( TTTarray );
    //OR
    //insertO( TTTarray );

    //printTTT( TTTarray );

    /*****************
    I have included the declaratoin of the array, initialized to - for each spot.
    The '-' represents an empty position.  You should fill it with either a 
    capital 'O' or a capital 'X'. I have also included a number of initialized arrays 
    to test; just comment out the ones you don't want for that moment
    *****************/
    return 0;
}

void printTTT( char (&TTTarray)[3][3] ){
    /*****************
    print out the Tic-Tac-Toe grid
    *****************/
    for( int i=0; i < 3; i++ ){
        for( int j=0; j < 3; j++ ){
            cout << TTTarray[ i ][ j ];
        }
        cout << endl;
    }
    cout << endl;
}

void insertX( char (&TTTarray)[3][3] ){
    // Check if empty board, place center if empty
    int openCount = 0;
    for( int i=0; i < 3; i++ ){
        for( int j=0; j < 3; j++ ){
            if( TTTarray[ i ][ j ] == '-' )
                openCount++;
        }
    }    
    if( openCount == 9 ){
        TTTarray[ 1 ][ 1 ] = 'X';
        return;
    }

    // First check if you can win this turn
    int countXDiag1 = 0;
    for( int i=0; i < 3; i++ ){
         if( TTTarray[ i ][ i ] == 'X' )
              countXDiag1++;
         else if( TTTarray[ i ][ i ] == 'O' )
              countXDiag1 = -1;

         int countXRow = 0;
         int countXCol = 0;
         for( int j=0; j < 3; j++ ){
               if( TTTarray[ i ][ j ] == 'X' )
                    countXRow++;
               else if( TTTarray[ i ][ j ] == 'O' )
                    countXRow = -1;
               if( TTTarray[ j ][ i ] == 'X' )
                    countXCol++;
               else if( TTTarray[ j ][ i ] == 'O' )
                    countXCol = -1;
         }
         if( countXRow == 2 ){ // You can get 3 in a row
               TTTarray[ i ][ 0 ] = 'X';
               TTTarray[ i ][ 1 ] = 'X';
               TTTarray[ i ][ 2 ] = 'X';
               return;
         }
         if( countXCol == 2 ){ // You can get 3 in a col
               TTTarray[ 0 ][ i ] = 'X';
               TTTarray[ 1 ][ i ] = 'X';
               TTTarray[ 2 ][ i ] = 'X';
               return;
         }
    }
    if( countXDiag1 == 2 ){
         TTTarray[ 0 ][ 0 ] = 'X';
         TTTarray[ 1 ][ 1 ] = 'X';
         TTTarray[ 2 ][ 2 ] = 'X';
         return;
    }
    int countXDiag2 = 0;
    for( int i=0, j=2; i < 3; i++, j-- ){
        if( TTTarray[ i ][ j ] == 'X' )
            countXDiag2++;
        else if( TTTarray[ i ][ j ] == 'O' )
            countXDiag2 = -1;
    }
    if( countXDiag2 == 2 ){
          TTTarray[ 0 ][ 2 ] = 'X';
          TTTarray[ 1 ][ 1 ] = 'X';
          TTTarray[ 2 ][ 0 ] = 'X';
          return;
    } // X cannot win this turn
 
    // Second check if O could win next turn (and stop it)
    int countODiag1 = 0;
    for( int i = 0; i < 3; i++ ){
        if( TTTarray[ i ][ i ] == 'O' )
            countODiag1++;
       
        int countORow = 0;
        int countOCol = 0;
        for( int j = 0; j < 3; j++ ){
              if( TTTarray[ i ][ j ] == 'O' )
                  countORow++; 
              if( TTTarray[ j ][ i ] == 'O' )
                  countOCol++;
        }
        if( countORow == 2 ){
              for( int j=0; j < 3; j++ ){
                  if( TTTarray[ i ][ j ] == '-' ){
                      TTTarray[ i ][ j ] = 'X';
                      return;
                  }
              }
        }
        if( countOCol == 2 ){
             for( int j=0; j < 3; j++ ){
                  if( TTTarray[ j ][ i ] == '-' ){
                      TTTarray[ j ][ i ] = 'X';
                      return;
                  }
             }
        }
    }
    if( countODiag1 == 2 ){
        for( int i=0; i < 3; i++ ){
            if( TTTarray[ i ][ i ] == '-' ){
                 TTTarray[ i ][ i ] = 'X';
                 return;
             }
        }
    }
    int countODiag2 = 0;
    for( int i=0, j=2; i < 3; i++, j-- ){
        if( TTTarray[ i ][ j ] == 'O' )
             countODiag2++;
    }
    if( countODiag2 == 2 ){
        for( int i=0, j=2; i < 3; i++, j-- ){
            if( TTTarray[ i ][ j ] == '-' ){
                TTTarray[ i ][ j ] = 'X';
                return;
            }
        }
    }// O cannot win next turn

    // Third try to place in corners
    for( int i=0; i < 3; i=i+2 ){
        for( int j=0; j < 3; j=j+2 ){
            if( TTTarray[ i ][ j ] == '-' ){
                TTTarray[ i ][ j ] = 'X';
                return;
            }
        }
    }// Cannot place in the corners

    // Only place left is sides
    for( int i=0; i < 2; i++ ){
        if( TTTarray[ i ][ i+1 ] == '-' ){
            TTTarray[ i ][ i+1 ] = 'X';
            return;
        }
    }
    for( int i=1; i < 3; i++ ){
        if( TTTarray[ i ][ i-1 ] == '-' ){
            TTTarray[ i ][ i-1 ] = 'X';
            return;
        }
    }
}

void insertO( char (&TTTarray)[3][3] ){

}

