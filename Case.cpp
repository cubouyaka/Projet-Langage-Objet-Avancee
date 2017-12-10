#include "Case.hpp"

Case::Case(char s, int i, int j) : symbole(s), i(i), j(j) {}
Case::Case(const Case &c) : symbole(c.getSymbole()), i(c.getI()), j(c.getJ()) {}

Case& Case::operator=(const Case &c){
  i = c.getI();
  j = c.getJ();
  symbole = c.getSymbole();
  return *this;
}

int Case::getI() const{ return i; }
int Case::getJ() const{ return j; }
void Case::SetI(int _i){i=_i;}
void Case::SetJ(int _j){j=_j;}
char Case::getSymbole() const{ return symbole; }
void Case::print() const{ cout << symbole; }

Empty::Empty() : Case('.') {}
