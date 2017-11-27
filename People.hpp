#ifndef PEOPLE_H
#define PEOPLE_H
#include "Weapon.hpp" 
#include "Potion.hpp"

#define MAX_LIFE 100
#define DEFAULT_WEAPON Weapon(5,-1,1,'?',"Hands",0)

class People : public Case {
protected:
  mutable int life;
  mutable double resi;
  const int size;
  mutable Weapon weapon;
  const Item item;

public :
  People(int l = MAX_LIFE, double r = 1, const int s = 1,
	 Weapon w = DEFAULT_WEAPON, const Item i = Item());

  const Weapon getWeapon() const;
  const Item getItem() const;

  bool attacked(const Weapon &w); //get dammage of the weapon w and return true ifthe people die.
  void drinkPotion(const HealingPotion &p);
  void drinkPotion(const Posion &p); //lunch die if needed 
  void drinkPotion(const ResiUpPotion &p);
  void drinkPotion(const ResiDownPotion &p);
  void die(); //destruct the people and drop object if needs
};

#endif
