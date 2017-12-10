#include "Floor.hpp"

Floor::Floor(const int _n, const int _m) : n(_n), m(_m) { 
  board = new Case ** [n];
  for(int i = 0; i < n; i++){
    board[i] = new Case *[m];
    for(int j = 0; j < m; j++)
      board[i][j] = new Case(' ',this,i,j);
  }
}
Floor::Floor(const Floor &f) : n(f.getN()), m(f.getM()), board(f.getBoard()) {}

int Floor::getN() const { return n; }
int Floor::getM() const { return m; }
Case*** Floor::getBoard() const { return board; }
void Floor::setBoard(const int i, const int j) { 
  Empty c = Empty();
  if(0 <= i && i < n && 0 <= j && j < m)
    board[i][j] = &c; 
  //TODO else: out of bounds
}void Floor::setBoard(const int i, const int j, Case &c) { 
  if(0 <= i && i < n && 0 <= j && j < m)
    board[i][j] = &c; 
  //TODO else: out of bounds
}

void Floor::turn() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(!board[i][j]->getPlayed()){ //if it didn't moved already
	cout << "TTTTTTTTT\n";
	board[i][j]->turn();
      }
}

void Floor::print() const{
  cout << endl <<'+'<< setfill('-') << setw(n+1) << '+' << endl;
  for(int i = 0; i < n; i++){
    cout << '|';
    for(int j = 0; j < m; j++)
      board[i][j]->print();
    cout << '|' <<  endl;
  }
  cout <<'+'<< setfill('-') << setw(n+1) << '+' << endl;
}
  
