#include "Monster.hpp"
#include "Player.hpp"
#include "Warrior.hpp"
#include <iostream>

using namespace std;


int main(){
/*  Item c('C');
  Item d;
  Potion p;
  Potion pp(10);
  Player mo(0,0,"Brutus");
  mo.setSymbole('^');
  mo.print();
  const Weapon w;
  const Monster m,n;
  Case cas;
  m.print();
  p.print();
  cout << w.getDurability() << endl;
  while(w.setDurability())
    cout << w.getDurability() << endl;
  cout << d.getName() << endl;*/
  Item i('C',"potion",2,3,2);
    Item d;
    //
    Potion pp(10,'P',"eau de vie");
    Player mo(0,0,"Brutus");
    mo.setSymbole('^');
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

}
