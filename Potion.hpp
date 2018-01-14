#ifndef POTION_H
#define POTION_H
#include "Item.hpp"
using namespace std;
#define DEFAULT_POTION 10

class Potion : public Item {
private:
  const int effect;

public:
  Potion(const int e = DEFAULT_POTION, const char s = 'P', 
	 const char * n = "Unknown Potion",Floor* f = NULL);

  const int getEffect() const;
  virtual void print() const;
  virtual int typeOf() const;
};

class HealingPotion : public Potion {
public:
  HealingPotion(const int e = DEFAULT_POTION);
  int typeOf() const;
};

class Posion : public Potion {
public:
  Posion(const int e = DEFAULT_POTION);
  void print() const;
  int typeOf() const;
};

class ResiUpPotion : public Potion {
public:
  ResiUpPotion(const int e = DEFAULT_POTION);
  int typeOf() const;
};

class ResiDownPotion : public Potion {
public:
  ResiDownPotion(const int e = DEFAULT_POTION);
  void print() const;
  int typeOf() const;
};

#endif
