#ifndef GAME_H
#define GAME_H
#include "Monster.hpp"
#include "Warrior.hpp"

#include "Player.hpp"
#include "Warrior.hpp"
#include "Wizard.hpp"
#include "Game.hpp"
#include "Weapon.hpp"
#include "Item.hpp"
#include "Potion.hpp"
#include "Floor.hpp"
#include <string>
#include <fstream>

using namespace std;
class Game {
public:
  const int nb_floor;
  int i_current_floor;
  Floor ** floors;
  int nb_tours;

  Game(int nb_f = 1);
  virtual~Game();
  void setFloor(int n, Floor* f);
  Floor * getFloor(int n);
  void play();
};

#endif
