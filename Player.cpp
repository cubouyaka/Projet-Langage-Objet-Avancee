#include "Player.hpp"

Player::Player(int i, int j, const char * n, int l, const double r, const int s,
	       int va, const Weapon w) : People(i,j,'>',l,r,s,va,w), name(n){}

void Player::setSymbole(char s){ symbole = s; }
const char * Player::getName() const { return name; }
void Player::print() const { cout << BOLDYELLOW << symbole << RESET<<endl; }
