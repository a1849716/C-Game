#include "Play_Area.h"

#include <iostream>
#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Tetromino.h"
using namespace sf;
using namespace std;

Play_Area::Play_Area() {
  gridSize = 10;
  game_status = false;
  filled_rows = 0;
  score = 0;
  for (int r = 0; r < gridSize; r++) {
    for (int c = 0; c < gridSize; c++) {
      *(isFilled[r][c]) = 0;
    }
  };

  //window variable
  RenderWindow window(VideoMode(gridSize, gridSize), "BLOCK PUZZLE",
                      Style::Close | Style::Titlebar);
  gridSizeU = static_cast<unsigned>(gridSize);
  RectangleShape tileSelector(Vector2f(gridSize, gridSize));
  
  // make table of grids
  RectangleShape tableTile[gridSize][gridSize];
  // setting up grid
  for (int x = 0; x < gridSize; x++) {
    for (int y = 0; y < gridSize; y++) {
      tableTile[x][y].setSize(Vector2f(gridSize, gridSize));
      tableTile[x][y].setFillColor(Color::Black);
      tableTile[x][y].setOutlineThickness(1.f);
      tableTile[x][y].setOutlineColor(Color::White);
      tableTile[x][y].setPosition(x * gridSize + 300, y * gridSize + 300);
      isFilled[x][y] = 0;
    }
  }
}

void Play_Area::update_mouse_positions() {
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
}

void Play_Area::make_game_area() {
  // Init Window
  const int WINDOW_WIDTH = 1200;
  const int WINDOW_HIGHT = 1200;
  // Make window with size 1200 x 1200
  RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "BLOCK PUZZLE",
                      Style::Close | Style::Titlebar);

  // setting the framerate to 60
  window.setFramerateLimit(60);


  // making the mouse highlight current grid
  
  tileSelector.setFillColor(Color::Transparent);
  tileSelector.setOutlineThickness(1.f);
  tileSelector.setOutlineColor(Color::Cyan);
      // update game elements
    tileSelector.setPosition(mousePosGrid.x * gridSize,
                             mousePosGrid.y * gridSize);
};

int Play_Area::set_status(bool gameStatus) { game_status = gameStatus; };
int Play_Area::get_status() {
  cout << game_status << endl;
  return game_status;
};
int Play_Area::check_rows() {
  // for loop from 1 - 10
  for (int r = 0; r < gridSize; r++) {
    // variable to check if add if there is block
    int filled = 0;
    // for loop from 1 - 10 for columns
    for (int c = 0; c < gridSize; c++) {
      // if block is filled
      if (isFilled[r][c] == 1) {
        // add 1 to filled
        filled++;
        // once filled becomes 10
        if (filled == 10) {
          // empty the row from 1 to 0
          for (int rc = 0; rc < 10; rc++) {
            // replace the row with 0
            isFilled = 0;
          }
        }
      }
    }
  }
};
bool Play_Area::check_game_status(){

};
Tetromino Play_Area::create_tetromino(){};
void Play_Area::update_mouse_positions() {
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
};

void Play_Area::draw_area(){
    // drawing and updating the values
  window.clear();
  //draw 10x10 grid
  for (int x = 0; x < gridSize; x++) {
    for (int y = 0; y < gridSize; y++) {
      window.draw(tableTile[x][y]);
    }
  }
  //draw tileselector
  window.draw(tileSelector);
  //display window
  window.display();
}