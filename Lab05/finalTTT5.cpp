/*
 * finalTTT5.cpp
 * ELEC3150: Lab05
 * Matt Bennett
 * Eduardo Cortes
 */

#include <iostream>
using namespace std;

typedef char printTTT[3][3];

void intBoard(printTTT board) {
    for(int r = 0; r < 3; r++)
        for(int c = 0; c < 3; c++)
            board[r][c] = '-';
}

void printBoard(printTTT board) {
    for(int r = 0; r < 3; r++) {
        for(int c = 0; c < 3; c++)
            cout << board[r][c] <<' ';
        cout<<'\n';
    }
    cout<<'\n';
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


void insertO(char (&board)[3][3])
{
    
    //CHECK FOR WIN
    int counterDiag = 0;
    for(int i = 0; i < 3; i++)
    {
        if (board[i][i] == 'O')
        {
            counterDiag++;
        }
        else if (board[i][i] == 'X')
        {
            counterDiag = -1;
        }
        int numbRow = 0;
        int numbCol = 0;
        for (int j = 0; j < 3; j++ )
        {
            if (board[i][j] == 'O' )
                numbRow++;
            else if( board[i][j] == 'X' )
                numbRow = -1;
            if( board[j][i] == 'O')
                numbCol++;
            else if (board[j][i] == 'X')
                numbCol = -1;
        }
        if (numbRow == 2)
        {
            // CHECK FOR WIN (3 - ROW)
            board[i][0] = 'O';
            board[i][1] = 'O';
            board[i][2] = 'O';
            return;
        }
        if (numbCol == 2)
        {
            // CHECK FOR WIN (3 - COLUMN)
            board[0][i] = 'O';
            board[1][i] = 'O';
            board[2][i] = 'O';
            return;
        }
    }
    if (counterDiag == 2)
    {
        board[0][0] = 'O';
        board[1][1] = 'O';
        board[2][2] = 'O';
        return;
    }
    int counterDiag2 = 0;
    for (int i = 0, j = 2; i < 3; i++, j-- )//Increment i, decrement j
    {
        if (board[i][j] == 'O')
        {
            counterDiag2++;
        }
        else if (board[i][j] == 'X' )
        {
            counterDiag2 = -1;
        }
    }
    if (counterDiag2 == 2 )
    {
        board[0][2] = 'O';
        board[1][1] = 'O';
        board[2][0] = 'O';
        return;
    } // ELSE YOU CANNOT WIN THIS TURN
    
    //BLOCK PLAYER X FROM COMPLETING ROW OR COLUMN OR DIAGONAL
    if ((board[0][0] == 'X') && (board[0][1] == 'X') && (board[0][2]!='O'))
    {
        board[0][2] = 'O';
        return;
    }
    else if (board[0][1]=='X' && board[0][2] =='X' && board[0][0]!='O')
    {
        board[0][0] = 'O';
        return;
    }
    else if (board[0][0]=='X' && board[0][2]=='X' && board[0][1]!='O')
    {
        board[0][1] = 'O';
        return;
    }
    else if (board[1][0]=='X' && board[1][1]=='X' && board[1][2]!='O')
    {
        board[1][2] = 'O';
        return;
    }
    else if (board[1][1] == 'X' && board[1][2] == 'X' && board[1][0] != 'O')
    {
        board[1][2] = 'O';
        return;
    }
    else if (board[1][0]=='X' && board[1][2]=='X' && board[1][1]!='O')
    {
        board[1][1] = 'O';
        return;
    }
    else if (board[2][0]=='X' && board[2][1]=='X' && board[2][2]!='O')
    {
        board[2][2] = 'O';
        return;
    }
    else if (board[2][1]=='X' && board[2][2]=='X' && board[2][0]!='O')
    {
        board[2][0] = 'O';
        return;
    }
    else if (board[2][0]=='X' && board[2][2]=='X' && board[2][1]!='O')
    {
        board[2][1] = 'O';
        return;
    }
    else if (board[0][0]=='X' && board[1][0]=='X' && board[2][0]!='O')
    {
        board[2][0] = 'O';
        return;
    }
    else if (board[1][0]=='X' && board[2][0]=='X' && board[0][0]!='O')
    {
        board[0][0] = 'O';
        return;
    }
    else if (board[0][0]=='X' && board[2][0]=='X' && board[1][0]!='O')
    {
        board[1][0] = 'O';
        return;
    }
    else if (board[0][1]=='X' && board[1][1]=='X' && board[2][1]!='O')
    {
        board[2][1] = 'O';
        return;
    }
    else if (board[1][1]=='X' && board[2][1]=='X' && board[0][1]!='O')
    {
        board[0][1] = 'O';
        return;
    }
    else if (board[0][1]=='X' && board[2][1]=='X' && board[1][1]!='O')
    {
        board[1][1] = 'O';
        return;
    }
    else if (board[0][2]=='X' && board[1][2]=='X' && board[2][2]!='O')
    {
        board[2][2] = 'O';
        return;
    }
    else if (board[1][2]=='X' && board[2][2]=='X' && board[0][2]!='O')
    {
        board[0][2] = 'O';
        return;
    }
    else if (board[0][2]=='X' && board[2][2]=='X' && board[1][2]!='O')
    {
        board[1][2] = 'O';
        return;
    }
    else if (board[0][0]=='X' && board[1][1]=='X' && board[2][2]!='O')
    {
        board[2][2] = 'O';
        return;
    }
    else if (board[1][1]=='X' && board[2][2]=='X' && board[0][0]!='O')
    {
        board[0][0] = 'O';
        return;
    }
    else if (board[0][0]=='X' && board[2][2]=='X' && board[1][1]!='O')
    {
        board[1][1] = 'O';
        return;
    }
    else if (board[2][0]=='X' && board[1][1]=='X' && board[0][2]!='O')
    {
        board[0][2] = 'O';
        return;
    }
    else if (board[1][1]=='X' && board[0][2]=='X' && board[2][0]!='O')
    {
        board[2][0] = 'O';
        return;
    }
    else if (board[2][0] =='X' && board[0][2]=='X' && board[1][1]!='O')
    {
        board[1][1] = 'O';
        return;
    }
    
    
    //IF PLAYER X STARTS AT CENTER
    if ((board[1][1] == 'X') && (board[0][0] == '-'))
    {
        board[0][0] = 'O';
        return;
    }
    
    //IF PLAYER X STARTS ON EDGE OR CONER
    
    if ((board[0][0] == 'X' && board[0][0] == '-') ||
        (board[0][1] == 'X' && board[0][1] == '-') ||
        (board[0][2] == 'X' && board[0][2] == '-') ||
        (board[1][0] == 'X' && board[1][0] == '-') ||
        (board[1][2] == 'X' && board[1][2] == '-') ||
        (board[2][0] == 'X' && board[2][0] == '-') ||
        (board[2][1] == 'X' && board[2][1] == '-') ||
        (board[2][2] == 'X' && board[2][2] == '-'))
    {
        board[1][1] = 'O';
        return;
    }
    
    for (int i = 0; i < 3; i++)
    {
        
        for (int j = 0; j < 3; j++)
        {
            
            if (board[i][j] == '-')
            {
                
                board[i][j] = 'O';
                return;
            }
        }
    }
    
}

bool isWin(char (&board)[3][3])//Make bool?
{
    int sumRows = 0;
    int sumCols = 0;
    int sumDiag1 = 0;
    int sumDiag2 = 0;
    
    for (int i = 0; i < 3; i++) //rows
    {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
        {
            sumRows++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
        {
            //Could be a bool
            sumCols++;
        }
    }
    
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) //diagonals
    {
        sumDiag1++;
    }
    
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
    {
        sumDiag2++;
    }
    
    if ((sumRows > 2) || (sumCols > 2) || (sumDiag1 > 2) || (sumDiag2 > 2))
    {
        return true;
    }
    return false;
    
}

bool isDraw(char (&board)[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                return false;
            }
        }
    }
    
    return true;
}

int main()
{
    printTTT board;
    intBoard(board);
    
    while (true)
    {
        printBoard(board);
        insertX(board);
        if (isWin(board))
        {
            cout << "X wins!" << endl;
            printBoard(board);
            break;
        }
        if (isDraw(board))
        {
            cout << "It's a draw!" << endl;
            printBoard(board);
            break;
        }
        printBoard(board);
        insertO(board);
        if (isWin(board))
        {
            cout << "O wins!" << endl;
            printBoard(board);
            break;
        }
        if (isDraw(board))
        {
            
            cout << "It's a draw!" << endl;
            printBoard(board);
            break;
        }
        
        
    }
    
    
}

