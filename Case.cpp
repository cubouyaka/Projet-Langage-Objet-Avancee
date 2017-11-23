#include "Case.hpp"

Case::Case(const char s) : symbole(s) {}

const char Case::getSymbole() const{ return symbole; }
void Case::print() const{ cout << symbole; }

Empty::Empty() : Case('.') {}
