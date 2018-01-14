#ifndef MONSTER_H
#define MONSTER_H
#include "People.hpp"

class Monster : public People {
public:
Monster(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1,
	  char c='m',const int s = 1, int va = 3, Weapon w = DEFAULT_WEAPON,
	  const Item it = Item(), Floor* f = NULL );
  
const string getName() const;
void setFloor(Floor *f);
  

bool emptyAround(int i, int j) const;
void print() const;
virtual void turn();
int typeOf() const;
virtual void move();
};

class Monster2 : public Monster{
public:
Monster2(int i = -1, int j = -1, int l = MAX_LIFE2, const double r = 1,
	  char c='M',const int s = 1, int va = 3, Weapon w = DEFAULT_WEAPON2,
	  const Item it = Item(), Floor* f = NULL );

  void print() const;
};

#endif
