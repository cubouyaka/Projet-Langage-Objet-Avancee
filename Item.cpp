#include "Item.hpp"

/*<<<<<<< HEAD
Item::Item(char s, const char * n, const int p, int i, int j) : Case(s,i,j),
							       name(n),pods(p) {}
Item::Item(const Item &i) : Case(i.getSymbole(),i.getI(),i.getJ()),
			    name(i.getName()), pods(i.getPods()) {}
=======*/
Item::Item(Floor* f, char s, string n, int p, int i, int j) : 
  Case(s,f,i,j), name(n), pods(p) {}
Item::Item(const Item &i) : Case(i.getSymbole(),i.getFloor(), i.getI(),i.getJ()),
			    name(i.getName()), pods(i.getPods()) {} 
//>>>>>>> ccafb6b75eb7b2b1f4b4e3593b016536820f6408

Item& Item::operator=(const Item &i){
  setName(i.getName());
  pods = i.getPods();
}
/*<<<<<<< HEAD

const char * Item::getName() const{ return name; }
const int Item::getPods() const{ return pods; }
=======*/
				       
string Item::getName() const{ return name; }
int Item::getPods() const{ return pods; }
void Item::setPods(const int i){ pods = i; }
void Item::setName(const string c){ name = c; }
//>>>>>>> ccafb6b75eb7b2b1f4b4e3593b016536820f6408

void Item::print(){
  cout << 'T';
}
