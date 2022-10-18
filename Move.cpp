#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Move.h"

Move::Move(**array) {

    rows = 20;
    cols = 10;
    frames = 0;
 
    for (i = 0; i < 3; i++) {
        for (j = 0; j < cols; j++) {
             cout << array[i][j];
        }
            cout << endl;
        }
        cout << endl;
  

    while (window.isOpen()) {
        Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
                case Event::Closed:
                window.close();
                break;
            }
        
        move_right() {
            Shape.move(60.0f, 0.0f);
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    if (array[i][j] == 1 && array[i + 1][j] && j+1 < cols) {
                        array[i][j] = 0;
                        array[i + 1][j] = 0;
                        array[i][j + 1] = 1;
                        array[i + 1][j + 1] = 1;
                        i = rows;
                    }
                }
            } 
        }

        move_left() {
            Shape.move(-60.0f, 0.0f);
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    if (array[i][j] == 1 && array[i + 1][j] && j > 0) {
                        array[i][j] = 0;
                        array[i + 1][j] = 0;
                        array[i][j-1] = 1;
                        array[i + 1][j-1] = 1;
                        i = rows;
                        }
                    }
                }    
                
            }
        }
    }      
};