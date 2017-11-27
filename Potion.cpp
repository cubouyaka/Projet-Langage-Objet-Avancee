#include "Potion.hpp"

Potion::Potion(const int e, const char s, const char* n):Item(s,n), effect(e){} 
const int Potion::getEffect() const { return effect; }

HealingPotion::HealingPotion(const int e) : Potion(e,'H',"Healing Potion"){}

Posion::Posion(const int e) : Potion(e,'h',"Posion Potion"){}

ResiUpPotion::ResiUpPotion(const int e) : Potion(e,'R',"Resistance+ Potion"){}

ResiDownPotion::ResiDownPotion(const int e):Potion(e,'r',"Resistance- Potion"){} 
