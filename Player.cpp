#include "Player.hpp"

Player::Player(Floor* f, int i, int j, const string n, int l, const double r, 
	       const int s, int va, const Weapon w) : 
  People(f,i,j,'>',l,r,s,va,w), name(n){}

void Player::setSymbole(char s){ symbole = s; }
<<<<<<< HEAD

const char * Player::getName() const { return name; }

void Player::print() const {
	cout << "My name is "<<getName()<<"My symbole is "<<BOLDYELLOW << symbole << RESET<<endl; }
//methode pour regarder les elements du joueur
void Player::lookbag()const{
	for(int i(0); i<bag.size(); i++)
    	cout << bag[i].getName() << "| ";
	cout <<endl;
}
//methode pour ajouter des elements dans le sac on regardesi le sac n'est pas plein on ajoute sinon on doit supprimer un item
void Player::Add_item_bag( Item &item) const{
	if(bag.size()<MAX_ITEM){
		bag.push_back(item);
		//changer la positon de l'item
		item.SetI(i);
		item.SetJ(j);
	}
	else
		cout <<RED<<"Your bag is full remove a item if you want to add this item"<<RESET<<endl;
}
void Player::remove_item_bag( ){
	if(bag.size()<=0)
		cout <<"your bag is empty, you can't remove a item"<<endl;
	else{
		cout<<"choice the number of the item wich you want remove"<<endl;
		lookbag();
		int i=0;
		cin >>i ;
		while(i<0 ||i>=bag.size())
		{
			cout <<"Wrong number, this item does not exist in your bag "<<endl;
			cout <<"please put a valid number"<<endl;
			cin >>i ;
		}

		cout<<"you have choosen this item: "<<CYAN<<bag[i].getName()<<RESET<<" it will be remove in your bag"<<endl;
		//TODO supprime le dernier element au lieu de l'element selectionné
		bag.erase(bag.begin()+ i);

		lookbag();
	}
}
void Player::change_Weapon(){
	/*if(bag.size()<=0)
		cout <<"your bag is empty, you can't change your weapon"<<endl;
	else{
		cout<<"choice the number of weapon wich you want replace"<<endl;
		lookbag();
		int i=0;
		cin >>i ;
		while(i<0 ||i>=bag.size())
		{
			cout <<"Wrong number, this item does not exist in your bag "<<endl;
			cout <<"please put a valid number"<<endl;
			cin >>i ;
			if(bag[i])
		}

		cout<<"you have choosen this item: "<<CYAN<<bag[i].getName()<<RESET<<" it will be remove in your bag"<<endl;
*/
=======
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
  case 'o' :
  case 'l' :
  case 'm' :
  default:
    cout <<BOLDRED<< "Error move player, wrong command\n";
  }
>>>>>>> ccafb6b75eb7b2b1f4b4e3593b016536820f6408
}
