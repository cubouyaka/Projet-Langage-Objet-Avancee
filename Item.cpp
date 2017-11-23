#include "Item.hpp"

Item::Item(const char s, const char * n,const int p):Case(s),name(n),pods(p){}

//const char Item::getSymbole() const{ return symbole; }
const char * Item::getName() const{ return name; }
const int Item::getPods() const{ return pods; }


Potion::Potion(const int e, const char s, const char* n):Item(s,n), effect(e){} 
const int Potion::getEffect() const { return effect; }


Weapon::Weapon(const int a, int d, const int sc, const char s, const char * n,
	       const int p) : Item(s,n,p), attack(a), scope(sc), durability(d){}
const int Weapon::getAttack() const{ return attack; }
const int Weapon::getScope() const{ return scope; }
int Weapon::getDurability() const { return durability; }
bool Weapon::setDurability() const { return ((--durability) != 0); }
