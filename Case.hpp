#ifndef CASE_H
#define CASE_H
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <cmath>

#include "Floor.hpp"

#define RED "\033[31m"
#define BOLDRED "\033[1m\033[31m"
#define BLUE "\033[34m"
#define BOLDBLUE "\033[1m\033[34m"
#define GREEN "\033[32m"
#define BOLDGREEN "\033[1m\033[32m"
#define YELLOW "\033[33m"
#define BOLDYELLOW "\033[1m\033[33m"
#define MAGENTA "\033[35m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define CYAN "\033[36m"
#define BOLDCYAN "\033[1m\033[36m"
#define WHITE "\033[37m"
#define BOLDWHITE "\033[1m\033[37m"
#define RESET "\033[0m"

#define WALL 0
#define EMPTY 1
#define MONSTER 2
#define ITEM 3
#define PLAYER 4
#define PNJ 5
#define WEAPON 6
#define POTION 7
#define POSION 17
#define RESI_UP 27
#define RESI_DOWN 37
#define HEALING 47


using namespace std;

class Floor;

class Case {
protected:
  mutable char symbole;
  mutable int i;
  mutable int j;
  Floor * floor;

public:
  //CONSTRUCTORS
  Case(char s = ' ', Floor * f = NULL, int i = -1, int j = -1);
  Case(const Case &c);

  //OPERATORS
  Case& operator=(const Case &c);

  //GETTERS
  char getSymbole() const;
  int getI() const;
  int getJ() const;
  //SETTERS
  void setI(int _i);
  void setJ(int _j);
  Floor* getFloor() const;
  virtual bool getPlayed() const;
  virtual void setPlayed(bool b);

  //METHODS
  virtual void turn();
  virtual void print() const;
  //  virtual void interact(Player * p);
  virtual int typeOf() const;

};

//An empty case (inside a room)
class Empty : public Case {
public:
  Empty(Floor *f = NULL, int i = -1, int j = -1);
};

#endif
