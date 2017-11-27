#include "Case.hpp"

class Item : public Case {
private:
  //const char symbole;
  const char * name;
  const int pods;

public:
  Item(const char s = '?', const char * n = "Unknown Item", const int p = 1);

  //const char getSymbole() const;
  const char * getName() const;
  const int getPods() const;

};


