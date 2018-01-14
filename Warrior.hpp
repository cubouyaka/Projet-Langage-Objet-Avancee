#ifndef WARRIOR_H
#define WARRIOR_H
#include "Monster.hpp"

#define SCOPE_WARRIOR 3
#define SCOPE_WARRIOR2 5

#define SCOPE_NINJA 3

#define SCOPE_CAVA 2

//Class Warrior
class Warrior : public Monster {
public:
Warrior(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1,
	  char c = 'w',const int s = 1, int va = SCOPE_WARRIOR,
	  const Weapon w = SWORD, const Item it = Item());
void print() const;
virtual void turn();
virtual void move();
};
//Class Warrior II
class Warrior2 : public Warrior {
public:
Warrior2(int i = -1, int j = -1, int l = MAX_LIFE2, const double r = 1,
	   char c = 'W',const int s = 1, int va = SCOPE_WARRIOR2, 
	   const Weapon w = SWORD2, const Item it = Item());
void print() const;
};
//Class Ninja
class Ninja : public Warrior {
public:
Ninja(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1.5,
	const int s = 1, int va = SCOPE_NINJA, const Weapon w = SHURIKEN,
	const Item it = Item());
void print() const;
//fonction teleportation
void teleportation() ;
void getposition() const;
};

//Class Cavalier
class Cavalier : public Warrior{
public:
Cavalier(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1,
	   const int s = 2, int va = SCOPE_CAVA, const Weapon w = DEFAULT_WEAPON,
	   const Item it = Item());
void print() const;
void getposition() const;
};

#endif
