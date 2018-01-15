#include "Case.hpp"

Case::Case(char s, Floor *f, int i, int j) : symbole(s), floor(f), i(i), j(j) {}
Case::Case(const Case &c) : floor(c.getFloor()), symbole(c.getSymbole()),
			    i(c.getI()), j(c.getJ()) {}
Case::~Case(){}
Case& Case::operator=(const Case &c){
  i = c.getI();
  j = c.getJ();
  symbole = c.getSymbole();
  return *this;
}

Floor* Case::getFloor() const{ return floor; }
int Case::getI() const{ return i; }
int Case::getJ() const{ return j; }
void Case::setI(int _i){i=_i;}
void Case::setJ(int _j){j=_j;}
char Case::getSymbole() const{ return symbole; }
bool Case::getPlayed() const { return true; }
void Case::setPlayed(bool b){}

void Case::turn() {}
void Case::print() const{ cout << symbole; }
//void Case::interact(Player & p){ cout << p.getName() << endl; }
int Case::typeOf() const{ return EMPTY; }
void Case::setFloor(Floor * f){ floor = f; }


Empty::Empty(Floor * floor, int i, int j) : Case('.',floor,i,j) {}
Empty::~Empty(){}

Wall::~Wall(){};

Space::Space(Floor * floor, int i, int j) : Case(' ',floor,i,j) {}
int Space::typeOf() const{ return SPACE; }

Wall::Wall(Floor * floor, int i, int j) : Case('#',floor,i,j) {}
int Wall::typeOf() const{ return WALL; }

StairsUp::StairsUp(Floor * floor, int i, int j) : Case('U',floor,i,j) {}
int StairsUp::typeOf() const{ return STAIRS_UP; }
void StairsUp::print() const{ cout << BOLDYELLOW << symbole << RESET;}

StairsDown::StairsDown(Floor * floor, int i, int j) : Case('D',floor,i,j) {}
int StairsDown::typeOf() const{ return STAIRS_DOWN; }
void StairsDown::print() const{ cout << BOLDYELLOW << symbole << RESET;}

Source::Source(Floor * floor, int i, int j) : Case('X',floor,i,j){}
Source::~Source(){}
int Source::typeOf() const{ return SOURCE; }
void Source::print() const{cout << BOLDGREEN << symbole << RESET; }
