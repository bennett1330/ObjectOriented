#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Player{
  private:
     string name;
     int number;
     int shoot2Acc, shoot3Acc;
  public:   
     Player(){}
     Player( string name, int number, int shoot2Acc, int shoot3Acc ) 
          : name( name )
          , number( number )
          , shoot2Acc( shoot2Acc )
          , shoot3Acc( shoot3Acc )
     {}
     int takeShot( int twoOrThree ){
          int actual = rand() % 100 + 1;
          if( (twoOrThree == 3) && (actual <= shoot3Acc) ){
               return 3;
          }else if( (twoOrThree == 2) && (actual <= shoot2Acc) ){
               return 2; 
          }else{
               return 0;
          }
     }
     string getName(){
          return this->name;
     }
     int getNumber(){
          return this->number;
     }
     int getAccur2(){
          return this->shoot2Acc;
     }
     int getAccur3(){
          return this->shoot3Acc;
     }
};

Player randPlayer( Player playerArray[ 5 ] ){
     return playerArray[ rand() % 5 ];
}

bool accuracySum( Player playerArray[ 5 ] ){
     int accur2 = 0;
     int accur3 = 0;
     for( int i = 0; i < 5; i++ ){
         accur2 = accur2 + playerArray[ i ].getAccur2();
         accur3 = accur3 + playerArray[ i ].getAccur3();
     }
     if( (accur2 <= 300) && (accur3 <= 200) ){
          return true;
     }
     return false;
}

int main(){
     srand ( time(NULL) );
     Player playerArray[ 5 ];
     // construct players
     playerArray[ 0 ] = *( new Player( string("John Smith"), 0, 60, 40 ));
     playerArray[ 1 ] = *( new Player( string("Tony Stark"), 1, 60, 40 ));
     playerArray[ 2 ] = *( new Player( string("Dr. Strange"), 2, 60, 40 ));
     playerArray[ 3 ] = *( new Player( string("Butterfingers"), 3, 60, 40));
     playerArray[ 4 ] = *( new Player( string("Newbie"), 4, 60, 40));
     // take 100 shots
     int points = 0;
     int shotPts;
     for( int i = 1; i <= 100; i++ ){
           Player shooter = randPlayer( playerArray );
           int twoOrThree = rand() % 2 + 2;
           shotPts = shooter.takeShot( twoOrThree );
           points = points + shotPts;
           cout << "Shot " << i << " : " << shotPts
                << " Points - Player " << shooter.getNumber() 
                << " " << shooter.getName() << endl;
           cout << "Total is " << points << " points." <<  endl;
     }
     cout << "Accuracies within specifications? " << (accuracySum( playerArray ) ? "true" : "false") << endl; 
     return 0;
}



#endif
