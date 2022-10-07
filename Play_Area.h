#ifndef PLAY_AREA_H
#define PLAY_AREA_H
#include "Tetromino.h"

class Play_Area {
 private:
  char** area;
  bool game_status;
  int filled_rows;

 public:
  int set_status();
  int get_status();
  int check_rows();
  bool check_game_status();
  Tetromino create_tetromino();
};
#endif