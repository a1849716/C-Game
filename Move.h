#include <iostream>
#ifndef MOVE_H
#define MOVE_H

class Move {

    private:
        int array;
        int rows;
        int cols;
        int frames;
        int i;
        int j;
    public: 
        move(**array);
        move_left();
        move_right();
        move_down();
};

#endif;
