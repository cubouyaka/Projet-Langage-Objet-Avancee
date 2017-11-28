#ifndef PLAYER_H
#define PLAYER_H
#include "People.hpp"
#include <vector>

//TODO END DEF ect..

class Player : public People {
private: 
  const char * name;
  mutable std::vector<Item> bag;
public:
  Player(const char* n = "?", int l = MAX_LIFE_PLAYER, const double r = 1,
	 const int s = 1, const Weapon w = DEFAULT_WEAPON);

  void setSymbole(char s);
  const char * getName() const;
  void print() const;
};

#endif
