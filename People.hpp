#ifndef PEOPLE_H
#define PEOPLE_H
#include "Weapon.hpp" 
#include "Potion.hpp"

#define MAX_LIFE 500
#define MAX_LIFE_PLAYER 100
#define DEFAULT_WEAPON Weapon(5,-1,1,'?',"Hands",0)

class People : public Case {
protected:
  mutable int life;
  mutable double resi;
  const int size;
  mutable Weapon weapon;
  const Item item;

public :
  //CONSTRUCTORS
  People(char s = '!', int l = MAX_LIFE, double r = 1, const int S = 1,
	 Weapon w = DEFAULT_WEAPON, const Item i = Item());
  People(const People &p);

  //OPERATORS
  People& operator=(const People &p);

  //GETTERS
  int getLife() const;
  double getResi() const;
  const int getSize() const;
  const Weapon getWeapon() const;
  const Item getItem() const;

  //SETTERS
  void setWeapon(Weapon &w);

  //METHODS
  bool attacked(const People &p); 
  //get attacked by people p and return true if the people (this) die.
  void attack(People &p); //attack the people p with the weapon
  void drinkPotion(const HealingPotion &p);
  void drinkPotion(const Posion &p); //lunch die if needed 
  void drinkPotion(const ResiUpPotion &p);
  void drinkPotion(const ResiDownPotion &p);
  void die(); //destruct the people and drop object if needs
};

#endif
