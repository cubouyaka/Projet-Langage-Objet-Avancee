#ifndef CASE_H
#define CASE_H
#include <iostream>

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

class Case {
protected:
  const char symbole;

public:
  Case(const char s = ' ');

  const char getSymbole() const;
  void print() const;

};

//An empty case (inside a room)
class Empty : public Case {
public:
  Empty();
};

#endif
