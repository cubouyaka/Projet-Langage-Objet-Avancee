#include "Item.hpp"

Item::Item(char s, const char * n,const int p) : Case(s),name(n),pods(p) {}
Item::Item(const Item &i) : Case(i.getSymbole()), name(i.getName()),
			    pods(i.getPods()) {} 

Item& Item::operator=(const Item &i){
  //TODO
}
				       
const char * Item::getName() const{ return name; }
const int Item::getPods() const{ return pods; }
