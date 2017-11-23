#include "People.hpp"

//TODO END DEF ect..

class Monster : public People {
public:
  Monster(int l = 100, const int a = 10, const double r = 1, const int s = 1,
	  const Item i = Item());
  void print() const;
};
