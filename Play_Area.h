#ifndef PLAY_AREA_H
#define PLAY_AREA_H
#include "Tetromino.h"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

using namespace sf;

class Play_Area {
 private:
  const int gridSize;
  bool game_status;
  int filled_rows;
  int score;

 public:
  int set_status();
  int get_status();
  int check_rows();
  bool check_game_status();
  Tetromino create_tetromino();
};
#endif