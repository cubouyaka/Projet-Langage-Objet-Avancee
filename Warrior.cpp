#include "Warrior.hpp"
#include <cstdlib>
#include <ctime>
Warrior::Warrior(int i, int j, int l, const double r,char c, const int s, int va,
		 const Weapon w, const Item it) : Monster(i,j,l,r,c,s,va,w,it){}

void Warrior::print() const { cout << RED << "I'm a Warrior " <<  symbole << RESET << endl;}


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

Cavalier::Cavalier(int i, int j, int l, const double r, const int s, int va,
		 const Weapon w, const Item it) : Warrior(i,j,l,r,'C',s,va,w,it){}

void Cavalier::print() const { cout << YELLOW<<  "I'm a cavalier -> " << RED << symbole << RESET << endl;}
void Cavalier::getposition() const {
  cout << YELLOW<< "your position is "<< i <<","<< j <<RESET <<endl;
}
