#ifndef WARRIOR_H
#define WARRIOR_H
#include "Monster.hpp"

//TODO END DEF ect..
//Class Warrior
class Warrior : public Monster {
public:
  Warrior(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1,
	  char c = 'W',const int s = 1, int va = 3, const Weapon w = DEFAULT_WEAPON,
	  const Item it = Item());
  void print() const;
};
//Class Ninja
class Ninja : public Warrior {
public:
  Ninja(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1.5,
	  const int s = 1, int va = 3, const Weapon w = DEFAULT_WEAPON,
	  const Item it = Item());
  void print() const;
  //fonction teleportation
  void teleportation() ;
  void getposition() const;
};

//Class Cavalier
class Cavalier : public Warrior{
public:
  Cavalier(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1,
	  const int s = 2, int va = 3, const Weapon w = DEFAULT_WEAPON,
	  const Item it = Item());
  void print() const;
  void getposition() const;
};

#endif
