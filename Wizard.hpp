#ifndef WIZARD_H
#define WIZARD_H
#include "Monster.hpp"

class Wizard : public Monster {
public:
  Wizard(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1,char c='W',const int s = 1, int va = 3, Weapon w = SCEPTER,const Item it = Item());

  virtual void attack(People &p);
};

class Wizard2 : public Wizard {
public:
  Wizard2(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1.5,char c='W',const int s = 1, int va = 6, Weapon w = SCEPTER2,const Item it = Item());

  void attack(People &p);
  void print() const;  
};

#endif
