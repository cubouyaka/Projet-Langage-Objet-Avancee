#include "Monster.hpp"
#include <iostream>

using namespace std;


int main(){
  Item c('C');
  Item d;
  Potion p;
  Potion pp(10);
  const Weapon w;
  const Monster m,n;
  Case cas;
  m.print();
  cas.print();
  cout << m.getItem().getSymbole() << endl;
  cout << w.getDurability() << endl;
  while(w.setDurability())
    cout << w.getDurability() << endl;
  cout << d.getName() << endl;
}
