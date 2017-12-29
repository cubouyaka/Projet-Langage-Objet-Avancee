#include "Potion.hpp"


Potion::Potion(const int e, const char s, const char* n,Floor * f) : Item(f,s,n),
								     effect(e){} 
const int Potion::getEffect() const { return effect; }

void Potion::print() const {
  //affichage du nom et le symbole de l'item
   cout<<"Potion name : "<<name <<" potion Symbole: " << BOLDBLUE << symbole << RESET<<endl; }

HealingPotion::HealingPotion(const int e) : Potion(e,'H',"Healing Potion"){}

Posion::Posion(const int e) : Potion(e,'h',"Posion Potion"){}

void Posion::print() const { cout << BLUE << symbole << RESET; }

ResiUpPotion::ResiUpPotion(const int e) : Potion(e,'R',"Resistance+ Potion"){}

ResiDownPotion::ResiDownPotion(const int e):Potion(e,'r',"Resistance- Potion"){}

void ResiDownPotion::print() const { cout << 'y'<<BLUE << symbole << RESET; }
