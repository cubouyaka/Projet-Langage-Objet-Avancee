#include "Case.hpp"

Case::Case(char s, Floor *f, int i, int j) : symbole(s), floor(f), i(i), j(j) {}
Case::Case(const Case &c) : floor(c.getFloor()), symbole(c.getSymbole()),
			    i(c.getI()), j(c.getJ()) {}

Case& Case::operator=(const Case &c){
  i = c.getI();
  j = c.getJ();
  symbole = c.getSymbole();
  return *this;
}

Floor* Case::getFloor() const{ return floor; }
int Case::getI() const{ return i; }
int Case::getJ() const{ return j; }
char Case::getSymbole() const{ return symbole; }
bool Case::getPlayed() const { return true; }

void Case::turn() {}
void Case::print() const{ cout << symbole; }

Empty::Empty() : Case('.') {}
