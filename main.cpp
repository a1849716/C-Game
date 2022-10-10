#include <iostream>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

using namespace sf;
using namespace std;

int main() {
  // Init Game
  float gridSize = 60.f;
  unsigned gridSizeU = static_cast<unsigned>(gridSize);
  float dt = 0.f;
  Clock dtClock;
  Vector2i mousePosScreen;
  Vector2i mousePosWindow;
  Vector2f mousePosView;
  Vector2u mousePosGrid;

  // Init Window
  const int WINDOW_WIDTH = 1200;
  const int WINDOW_HIGHT = 1200;
  // Make window with size 1200 x 1200
  RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "BLOCK PUZZLE",
                      Style::Close | Style::Titlebar);

  // setting the framerate to 60
  window.setFramerateLimit(60);

  // make shape for testing
  RectangleShape Shape(Vector2f(gridSize - 2, (gridSize * 2) - 2));
  Shape.setFillColor(Color::Cyan);
  Shape.setOutlineThickness(2);
  Shape.setOutlineColor(Color::Blue);
  Shape.setPosition(600.f, 600.f);

  // make table of grids
  const int tableSize = 10;
  RectangleShape tableTile[tableSize][tableSize];

  for (int x = 0; x < tableSize; x++) {
    for (int y = 0; y < tableSize; y++) {
      tableTile[x][y].setSize(Vector2f(gridSize, gridSize));
      tableTile[x][y].setFillColor(Color::Black);
      tableTile[x][y].setOutlineThickness(1.f);
      tableTile[x][y].setOutlineColor(Color::White);
      tableTile[x][y].setPosition(x * gridSize + 300, y * gridSize + 300);
    }
  }
  RectangleShape tileSelector(Vector2f(gridSize, gridSize));
  tileSelector.setFillColor(Color::Transparent);
  tileSelector.setOutlineThickness(1.f);
  tileSelector.setOutlineColor(Color::Cyan);

  // start of game loop
  while (window.isOpen()) {
    // updating dt
    dt = dtClock.restart().asSeconds();
    // update mouse positions
    mousePosScreen = Mouse::getPosition();
    mousePosWindow = Mouse::getPosition(window);
    mousePosView = window.mapPixelToCoords(mousePosWindow);
    if (mousePosView.x >= 0.f) {
      mousePosGrid.x = mousePosView.x / gridSizeU;
    }
    if (mousePosView.y >= 0.f) {
      mousePosGrid.y = mousePosView.y / gridSizeU;
    }
    // update game elements
    tileSelector.setPosition(mousePosGrid.x * gridSize,
                             mousePosGrid.y * gridSize);

    Event evnt;
    while (window.pollEvent(evnt)) {
      // if the close button is hit
      if (evnt.type == Event::Closed) window.close();
    }

    // Left screen collision
    if (Shape.getPosition().x < 0) {
      Shape.setPosition(0, Shape.getPosition().y);
    }
    // Right screen collision
    if (Shape.getPosition().x + Shape.getGlobalBounds().width > WINDOW_WIDTH) {
      Shape.setPosition(WINDOW_WIDTH - Shape.getGlobalBounds().width,
                        Shape.getPosition().y);
    }
    // Bottom screen collision
    if (Shape.getPosition().y + Shape.getGlobalBounds().height > WINDOW_HIGHT) {
      Shape.setPosition(WINDOW_HIGHT - Shape.getGlobalBounds().height,
                        Shape.getPosition().y);
    }

    // drawing and updating the values
    window.clear();

    window.draw(Shape);

    for (int x = 0; x < tableSize; x++) {
      for (int y = 0; y < tableSize; y++) {
        window.draw(tableTile[x][y]);
      }
    }
    window.draw(tileSelector);

    window.display();
  }

  return 0;
}
// compiler code
// g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_1/include/ -o main
// -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window
// -lsfml-system