#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <iostream>

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
  
  Clock clock;
  float dt;
  int array[20][10] = {
      {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  };
  const int rows = 20;
  const int cols = 10;
  int frames = 0;

  const int table_height = 20;
  const int table_width = 10;
  RectangleShape tableTile[table_height][table_width];
  // setting up grid
  for (int x = 0; x < table_height; x++) {
    for (int y = 0; y < table_width; y++) {
      tableTile[x][y].setSize(Vector2f(60, 60));
      tableTile[x][y].setFillColor(Color::Transparent);
      tableTile[x][y].setOutlineThickness(1.f);
      tableTile[x][y].setOutlineColor(Color::White);
      tableTile[x][y].setPosition(x * 60, y * 60);
    }
  }

  // start of game loop
  while (window.isOpen()) {
    Event evnt;
    while (window.pollEvent(evnt)) {
      switch (evnt.type) {
      // if the close button is hit
      case Event::Closed:
        window.close();
        break;
      }
      
      // Key pressed actions
      // Right key
      if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
        for (int i = 0; i < rows; i++) {
          for (int j = 0; j < cols; j++) {
            if (array[i][j] == 1 && array[i + 1][j] == 1 && j + 1 < cols) {
              array[i][j] = 0;
              array[i + 1][j] = 0;
              array[i][j + 1] = 1;
              array[i + 1][j + 1] = 1;
              i = rows;
            }
          }
        }

        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < cols; j++) {
            cout << array[i][j];
          }
          cout << endl;
        }
        cout << endl;
      }

      // Left key
      if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
        for (int i = 0; i < rows; i++) {
          for (int j = 0; j < cols; j++) {
            if (array[i][j] == 1 && array[i + 1][j] == 1 && j > 0) {
              array[i][j] = 0;
              array[i + 1][j] = 0;
              array[i][j - 1] = 1;
              array[i + 1][j - 1] = 1;
              i = rows;
            }
          }
        }
        
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < cols; j++) {
            cout << array[i][j];
          }
          cout << endl;
        }
        cout << endl;
      }

      window.clear();
      // drawing and updating the values
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (array[i][j] == 1) {
            tableTile[i][j].setFillColor(Color::Cyan);
          } else {
            tableTile[i][j].setFillColor(Color::Transparent);
          }
        }
      }

      // draw grid
      for (int x = 0; x < table_height; x++) {
        for (int y = 0; y < table_width; y++) {
          window.draw(tableTile[x][y]);
        }
      }
      // drawing and updating the values
      window.display();

      dt = clock.restart().asSeconds();
    }
  }
  return 0;
}
