#ifndef PEOPLE_H
#define PEOPLE_H
#include "Weapon.hpp"
#include "Potion.hpp"
#include <stdlib.h>

#define MAX_LIFE 10
#define MAX_LIFE2 30
#define MAX_LIFE_PLAYER 500
#define DEFAULT_WEAPON Weapon(5,-1,1,'?',"Hands",0)

class People : public Case {
protected:
  mutable int life;
  mutable double resi;
  const int size;
  mutable int visual_area;
  mutable Weapon weapon;
  const Item item;
  bool played; //if the people played this turn

public :
  //CONSTRUCTORS
  People(Floor * f = NULL, int i = -1, int j = -1, char s = '!',
	 int l = MAX_LIFE, double r = 1, const int S = 1, int va = 3,
	 Weapon w = DEFAULT_WEAPON, const Item it = Item());
  People(const People &p);
  virtual ~People();

  //OPERATORS
  People& operator=(const People &p);

  //GETTERS
  virtual const string getName() const;
  bool getPlayed() const;
  int getLife() const;
  double getResi() const;
  const int getSize() const;
  int getVArea() const;
  Weapon getWeapon() const;
  const Item getItem() const;

  //SETTERS
  void setWeapon(Weapon &w);
  void setPlayed(bool b);

  //METHODS
  bool attacked(const People &p);
  //get attacked by people p and return true if the people (this) die.
  virtual void attack(People &p); //attack the people p
  void drinkPotion(const HealingPotion &p);
  void drinkPotion(const Posion &p); //lunch die if needed
  void drinkPotion(const ResiUpPotion &p);
  void drinkPotion(const ResiDownPotion &p);
  virtual void die(); //destruct the people and drop object if needs
};

#endif
