#include "Item.hpp"
#include <iostream>


int main(){
  Item c('C');
  Item d;
  Potion p;
  Potion pp(10);
  const Weapon w;
  std::cout << w.getDurability() << std::endl;
  while(w.setDurability())
    std::cout << w.getDurability() << std::endl;
  std::cout << d.getName() << std::endl;
}
