#ifndef TETROMINO_H
#define TETROMINO_H

class Tetromino{
  private:
    int block1by1_tetrominto;
    int block2by1_tetromino;
    int block4by1_teromino;
    int block5by1_teromino;
    int block1by2_tetromino;
    int block1by3_tetromino;
    int block1by4_tetromino;
    int block1by5_tetromino;
    int block2by2_tetromino;
    int block3by3_tetromino;
    int block2by2L_tetromino;
    int blockback2by2L_tetromino;
    int block3by3L_tetromino;
    int blockback3by3L_tetromino;
  public:
    Tetromino();
    int generate_Block();
};




#endif