#include "Player.hpp"

Player::Player(Floor* f, int i, int j, const string n, int l, const double r, 
	       const int s, int va, const Weapon w) : 
  People(f,i,j,'>',l,r,s,va,w), name(n){}

void Player::setSymbole(char s){ symbole = s; }

void Player::print() const {
  cout << BOLDYELLOW << getSymbole() << RESET;
}
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
    item.setI(i);
    item.setJ(j);
  }
  else
    cout <<RED<<"Your bag is full remove an item if you want to add it"<<RESET<<endl;
}
void Player::remove_item_bag( ){
  if(bag.size()<=0)
    cout <<"your bag is empty, you can't remove an item"<<endl;
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

/*void Player::change_Weapon(){
  if(bag.size()<=0)
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
const string Player::getName() const { return name; }
  
void Player::turn() {
  char c = 0;
  bool b = false;
  while(!b){
    system("stty raw");
    c = getchar();
    system("stty cooked");
    cout << endl;
    if(c != 'o' && c != 'k' && c != 'l' && c != 'm' && c != 'h' && c != 'q')
      cout << RED << "Wrong command, try again : k(left), o(up), l(down), m(right), h(help), q(quit)\n" << RESET;
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
    exit(0);
  else //a move
    move(c);
}

void Player::move(char c){
  if(c == 'k'){
    if(j > 0){ //not out of bounds
      if(interact(*floor->getCase(i,j-1))){
	floor->setBoard(i,j-1,*this);
	setSymbole('<');
	floor->setBoard(i,j);
	setJ(j-1);
      }
    }
  }else if( c == 'o'){
    if(i > 0){
      floor->setBoard(i-1,j,*this);
      setSymbole('^');
      floor->setBoard(i,j);
      setI(i-1);
    }
  }else if( c == 'l'){
    if(i < floor->getN()-1){
      floor->setBoard(i+1,j,*this);
      setSymbole('v');
      floor->setBoard(i,j);
      setI(i+1);
    }
  }else if(c == 'm'){
    if(j < floor->getM()-1){
      floor->setBoard(i,j+1,*this);
      setSymbole('>');
      floor->setBoard(i,j);
      setJ(j+1);
    }
  }
  setPlayed(true);
}

bool Player::interact(Case & c){
  if(c.typeOf() == EMPTY)
    return true;
  else if(c.typeOf() == ITEM){
    askUseOrStore((Item&)c);
    return true;
  }else if(c.typeOf() == MONSTER){
    attack((People&)c);
    return false;
  }
}

void Player::askUseOrStore(Item &item){
  char answer = 0;
  bool b = true;
  char c;
  cout << "Do you want to use(u) " << item.getName() << 
    " or store(s) it in your bag ?" << endl;
  while(b){
    system("stty raw");
    c = getchar();
    system("stty cooked");
    cout << endl;
    if(c != 'u' && c != 's')
      cout << RED << "Wrong answer. Press u to use " << item.getName()
	   <<" or s to store it" << RESET << endl;
    else
      b = false; 
  }
  if(c == 'u'){
    //TODO
  }
}

int Player::typeOf() const{ return PLAYER; }
