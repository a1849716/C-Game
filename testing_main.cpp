#include <ctime>
#include <iostream>

#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

int main() {
  const int WINDOW_WIDTH = 600;
  const int WINDOW_HEIGHT = 1200;
  // Make window with size 600 x 1200 for play size, additional info will
  // require more space which will be added on later
  RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SCUFFED TETRIS",
                      Style::Close | Style::Titlebar);
  window.setFramerateLimit(60);
  float gridSize = 60.0;

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
  int rows = 20;
  int cols = 10;
  int frames = 0;
  float fps;
  sf::Clock clock;
  sf::Time elapsedTime;
  time_t beginT = time(NULL), endT = time(NULL);

  RectangleShape tableTile[rows][cols];
  // setting up grid
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      tableTile[i][j].setSize(Vector2f(60, 60));
      tableTile[i][j].setFillColor(Color::Black);
      tableTile[i][j].setOutlineThickness(1.f);
      tableTile[i][j].setOutlineColor(Color::White);
      tableTile[i][j].setPosition(j * 60, i * 60);
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
            if (array[i][j] == 1 && j + 1 < cols) {
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
            if (array[i][j] == 1 && array[i + 1][j] && j > 0) {
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
    }
      if (difftime(endT, beginT) < 1.0f) {
        endT = time(NULL);
      } else {
        beginT = time(NULL);
        endT = time(NULL);
        for (int i = 0; i < rows; i++) {
          for (int j = 0; j < cols; j++) {
            if (array[i][j] == 1 && array[i + 2][j] == 0 && i + 2 < rows) {
              array[i][j] = 0;
              array[i + 1][j] = 0;
              array[i + 1][j] = 1;
              array[i + 2][j] = 1;
              i = rows;
            }
          }
        }
      }
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
      window.clear();
      // draw 10x10 grid
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          window.draw(tableTile[i][j]);
        }
      }
      // drawing and updating the values
      window.display();
  }
  return 0;
}
