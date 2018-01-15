#ifndef WARRIOR_H
#define WARRIOR_H
#include "Monster.hpp"

#define SCOPE_WARRIOR 3
#define SCOPE_WARRIOR2 5

#define SCOPE_NINJA 3
#define SCOPE_NINJA2 6

#define SCOPE_CAVA 2
#define SCOPE_CAVA2 3

#define SCOPE_MAGICIAN 3
#define SCOPE_MAGICIAN2 4

//Class Warrior
class Warrior : public Monster {
public:
  Warrior(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1,
	  char c = 'w',const int s = 1, int va = SCOPE_WARRIOR,
	  const Weapon w = SWORD, const Item it = Item());
  virtual~Warrior();
  void print() const;
  virtual void turn();
  virtual void move();
  virtual const string getName() const;
};
//Class Warrior II
class Warrior2 : public Warrior {
public:
  Warrior2(int i = -1, int j = -1, int l = MAX_LIFE2, const double r = 1,
	   char c = 'W',const int s = 1, int va = SCOPE_WARRIOR2,
	   const Weapon w = SWORD2, const Item it = Item());
  virtual~Warrior2();
  void print() const;
  const string getName() const;
};
//Class Ninja

class Ninja : public Warrior {
public:
  Ninja(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1.5,
	char c = 'n', const int s = 1, int va = SCOPE_NINJA,
	const Weapon w = SHURIKEN, const Item it = Item());
  virtual~Ninja();
  void teleportation() ;
  virtual const string getName() const;
};

//Class Ninja2
class Ninja2 : public Ninja {
public:
  Ninja2(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1.5,
	 char c = 'N', const int s = 1, int va = SCOPE_NINJA2, const Weapon w = SHURIKEN,
	 const Item it = Item());
   virtual~Ninja2();
  void print() const;
};

//Class Cavalier
class Cavalier : public Warrior{
public:
  Cavalier(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 1,
	     char c = 'c', const int s = 2, int va = SCOPE_CAVA,
	     const Weapon w = SWORD, const Item it = Item());
virtual~Cavalier();
void move();
};

//Class Cavalier2
class Cavalier2 : public Cavalier{
public:
  Cavalier2(int i = -1, int j = -1, int l = MAX_LIFE2, const double r = 2,
	     char c = 'C', const int s = 2, int va = SCOPE_CAVA2,
	     const Weapon w = SWORD2, const Item it = Item());
       virtual~Cavalier2();
void print() const;
};

//Class Magician
class Magician : public Warrior{
public:
  Magician(int i = -1, int j = -1, int l = MAX_LIFE, const double r = 2,
	     char c = 'm', const int s = 2, int va = SCOPE_MAGICIAN,
	     const Weapon w = SCEPTER, const Item it = Item());
  virtual~Magician();
};

//Class Magician2
class Magician2 : public Magician{
public:
  Magician2(int i = -1, int j = -1, int l = MAX_LIFE2, const double r = 2,
	      char c = 'M', const int s = 2, int va = SCOPE_MAGICIAN2,
	      const Weapon w = SCEPTER2, const Item it = Item());
  virtual~Magician2();
  void print() const;
};

#endif
