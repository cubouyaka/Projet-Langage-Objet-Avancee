#include "Player.hpp"

Player::Player(const char * n, int l, const double r, const int s, 
	       const Weapon w) : People('>',l,r,s,w), name(n){}

void Player::setSymbole(char s){ symbole = s; }
const char * Player::getName() const { return name; }
void Player::print() const { cout << BOLDYELLOW << symbole << RESET; }

