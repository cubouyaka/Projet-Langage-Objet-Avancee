#include "Wizard.hpp"

Wizard::Wizard(int i, int j, int l, const double r, char c, const int s, int va, Weapon w, const Item it) : Monster(i,j,c,l,r,s,va,w,it){}
Wizard::~Wizard(){}
void Wizard::attack(People &p){
  Weapon fireBall = FIREBALL;
  Weapon w = getWeapon();
  if(abs(getI()-p.getI())>w.getScope() || abs(getJ()-p.getJ())>w.getScope())
    setWeapon(fireBall); //attack with fireball
  p.attacked(*this);
  if(weapon.setDurability()){ //if the weapon is over
    cout << BOLDMAGENTA << getWeapon().getName() <<
      " is over, now you're using your hands" << RESET << endl;
    w = DEFAULT_WEAPON; //replace it with DEFAULT_WEAPON (cf People.hpp)
  }
  setWeapon(w);
}
Wizard2::Wizard2(int i, int j, int l, const double r, char c, const int s, int va, const Weapon w, const Item it) :
  Wizard(i,j,c,l,r,s,va,w,it){}
  Wizard2::~Wizard2(){}

void Wizard2::attack(People &p){
  Weapon fireBall = FIREBALL2;
  Weapon w = getWeapon();
  if((getI()-p.getI()) > getWeapon().getScope() || (getJ()-p.getJ()) > 1)
    setWeapon(fireBall); //attack with fireball
  p.attacked(*this);
  if(weapon.setDurability()){ //if the weapon is over
    cout << BOLDMAGENTA << getWeapon().getName() <<
      " is over, now you're using your hands" << RESET << endl;
    w = DEFAULT_WEAPON; //replace it with DEFAULT_WEAPON (cf People.hpp)
  }
  setWeapon(w);
}
void Wizard2::print() const{ cout << BOLDRED << symbole << RESET; }
