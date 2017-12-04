#include "People.hpp"

People::People(int i, int j, char s, int l, double r, const int S, int va,
	       Weapon w,const Item it) : Case(s,i,j), life(l), resi(r), size(S), 
					 visual_area(va), weapon(w), item(it){ }
People::People(const People &p) : Case(p.getI(), p.getJ(), p.getSymbole()), 
				  life(p.getLife()), resi(p.getResi()),
				  size(p.getSize()), visual_area(p.getVArea()),
				  weapon(p.getWeapon()),item(p.getItem()) {}

People& People::operator=(const People &p){
  life = p.getLife();
  resi = p.getResi();
  visual_area = p.getVArea();
  weapon = p.getWeapon();
  cout << "REREé"<<endl;
}

int People::getLife() const { return life; }
double People::getResi() const { return resi; }
const int People::getSize() const { return size; }
int People::getVArea() const { return visual_area; }
Weapon People::getWeapon() const { return weapon; }
const Item People::getItem() const { return item; }
void People::setWeapon(Weapon &w) { weapon = w;cout<<RED<<weapon.getName()<<RESET; }

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
