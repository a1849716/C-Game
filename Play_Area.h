#ifndef PLAYAREA_H
#define PLAYAREA_H
#include "Tetromino.h"

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

using namespace sf;

class Play_Area{
 private:
  int gridSize;
  bool game_status;
  int filled_rows;
  int score;
  int *isFilled;
  unsigned gridSizeU;
  RenderWindow window;
  Vector2i mousePosScreen;
  Vector2i mousePosWindow;
  Vector2f mousePosView;
  Vector2u mousePosGrid;
  RectangleShape tileSelector;
  RectangleShape gridTile;
 public:
  int set_status(bool gameStatus);
  int get_status();
  int check_rows();
  bool check_game_status();
  void make_game_area();
  Tetromino create_tetromino();
  void update_mouse_positions();
  void draw_area();
};
#endif