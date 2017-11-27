#include "Item.hpp"

Item::Item(const char s, const char * n,const int p):Case(s),name(n),pods(p){}

const char * Item::getName() const{ return name; }
const int Item::getPods() const{ return pods; }
