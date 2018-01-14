#ifndef MONSTER_H
#define MONSTER_H
#include "People.hpp"

#define SCOPE_WARRIOR 3
#define SCOPE_WARRIOR2 5

class Monster : public People {
public:
Monster(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1,
	  char c='M',const int s = 1, int va = 3, Weapon w = DEFAULT_WEAPON,
	  const Item it = Item(), Floor* f = NULL );
  
const string getName() const;
void setFloor(Floor *f);
  
void print() const;
virtual void turn();
int typeOf() const;
virtual void move();
};

#endif
