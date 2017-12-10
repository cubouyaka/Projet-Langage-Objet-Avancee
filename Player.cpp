#include "Player.hpp"

Player::Player(Floor* f, int i, int j, const string n, int l, const double r, 
	       const int s, int va, const Weapon w) : 
  People(f,i,j,'>',l,r,s,va,w), name(n){}

void Player::setSymbole(char s){ symbole = s; }
const string Player::getName() const { return name; }
void Player::print() const { cout << BOLDYELLOW << symbole << RESET; }

void Player::turn() {
  char c = 0;
  while(true){
    bool b = false;
    while(!b){
      cin >> c;
      if(c != 'o' && c != 'k' && c != 'l' && c != 'm' && c != 'h' && c != 'q')
	cout << RED << "Wrong command, try again : k(left), o(up), l(down), m(right), h(help)\n" << RESET;
      else 
	b = true;
    }
    if(c == 'h'){
      cout << "To move on the game, use the following commands :"<<endl;
      cout << "\'k\' - left " << endl;
      cout << "\'o\' - up " << endl;
      cout << "\'l\' - down " << endl;
      cout << "\'m\' - right " << endl;
      cout << "\'q\' - quit " << endl;
    }else if(c == 'q')
      return;
    else //a move
      move(c);
  }
}

void Player::move(char c){
  switch(c){
  case 'k' :
    if(i < floor->getN() && i >= 0){
      if(j < floor->getM() && j >= 0){
	cout << "TR" <<endl;
	floor->setBoard(i-1,j,*this);
	floor->setBoard(i,j);
	floor->print();
      }
    }
    /*case 'o' :
  case 'l' :
  case 'm' :*/
    // default:
    //    cout <<BOLDRED<< "Error move player, wrong command\n"<<RESET;
  }
}
