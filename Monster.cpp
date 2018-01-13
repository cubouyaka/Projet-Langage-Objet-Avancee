#include "Monster.hpp"

Monster::Monster(int i, int j, int l, const double r, char c, const int s, int va, Weapon w, const Item it, Floor* f) : People(f,i,j,c,l,r,s,va,w,it){}

const string Monster::getName() const{ return string("Monster"); }
void Monster::setFloor(Floor *f){ floor = f; }

void Monster::print() const { cout << RED << symbole << RESET; }

void Monster::turn(){
  int i = getI();
  int j = getJ();
  int n = getFloor()->getN();
  int m = getFloor()->getM();
  //check if player is around, if not move randomly
  if(0 <= i-1 && i-1 < n && 0 <= j && j < m &&
     getFloor()->getCase(i-1,j)->typeOf() == PLAYER)
    attack((People&)*getFloor()->getCase(i-1,j));
  else if(0 <= i+1 && i+1 < n && 0 <= j && j < m &&
	  getFloor()->getCase(i+1,j)->typeOf() == PLAYER)
    attack((People&)*getFloor()->getCase(i+1,j));
  else if(0 <= i && i < n && 0 <= j-1 && j-1 < m &&
	  getFloor()->getCase(i,j-1)->typeOf() == PLAYER)
    attack((People&)*getFloor()->getCase(i,j-1));
  else if(0 <= i && i < n && 0 <= j+1 && j+1 < m &&
	   getFloor()->getCase(i,j+1)->typeOf() == PLAYER)
    attack((People&)*getFloor()->getCase(i,j+1));
  else{
    cout << "MONSTER : Personne autour" << endl;
    move();
  }
}

void Monster::move(){
  //move randomly around
  int ii,jj;
  srand (time(NULL));
  do{
    ii = getI();
    jj = getJ();
    int random = (int)(rand() % 4);
    if(random == 0 && ii > 0)
      ii = ii-1;
    else if(random == 1 && j > 0)
      jj = jj-1;
    else if(random == 2 && ii+1 < getFloor()->getN())
      ii = ii+1;
    else if(random == 3 && jj+1 < getFloor()->getM())
      jj = jj+1;
  }while(floor->getCase(ii,jj)->typeOf() != EMPTY);

  floor->setBoard(ii,jj,*this);
  floor->setBoard(getI(),getJ());
  setI(ii);
  setJ(jj);

  setPlayed(true);
}

int Monster::typeOf() const{ return MONSTER; }
