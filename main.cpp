#include <iostream>

#include "SFML/Graphics.hpp"
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
        Shape.move(60.0f, 0.0f);
      }
      // Left key
      if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
        Shape.move(-60.0f, 0.0f);
      }
      // Down key
      if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
        Shape.rotate(90);
      }
      // Up key
      if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
        Shape.rotate(-90);
      }
      // Enter key
      if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
        Shape.setPosition(Shape.getPosition().x, WINDOW_HIGHT - Shape.getGlobalBounds().height);
      }
      

      // drawing and updating the values
      window.clear();
      window.draw(Shape);
      window.display();

      dt = clock.restart().asSeconds();

      // Left screen collision
      if (Shape.getPosition().x < 0) {
        Shape.setPosition(0, Shape.getPosition().y);
      }
      // Right screen collision
      if (Shape.getPosition().x + Shape.getGlobalBounds().width > WINDOW_WIDTH) {
        Shape.setPosition(WINDOW_WIDTH - Shape.getGlobalBounds().width, Shape.getPosition().y);
      }
      // Bottom screen collision
      if (Shape.getPosition().y + Shape.getGlobalBounds().height > WINDOW_HIGHT) {
        Shape.setPosition(WINDOW_HIGHT - Shape.getGlobalBounds().height, Shape.getPosition().y);
      }
    }
  }

  return 0;
}
// compiler code
// g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_1/include/ -o main
// -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window
// -lsfml-system