#include "Monster.hpp"

Monster::Monster(int l, const double r, const int s, 
		 const Weapon w, const Item i) : People(l,r,s,w,i){ }

void Monster::print() const { cout << RED << symbole << RESET; }
