#include "Monster.hpp"
#include "Player.hpp"
#include "Warrior.hpp"
#include "Floor.hpp"
#include <iostream>

using namespace std;


int main(){
  Potion pp(10,'P',"eau de vie");
  Floor f(10,10);
  Item p;
  for(int i = 0; i < 10 ; i++)
    for(int j = 0; j< 10; j++)
      f.setBoard(i,j,pp);
  f.setBoard(4,5,p);
  f.print();
  /*  mo.setSymbole('^');
  mo.print();
  Warrior w;
  w.print();
  Ninja N;
  N.print();
  N.getposition();
  N.teleportation();
  N.getposition();
  Cavalier C;
  C.print();
  */
}
