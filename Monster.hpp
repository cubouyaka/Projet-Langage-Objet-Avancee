#ifndef MONSTER_H
#define MONSTER_H
#include "People.hpp"

//TODO END DEF ect..

class Monster : public People {
public:
  Monster(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1,char c='M',const int s = 1, int va = 3, Weapon w = DEFAULT_WEAPON,const Item it = Item());
  void print() const;
};

#endif
