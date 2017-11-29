#ifndef ITEM_H
#define ITEM_H
#include "Case.hpp"

class Item : public Case {
private:
  const char * name;
  const int pods;

public:
  //CONSTRUCTOR
  Item(char s = '?', const char * n = "Unknown Item", int i = -1, int j = -1, 
       const int p = 1);
  Item(const Item &i);

  //OPERATORS
  Item& operator=(const Item &i);

  //GETTERS
  const char * getName() const;
  const int getPods() const;

};

#endif

