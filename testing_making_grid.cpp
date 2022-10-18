#include <iostream>

#include "Play_Area.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

using namespace std;
using namespace sf;
extern void make_grid(int rows, int cols, int gridSize);

int main() {
  int rows, cols, gridSize;

  //rows = 10;
  //cols = 20;
  //gridSize = 60;
  cout << "Test 1" << endl;
  make_grid(10, 20, 60);
  //sucessful

  //rows = 20;
  //cols = 1;
  //gridSize = 80;
  cout << "Test 2" << endl;
  make_grid(20, 1, 80);
  //sucessful

  //rows = 0;
  //cols = -1;
  //gridSize = 1000;
  cout << "Test 2" << endl;
  make_grid(0, -1, 1000);
  //unsucessful
}