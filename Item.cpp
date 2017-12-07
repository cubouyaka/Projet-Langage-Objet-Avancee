#include "Item.hpp"

Item::Item(char s, string n, int p, int i, int j) : Case(s,i,j),
							       name(n),pods(p) {}
Item::Item(const Item &i) : Case(i.getSymbole(),i.getI(),i.getJ()),
			    name(i.getName()), pods(i.getPods()) {} 

Item& Item::operator=(const Item &i){
  setName(i.getName());
  pods = i.getPods();
}
				       
string Item::getName() const{ return name; }
int Item::getPods() const{ return pods; }
void Item::setPods(const int i){ pods = i; }
void Item::setName(const string c){ name = c; }

void Item::print(){
  cout << 'T';
}
