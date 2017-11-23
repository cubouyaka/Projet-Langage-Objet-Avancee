#include "Monster.hpp"

Monster::Monster(int l, const int a, const double r, const int s, const Item i) :
  People(l,a,r,s,i){ }

void Monster::print() const { cout << RED << symbole << RESET; }
