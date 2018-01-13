#include "Monster.hpp"

Monster::Monster(int i, int j, int l, const double r, char c, const int s, int va, Weapon w, const Item it, Floor* f) : People(f,i,j,c,l,r,s,va,w,it){}

void Monster::print() const { cout << RED << symbole << RESET; }

void Monster::turn(){
  int i = getI();
  int j = getJ();
  //check if player is around, if not move randomly
  if(getFloor()->getCase(i-1,j)->typeOf() == PLAYER)
    attack((People)getFloor()->getCase(i-1,j));
  else if(getFloor()->getCase(i+1,j)->typeOf() == PLAYER)
    attack(*getFloor()->getCase(i+1,j));
  else if(getFloor()->getCase(i,j-1)->typeOf() == PLAYER)
    attack(*getFloor()->getCase(i,j-1));
  else if(getFloor()->getCase(i,j+1)->typeOf() == PLAYER)
    attack(*getFloor()->getCase(i,j+1));
  else{
    //move();
  }
}

void Monster::move(){
  /*
  //move randomly around
  srand (time(NULL));
  int random = (int)(rand() % 4);
  if(random == 0)
    //
   else if(random == 1)
   else if(random == 2)
   else // random == 3
  */
}
