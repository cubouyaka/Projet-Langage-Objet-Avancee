#include "Monster.hpp"

Monster::Monster(int i, int j, int l, const double r, char c, const int s, int va, const Weapon w, const Item it) : People(i,j,c,l,r,s,va,w,it){}

void Monster::print() const { cout << RED << symbole << RESET; }
