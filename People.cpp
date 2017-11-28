#include "People.hpp"

People::People(char s, int l, double r, const int S, Weapon w,const Item i)
  : Case(s), life(l), resi(r), size(S), weapon(w), item(i){ }
People::People(const People &p) : life(p.getLife()), resi(p.getResi()),
				  size(p.getSize()), weapon(p.getWeapon()),
				  item(p.getItem()) {}

People& People::operator=(const People &p){
  //TODO 
}

int People::getLife() const { return life; }
double People::getResi() const { return resi; }
const int People::getSize() const { return size; }
const Weapon People::getWeapon() const { return weapon; }
const Item People::getItem() const { return item; }
void People::setWeapon(Weapon &w) { weapon = w; }

bool People::attacked(const People &p){
  return (life-=(p.getWeapon().getAttack()*resi)) <= 0;
}

void People::attack(People &p){
  p.attacked(*this);
  if(weapon.setDurability()){ //if the weapon is over
    cout << BOLDMAGENTA << getWeapon().getName() << 
      " is over, now you're using your hands" << RESET << endl;
    Weapon w = DEFAULT_WEAPON;
    setWeapon(w);//replace it with DEFAULT_WEAPON (cf People.hpp)
  }
}

void People::drinkPotion(const HealingPotion  &p) {
  if(life + p.getEffect() > MAX_LIFE)
    life = MAX_LIFE;
  else
    life += p.getEffect();
}

void People::drinkPotion(const Posion  &p) {
  if(life - p.getEffect() <= 0)
    die();
  else
    life -= p.getEffect();
}

void People::drinkPotion(const ResiUpPotion  &p){ resi += (double)p.getEffect();}

void People::drinkPotion(const ResiDownPotion &p){resi -= (double)p.getEffect();}

void People::die() {
  //TODO
}
