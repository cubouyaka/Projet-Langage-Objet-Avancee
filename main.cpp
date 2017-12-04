#include "Monster.hpp"
#include "Player.hpp"
#include "Warrior.hpp"
#include "Wizard.hpp"
#include "Floor.hpp"
#include <iostream>

using namespace std;


int main(){
  /*Potion pp(10,'P',"eau de vie");
  Floor f(10,10);
  Item p;
  for(int i = 0; i < 10 ; i++)
    for(int j = 0; j< 10; j++)
      f.setBoard(i,j,pp);
  f.setBoard(4,5,p);
  f.print();*/
  Wizard w(0,0);
  People p(10,1);
  Weapon fireBall(15,-1,5,'?',"FireBall");
  People t(12,45,'T',1000,2,4,4,fireBall);
  cout << GREEN << p.getSymbole() << endl;
  p = t;
  cout << GREEN << p.getSymbole() << endl;
  Weapon re;
  re = fireBall;
  cout<<WHITE <<re.getSymbole()<<YELLOW<<w.getWeapon().getSymbole()<<endl;
  p.setWeapon(re);
  cout<<BLUE<<p.getWeapon().getName()<<RESET;
  cout << p.getLife() << endl;
  w.attack(p);
  cout << p.getLife() << endl;
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
