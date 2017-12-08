#ifndef CASE_H
#define CASE_H
#include <iostream>
#include <iomanip>

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
  Floor* getFloor() const;
  virtual bool getPlayed() const;

  //METHODS
  virtual void turn();
  virtual void print() const;

};

//An empty case (inside a room)
class Empty : public Case {
public:
  Empty();
};

#endif
