#include "Tetromino.h"

#include <iostream>
#include<cstdlib>
using namespace std;

Tetromino::Tetromino() {
  //generate all blocks
  int block1by1_tetromino[1][1] = {1};

  int block2by1_tetromino[2][1] = {{1}, {1}};

  int block3by1_tetromino[3][1] = {{1}, {1}, {1}};

  int block4by1_teromino[4][1] = {{1}, {1}, {1}, {1}};

  int block5by1_teromino[5][1] = {{1}, {1}, {1}, {1}, {1}};

  int block1by2_tetromino[1][2] = {1, 1};

  int block1by3_tetromino[1][3] = {1, 1, 1};

  int block1by4_tetromino[1][4] = {1, 1, 1, 1};

  int block1by5_tetromino[1][5] = {1, 1, 1, 1, 1};

  int block2by2_tetromino[2][2] = {{1, 1}, {1, 1}};

  int block3by3_tetromino[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

  int block2by2L_tetromino[2][2] = {{1, 1}, {0, 1}};

  int blockback2by2L_tetromino[2][2] = {{1, 0}, {1, 1}};

  int block3by3L_tetromino[3][3] = {{1, 0, 0}, {1, 0, 0}, {1, 1, 1}};

  int blockback3by3L_tetromino[3][3] = {{1, 1, 1}, {0, 0, 1}, {0, 0, 1}};


  //setting the current shape
  int *curr_shape[1] = {1};
}

int Tetromino::generate_Block(){
  int randNum = rand() % 15 +1;
  int height = 0;
  int width = 0;
  switch (randNum){
    case 1:
      height = 1;
      width = 1;
      *curr_shape = new int[height];
      for (int r = 0; r < height; r++){
        for (int c = 0; c < width; c++){
          curr_shape[r] = block1by1_tetromino[r][c];
        }
      }
  }
};

int Tetromino::get_tetromino(){
  return *curr_shape;
};