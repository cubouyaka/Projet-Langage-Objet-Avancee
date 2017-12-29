#ifndef ITEM_H
#define ITEM_H
#include "Case.hpp"

class Item : public Case {
  /*<<<<<<< HEAD
protected:
  const char * name;
  const int pods;

public:
  //CONSTRUCTOR
  Item(char s = '?', const char * n = "Unknown Item", int i = -1, int j = -1,
       const int p = 1);
=======*/
protected:
  mutable string name;
  mutable int pods;

public:
  //CONSTRUCTOR
  Item(Floor* f = NULL ,char s = '?', string n = "Unknown Item", 
       int i = -1, int j = -1, const int p = 1);
  //>>>>>>> ccafb6b75eb7b2b1f4b4e3593b016536820f6408
  Item(const Item &i);

  //OPERATORS
  Item& operator=(const Item &i);

  //GETTERS
  string getName() const;
  int getPods() const;

  //SETTER
  void setPods(const int i);
  void setName(string c);

  virtual void print();

};

#endif
