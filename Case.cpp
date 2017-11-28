#include "Case.hpp"

Case::Case(char s) : symbole(s) {}

Case& Case::operator=(const Case &c){
  symbole = c.getSymbole();
  return *this;
}

char Case::getSymbole() const{ return symbole; }
void Case::print() const{ cout << symbole; }

Empty::Empty() : Case('.') {}
