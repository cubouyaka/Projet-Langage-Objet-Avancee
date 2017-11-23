#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLDRED "\033[1m\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"

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
