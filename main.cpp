#include "SFML/Graphics.hpp"
#include <iostream>
#include "Move.h"

using namespace sf;
using namespace std;

int main() {
  const int WINDOW_WIDTH = 600;
  const int WINDOW_HIGHT = 1200;
  // Make window with size 600 x 1200 for play size, additional info will
  // require more space which will be added on later
  RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "SCUFFED TETRIS",
                      Style::Close | Style::Titlebar);
  window.setFramerateLimit(60);
  float gridSize = 60.0;
  RectangleShape Shape(Vector2f(gridSize - 2, (gridSize * 2) - 2));
  Shape.setFillColor(Color::Cyan);
  Shape.setOutlineThickness(2);
  Shape.setOutlineColor(Color::Blue);
     

  Clock clock;
  float dt;

  if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
    Move::move_right();
  }

  if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
    Move::move_left();
  }


      // drawing and updating the values
      tableTile[3][3].setFillColor(Color::Cyan);
      window.clear();
      // draw 10x10 grid
      for (int x = 0; x < table_height; x++) {
        for (int y = 0; y < table_width; y++) {
          window.draw(tableTile[x][y]);
        }
      }
      window.draw(Shape);
      window.display();

      dt = clock.restart().asSeconds();

      // Left screen collision
      if (Shape.getPosition().x < 0) {
        Shape.setPosition(0, Shape.getPosition().y);
      }
      // Right screen collision
      if (Shape.getPosition().x + Shape.getGlobalBounds().width >
         
          WINDOW_WIDTH) {
        Shape.setPosition(WINDOW_WIDTH - Shape.getGlobalBounds().width,
                         
                          Shape.getPosition().y);
      }
      // Bottom screen collision
      if (Shape.getPosition().y + Shape.getGlobalBounds().height >
          WINDOW_HIGHT) {
        Shape.setPosition(WINDOW_HIGHT - Shape.getGlobalBounds().height,
                          Shape.getPosition().y);
      }
  return 0;
}