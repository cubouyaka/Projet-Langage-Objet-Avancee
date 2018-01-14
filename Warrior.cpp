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
  int xx,yy;
  int ii = i, jj = j;
  bool b = false;
  
  for(int x = i-scope; x <= i+scope; x++){
    for(int y = j-(scope-abs(i-x)); y <= j+(scope-abs(i-x)); y++){
      if(0 <= x && x < n && 0 <= y && y < m){
	if(getFloor()->getCase(x,y)->typeOf() == PLAYER){
	  b = true;
	  xx = x;
	  yy = y;
	}
      }
    }
  }

  if(!b)
    return Monster::move();

  do{
    if(xx <= i && yy < j){
      cout << "CAS 0" << endl;
      if(j-1 >= 0 && j-1 < m && floor->getCase(i,j-1)->typeOf() == EMPTY)
	jj = j-1;
      else if(i-1 >= 0 && i-1 < n && floor->getCase(i-1,j)->typeOf() == EMPTY)
	ii = i-1;
      else
	Monster::move();
    }else if(xx > i && yy <= j){
      cout << "CAS 1" << endl;
      if(i+1 >= 0 && i+1 < n && floor->getCase(i+1,j)->typeOf() == EMPTY)
	ii = i+1;
      else if(j+1 >= 0 && j+1 < m && floor->getCase(i,j+1)->typeOf() == EMPTY)
	jj = j+1;
      else
	Monster::move();
    }else if(xx < i && yy >= j){
      cout << "CAS 2" << endl;
      if(i-1 >= 0 && i-1 < n && floor->getCase(i-1,j)->typeOf() == EMPTY)
	ii = i-1;
      else if(j+1 >= 0 && j+1 < m && floor->getCase(i,j+1)->typeOf() == EMPTY)
	jj = j+1;
      else
	Monster::move();
    }else if(xx >= i && yy > j){
      cout << "CAS 3" << endl;
      if(j+1 >= 0 && j+1 < m && floor->getCase(i,j+1)->typeOf() == EMPTY)
	jj = j+1;
      else if(i+1 >= 0 && i+1 < n && floor->getCase(i+1,j)->typeOf() == EMPTY)
	ii = i+1;
      else
	Monster::move();
    }

    if(ii >= 0 && ii < n && jj >= 0 && jj < m){
      if(getFloor()->getCase(ii,jj)->typeOf() == PLAYER){
	attack((People&)*getFloor()->getCase(ii,jj));
	setPlayed(true);
	return;
      }
      else if(getFloor()->getCase(ii,jj)->typeOf() == EMPTY){
	floor->setBoard(ii,jj,*this);
	floor->setBoard(getI(),getJ());
	setI(ii);
	setJ(jj);
	setPlayed(true);
	return;
      }
    }
    cout << i << ";"<< j<<endl;
    cout << ii << ";"<< jj<<endl;
    sleep(2);
  }while(emptyAround(i,j));
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
