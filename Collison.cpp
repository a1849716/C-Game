#include "Collision.h"
#include "Tetromino.h"
#include "Play_Area.h"

Collision::Collision(int height, int width){
  WINDOW_HEIGHT = height;
  WINDOW_WIDTH = width;
  curr_shape = Tetromino.get_curr_shape;
}

void Collision::check_for_collision(){
  // Left screen collision
  if (curr_shape.getPosition().x < 0) {
    curr_shape.setPosition(0, curr_curr_shape.getPosition().y);
  }
  // Right screen collision
  if (curr_shape.getPosition().x + curr_curr_shape.getGlobalBounds().width > WINDOW_WIDTH) {
    curr_shape.setPosition(WINDOW_WIDTH - curr_shape.getGlobalBounds().width,
                      curr_shape.getPosition().y);
  }
  // Bottom screen collision
  if (curr_shape.getPosition().y + curr_shape.getGlobalBounds().height > WINDOW_HIGHT) {
    curr_shape.setPosition(WINDOW_HIGHT - curr_shape.getGlobalBounds().height,
                      curr_shape.getPosition().y);
  }
  // Top screen collision
  if (curr_shape.getPosition().y + curr_shape.getGlobalBounds().height < WINDOW_HIGHT) {
    curr_shape.setPosition(WINDOW_HIGHT - curr_shape.getGlobalBounds().height,
                      curr_shape.getPosition().y);
  }
}