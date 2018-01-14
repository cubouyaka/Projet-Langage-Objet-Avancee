#ifndef GAME_H
#define GAME_H

#include "Floor.hpp"

class Game {
public:
  const int nb_floor;
  int i_current_floor;
  Floor ** floors;
  int nb_tours;

  Game(int nb_f = 1);

  void setFloor(int n, Floor* f);
  void play();

};
  
#endif
