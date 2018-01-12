#include "Monster.hpp"

Monster::Monster(int i, int j, int l, const double r, char c, const int s, int va, Weapon w, const Item it, Floor* f) : People(f,i,j,c,l,r,s,va,w,it){}

const string Monster::getName() const{ return string("Monster"); }
void Monster::setFloor(Floor *f){ floor = f; }

void Monster::print() const { cout << RED << symbole << RESET; }
int Monster::typeOf() const{ return MONSTER; }
