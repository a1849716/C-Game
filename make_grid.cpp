#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
using namespace sf;

void make_grid(int rows, int cols, int gridSize) {
  RenderWindow window(VideoMode(800, 800), "TEST",
                      Style::Close | Style::Titlebar);
  // make the rectangle shape
  while (window.isOpen()) {
    RectangleShape tableTile[rows][cols];

    // nested for loops for setup
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        tableTile[i][j].setSize(Vector2f(gridSize, gridSize));
        tableTile[i][j].setFillColor(Color::Black);
        tableTile[i][j].setOutlineThickness(1.f);
        tableTile[i][j].setOutlineColor(Color::White);
        tableTile[i][j].setPosition(j * gridSize, i * gridSize);
      }
    }
    window.clear();
    // draw 10x10 grid
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        window.draw(tableTile[i][j]);
      }
    }
    window.display();
  }
}