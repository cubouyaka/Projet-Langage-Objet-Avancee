#include "Monster.hpp"
#include "Player.hpp"
#include "Warrior.hpp"
#include "Wizard.hpp"
#include "Floor.hpp"
#include <iostream>

using namespace std;


int main(){
  Floor f(10,10);
  string name = "Ivan LE TERRILE";
  Player p1(&f, 3,7,name);
  f.setBoard(3,7,p1);
  Potion pp(10,'P',"eau de vie");
  f.setBoard(1,0,pp);
  f.print();
  Wizard w(0,0);
  People p(&f,10,1);
  Weapon fireBall(15,-1,5,'?',"FireBall");
  People t(&f,12,45,'T',1000,2,4,4,fireBall);
  cout << p.getLife() << endl;
  w.attack(p);
  cout << p.getLife() << endl;
  f.turn();

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
