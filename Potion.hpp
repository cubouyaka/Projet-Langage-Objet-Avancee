#ifndef POTION_H
#define POTION_H
#include "Item.hpp"

#define DEFAULT_POTION 10

class Potion : public Item {
private:
  const int effect;
  
public:
  Potion(const int e = DEFAULT_POTION, const char s = 'P', 
	 const char * n = "Unknown Potion");

  const int getEffect() const;
  void print() const;
};

class HealingPotion : public Potion {
public:
  HealingPotion(const int e = DEFAULT_POTION);
};

class Posion : public Potion {
public:
  Posion(const int e = DEFAULT_POTION);
  void print() const;
};

class ResiUpPotion : public Potion {
public:
  ResiUpPotion(const int e = DEFAULT_POTION);
};

class ResiDownPotion : public Potion {
public:
  ResiDownPotion(const int e = DEFAULT_POTION);
  void print() const;
};

#endif
