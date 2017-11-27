#include "People.hpp"

People::People(int l, double r, const int s, Weapon w, const Item i):
  Case('M'), life(l), resi(r), size(s), weapon(w) , item(i){ }

const Weapon People::getWeapon() const { return weapon; }
const Item People::getItem() const { return item; }

bool People::attacked(const Weapon &w){return life-=(w.getAttack()*resi) <= 0; }

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
