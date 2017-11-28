#ifndef WEAPON_H
#define WEAPON_H
#include "Item.hpp"

#define DEFAULT_WEAPON_A 10
#define DEFAULT_WEAPON_D 10

class Weapon : public Item {
private:
  const int attack;
  const int scope;
  mutable int durability; //if -1 : indestructible 

public:
  //CONSTRUCTORS
  Weapon(const int a = DEFAULT_WEAPON_A, int d = DEFAULT_WEAPON_D,
	 const int sc = 1, const char s = 'W',
	 const char * n = "Unknown Weapon", const int p = 5);
  Weapon(const Weapon &w);

  //OPERATORS
  Weapon& operator=(const Weapon &w);

  //GETTERS
  const int getAttack() const;
  const int getScope() const;
  int getDurability() const;

  //SETTERS
  bool setDurability() const; //return true if the durability of the weapon is equal to zero, ie the weapon is over

  //METHODS
};
/*
class Hands : public Weapon {
public:
  Hands();
};
*/
#endif
