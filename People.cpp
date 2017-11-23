#include "People.hpp"

People::People(int l, const int a, const double r, const int s, const Item i) : 
  Case('M'), life(l), attack(a), resi(r), size(s), item(i){ }

const Item People::getItem() const { return item; }
