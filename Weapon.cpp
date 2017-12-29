#include "Weapon.hpp"

Weapon::Weapon(const int a, int d, const int sc, const char s, const char * n,
	       const int p, Floor *f) : Item(f,s,n,p), attack(a), scope(sc),
					durability(d){}
Weapon::Weapon(const Weapon &w) : Item(w.getFloor(), w.getSymbole(),w.getName(),
				       w.getPods()),
				  attack(w.getAttack()), scope(w.getScope()),
				  durability(w.getDurability()) {}

Weapon& Weapon::operator=(const Weapon &w){
  Item(w.getFloor(),w.getSymbole(),w.getName(),w.getI(),w.getJ(),w.getPods());
	attack=w.getAttack();
	scope=w.getScope();
	durability=w.getDurability();
	setName(w.getName());
}

const int Weapon::getAttack() const{ return attack; }
const int Weapon::getScope() const{ return scope; }
int Weapon::getDurability() const { return durability; }
bool Weapon::setDurability() const { return ((--durability) == 0); }
