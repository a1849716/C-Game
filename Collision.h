#ifndef COLLISION_H
#define COLLISION_H

class Collision{
  private:
    int WINDOW_HEIGHT;
    int WINDOW_WIDTH;
  public:
    Collision(int height, int width);
    void check_for_collision();
};
#endif
