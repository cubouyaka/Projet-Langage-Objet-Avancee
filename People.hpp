#include "Item.hpp" 

class People : public Case {
protected:
  mutable int life;
  const int attack;
  const double resi;
  const int size;
  const Item item;

public :
  People(int l = 100, const int a = 10, const double r = 1, const int s = 1,
	  const Item i = Item());

  const Item getItem() const;
};
