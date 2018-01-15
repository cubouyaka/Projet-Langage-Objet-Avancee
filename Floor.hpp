#ifndef FLOOR_H
#define FLOOR_H

#include "Case.hpp"

class Case;

class Floor {
  friend class Case;
protected:
  const int n;
  const int m;
  mutable Case*** board;


public:
  //CONSTRUCTORS
  Floor(const int n = 10, const int m = 10);
  Floor(const Floor &f);
  virtual~Floor();
  //GETTERS
  int getN() const;
  int getM() const;
  Case*** getBoard() const;
  Case * getCase(const int i, const int j) const;
  void setBoard(const int i, const int j);
  void setBoard(const int i, const int j,char c);
  void setBoard(const int i, const int j, Case &c);
  void endTurn();

  //METHODS
  void turn();
  void print() const;

};

#endif
