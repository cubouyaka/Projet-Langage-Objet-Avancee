#ifndef FLOOR_H
#define FLOOR_H
#include "Case.hpp"

class Floor {
protected:
  const int n;
  const int m;
  mutable Case** board;
  

public:
  //CONSTRUCTORS
  Floor(const int n = 10, const int m = 10);
  Floor(const Floor &f);

  //GETTERS
  int getN() const;
  int getM() const;
  Case** getBoard() const;
  void setBoard(const int i, const int j, Case &c);

  //METHODS
  void print() const;

};




#endif
