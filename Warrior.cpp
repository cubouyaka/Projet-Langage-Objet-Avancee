#include "Warrior.hpp"
#include <cstdlib>
#include <ctime>

//WARRIOR
Warrior::Warrior(int i, int j, int l, const double r,char c, const int s, int va,
		 const Weapon w, const Item it) : Monster(i,j,l,r,c,s,va,w,it){
  scope = SCOPE_WARRIOR;
}

void Warrior::print() const { 
  cout << RED <<  symbole << RESET;
}

void Warrior::turn(){
  move();
  setPlayed(true);
}

void Warrior::move(){
  int i = getI();
  int j = getJ();
  int n = getFloor()->getN();
  int m = getFloor()->getM();
  int x,y;

  for(int x = i-scope; x <= i+scope; x++)
    for(int y = j-(scope-abs(i-x)); y <= j+(scope-abs(i-x)); y++)
      if(0 <= x && x < n && 0 <= y && y < m)
	if(getFloor()->getCase(x,y)->typeOf() == PLAYER)
	  cout <<x<< ";"<<y<<endl;
}


//NINJA
Ninja::Ninja(int i, int j, int l, const double r, const int s, int va,
		 const Weapon w, const Item it) : Warrior(i,j,l,r,'N',s,va,w,it){}

void Ninja::print() const { cout << MAGENTA << "I'm a ninja x " << RED<<  symbole << RESET << endl;}
void Ninja::teleportation(){
  srand(time(NULL));
  int a=rand()%10;
  int b=rand()%10;
  i=a;
  j=b;
  //TODO..
}
void Ninja::getposition() const {
  cout << YELLOW<< "your position is "<< i <<","<< j <<RESET <<endl;
}

//CAVALIER
Cavalier::Cavalier(int i, int j, int l, const double r, const int s, int va,
		 const Weapon w, const Item it) : Warrior(i,j,l,r,'C',s,va,w,it){}

void Cavalier::print() const { cout << YELLOW<<  "I'm a cavalier -> " << RED << symbole << RESET << endl;}
void Cavalier::getposition() const {
  cout << YELLOW<< "your position is "<< i <<","<< j <<RESET <<endl;
}
