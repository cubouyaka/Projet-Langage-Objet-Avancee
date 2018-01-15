#include "Potion.hpp"


Potion::Potion(const int e, const char s, const char* n,Floor * f) : Item(f,s,n),
								     effect(e){}
const int Potion::getEffect() const { return effect; }
Potion::~Potion(){}
int Potion::typeOf() const{ return POTION; }

void Potion::print() const {
  //affichage du nom et le symbole de l'item
   cout<<BOLDBLUE << symbole << RESET; }

HealingPotion::HealingPotion(const int e) : Potion(e,'H',"Healing Potion"){}

Posion::Posion(const int e) : Potion(e,'h',"Posion Potion"){}

void Posion::print() const { cout << BLUE << symbole << RESET; }

ResiUpPotion::ResiUpPotion(const int e) : Potion(e,'R',"Resistance+ Potion"){}

ResiDownPotion::ResiDownPotion(const int e):Potion(e,'r',"Resistance- Potion"){}

void ResiDownPotion::print() const { cout <<BLUE << symbole << RESET; }

int Posion::typeOf() const{ return POSION; }
int HealingPotion::typeOf() const{ return HEALING; }
int ResiUpPotion::typeOf() const{ return RESI_UP; }
int ResiDownPotion::typeOf() const{ return RESI_DOWN; }
