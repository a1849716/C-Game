//include libraries & headers
#include <iostream>
#include "Play_Area.h"
#include "Tetromino.h"
//include sfml
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
//namespace sf and std
using namespace sf;
using namespace std;

//
int main() {
  // Init Game
  float gridSize = 60.f;
  float dt = 0.f;
  Clock dtClock;
  int WINDOW_HIGHT = 1200;
  int WINDOW_WIDTH = 1200;
  
  // start of game loop
  while (window.isOpen()) {
    // updating dt
    dt = dtClock.restart().asSeconds();
    
    //create an Event called evnt  
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
    // Top screen collision
    if (Shape.getPosition().y + Shape.getGlobalBounds().height < WINDOW_HIGHT) {
      Shape.setPosition(WINDOW_HIGHT - Shape.getGlobalBounds().height,
                        Shape.getPosition().y);
    }
    
    // drawing and updating the values
    window.clear();
    //draw 10x10 grid
    for (int x = 0; x < tableSize; x++) {
      for (int y = 0; y < tableSize; y++) {
        window.draw(tableTile[x][y]);
      }
    }
    //draw tileselector
    window.draw(tileSelector);
    //display window
    window.display();
  }

  return 0;
}
// compiler code

// g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system
//or
// g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.5.1_2/include/ -o main -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system
