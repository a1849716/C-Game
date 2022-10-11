#include "Play_Area.h"
#include "Tetromino.h"
#include <string>
using namespace std;

Play_Area::Play_Area(){
  gridSize = 10;
  game_status = false;
  filled_rows = 0;
  score = 0;
}

int set_status(bool gameStatus){
  game_status = gameStatus;
};
int get_status(){
  cout << game_status << endl;
  return game_status;
};
int check_rows(){
  //for loop from 1 - 10
  for (int r = 0; r< gridSize; r++){
    //variable to check if add if there is block
    int filled = 0;
    //for loop from 1 - 10 for columns
    for (int c = 0; c < gridSize; c++){
      // if block is filled 
      if (isFilled[r][c] == 1){
        //add 1 to filled
        filled++;
        //once filled becomes 10
        if (filled == 10){
          //empty the row from 1 to 0
          for (int rc = 0; rc < 10; rc++){
            //replace the row with 0
            isFilled = 0;
          }
        }
      }
    }
  }
};
bool check_game_status(){
  
};
Tetromino create_tetromino();
