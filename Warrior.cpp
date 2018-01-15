#include "Warrior.hpp"
#include <cstdlib>
#include <ctime>

//WARRIOR
Warrior::Warrior(int i, int j, int l, const double r,char c, const int s, int va,
		 const Weapon w, const Item it) : Monster(i,j,l,r,c,s,va,w,it){}
Warrior::~Warrior(){}
void Warrior::print() const {
  cout << RED <<  symbole << RESET;
}

const string Warrior::getName() const{ return string("Warrior"); }
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

  for(int x = i-visual_area; x <= i+visual_area; x++){
    for(int y = j-(visual_area-abs(i-x)); y <= j+(visual_area-abs(i-x)); y++){
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

  if(xx <= i && yy < j){
    if(j-1 >= 0 && j-1 < m && (floor->getCase(i,j-1)->typeOf() == EMPTY
			       || floor->getCase(i,j-1)->typeOf() == PLAYER))
      jj = j-1;
    else if(i-1 >= 0 && i-1 < n && (floor->getCase(i-1,j)->typeOf() == EMPTY
				    ||floor->getCase(i-1,j)->typeOf() == PLAYER))
      ii = i-1;
    else
      return Monster::move();
  }else if(xx > i && yy <= j){
    if(i+1 >= 0 && i+1 < n && (floor->getCase(i+1,j)->typeOf() == EMPTY
			       || floor->getCase(i+1,j)->typeOf() == PLAYER))
      ii = i+1;
    else if(j+1 >= 0 && j+1 < m && (floor->getCase(i,j+1)->typeOf() == EMPTY
				    ||floor->getCase(i,j+1)->typeOf() == PLAYER))
      jj = j+1;
    else
      return Monster::move();
  }else if(xx < i && yy >= j){
    if(i-1 >= 0 && i-1 < n && (floor->getCase(i-1,j)->typeOf() == EMPTY
			       || floor->getCase(i-1,j)->typeOf() == PLAYER))
      ii = i-1;
    else if(j+1 >= 0 && j+1 < m && (floor->getCase(i,j+1)->typeOf() == EMPTY
				    ||floor->getCase(i,j+1)->typeOf() == PLAYER))
      jj = j+1;
    else
      return Monster::move();
  }else if(xx >= i && yy > j){
    if(j+1 >= 0 && j+1 < m && (floor->getCase(i,j+1)->typeOf() == EMPTY
			       || floor->getCase(i,j+1)->typeOf() == PLAYER))
      jj = j+1;
    else if(i+1 >= 0 && i+1 < n && (floor->getCase(i+1,j)->typeOf() == EMPTY
				    ||floor->getCase(i+1,j)->typeOf() == PLAYER))
      ii = i+1;
    else
      return Monster::move();
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
}

//WARRIOR2
Warrior2::Warrior2(int i, int j, int l, const double r,char c, const int s,
		   int va, const Weapon w, const Item it) :
  Warrior(i,j,l,r,c,s,va,w,it){}
Warrior2::~Warrior2(){}
void Warrior2::print() const {
  cout << BOLDRED <<  symbole << RESET;
}

const string Warrior2::getName() const{ return string("Warrior2"); }

//NINJA

Ninja::Ninja(int i, int j, int l, const double r,char c, const int s,
	     int va, const Weapon w, const Item it) : Warrior(i,j,l,r,c,s,va,w,it){}
Ninja::~Ninja(){}
const string Ninja::getName() const{ return string("Ninja"); }

void Ninja::teleportation(){
  srand(time(NULL));
  int a=rand()%10;
  int b=rand()%10;
  i=a;
  j=b;
  //TODO..
}

Ninja2::Ninja2(int i, int j, int l, const double r,char c, const int s, int va,
	       const Weapon w, const Item it) : Ninja(i,j,l,r,c,s,va,w,it){}
 Ninja2::~Ninja2(){}

void Ninja2::print() const { cout << BOLDRED << symbole << RESET << endl;}

//CAVALIER
Cavalier::Cavalier(int i, int j, int l, const double r, char c, const int s,
		   int va, const Weapon w, const Item it)
  : Warrior(i,j,l,r,c,s,va,w,it){}
Cavalier::~Cavalier(){}
void Cavalier::move(){
  int i = getI();
  int j = getJ();
  int n = getFloor()->getN();
  int m = getFloor()->getM();
  int xx,yy;
  int ii = i, jj = j;
  bool b = false;

  for(int x = i-visual_area; x <= i+visual_area; x++){
    for(int y = j-(visual_area-abs(i-x)); y <= j+(visual_area-abs(i-x)); y++){
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
    return;

  if(xx <= i && yy < j){
    if(j-1 >= 0 && j-1 < m && (floor->getCase(i,j-1)->typeOf() == EMPTY
			       || floor->getCase(i,j-1)->typeOf() == PLAYER))
      jj = j-1;
    else if(i-1 >= 0 && i-1 < n && (floor->getCase(i-1,j)->typeOf() == EMPTY
				    ||floor->getCase(i-1,j)->typeOf() == PLAYER))
      ii = i-1;
    else
      return;
	}else if(xx > i && yy <= j){
    if(i+1 >= 0 && i+1 < n && (floor->getCase(i+1,j)->typeOf() == EMPTY
			       || floor->getCase(i+1,j)->typeOf() == PLAYER))
      ii = i+1;
    else if(j+1 >= 0 && j+1 < m && (floor->getCase(i,j+1)->typeOf() == EMPTY
				    ||floor->getCase(i,j+1)->typeOf() == PLAYER))
      jj = j+1;
    else
      return;
  }else if(xx < i && yy >= j){
    if(i-1 >= 0 && i-1 < n && (floor->getCase(i-1,j)->typeOf() == EMPTY
			       || floor->getCase(i-1,j)->typeOf() == PLAYER))
      ii = i-1;
    else if(j+1 >= 0 && j+1 < m && (floor->getCase(i,j+1)->typeOf() == EMPTY
				    ||floor->getCase(i,j+1)->typeOf() == PLAYER))
      jj = j+1;
    else
      return;
  }else if(xx >= i && yy > j){
    if(j+1 >= 0 && j+1 < m && (floor->getCase(i,j+1)->typeOf() == EMPTY
			       || floor->getCase(i,j+1)->typeOf() == PLAYER))
      jj = j+1;
    else if(i+1 >= 0 && i+1 < n && (floor->getCase(i+1,j)->typeOf() == EMPTY
				    ||floor->getCase(i+1,j)->typeOf() == PLAYER))
      ii = i+1;
    else
      return;
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
}

//CAVALIER2
Cavalier2::Cavalier2(int i, int j, int l, const double r, char c, const int s,
		     int va, const Weapon w, const Item it)
  : Cavalier(i,j,l,r,c,s,va,w,it){}
	Cavalier2::~Cavalier2(){}

void Cavalier2::print() const { cout << BOLDRED << symbole << RESET << endl;}

//MAGICIAN
Magician::Magician(int i, int j, int l, const double r, char c, const int s,
		   int va, const Weapon w, const Item it) :
  Warrior(i,j,l,r,c,s,va,w,it){}
Magician::~Magician(){}
//MAGICIAN2
Magician2::Magician2(int i, int j, int l, const double r, char c, const int s,
		     int va, const Weapon w, const Item it) :
  Magician(i,j,l,r,c,s,va,w,it){}
Magician2::~Magician2(){}
void Magician2::print() const { cout <<BOLDRED << symbole << RESET << endl;}
