#include "Monster.hpp"
#include "Player.hpp"
#include <iostream>

using namespace std;


int main(){
  Item c('C');
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
  cout << d.getName() << endl;
}
