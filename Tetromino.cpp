#include "Tetromino.h"

#include <iostream>
using namespace std;

Tetromino::Tetromino() {
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
}
