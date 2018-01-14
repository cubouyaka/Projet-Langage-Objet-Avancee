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
  if(bag.size()<=0)
    cout <<BOLDCYAN<<"your bag is empty"<<RESET<<endl;
  else {
    cout <<BOLDCYAN<<"your bag contains : "<<RESET<<endl;
    for(int i(0); i<bag.size(); i++)
      cout <<BOLDCYAN<< bag[i].getName() << " | ";
    cout<<RESET <<endl;
  }
}
//methode pour ajouter des elements dans le sac on regardesi le sac n'est pas plein on ajoute sinon on doit supprimer un item
void Player::Add_item_bag( Item &item){
  char c;
  if(bag.size()<MAX_ITEM){
    bag.push_back(item);

  }
  else{
    cout <<RED<<"Your bag is full remove an item if you want to add it"<<RESET<<endl;
    cout <<RED<<"tape 'y' if you want remove something or other button if not "<<RESET<<endl;

    system("stty raw");
    c = getchar();
    cout <<endl;
    system("stty cooked");
    if (c=='y')
      remove_item_bag();

  }
}
void Player::remove_item_bag(){
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
    bag.erase(bag.begin()+ i);

    lookbag();
  }
}

void Player::change_Weapon(){
  if(bag.size()<=0)
    cout <<"your bag is empty, you can't change your weapon"<<endl;
  else{
    //cout<<"choice the number of weapon wich you want replace"<<endl;
    for(int i(0); i<bag.size(); i++){
      cout <<BOLDCYAN<< bag[i].getName() << "| ";
      if(bag[i].typeOf()==WEAPON)
	//TODO 
	setWeapon((Weapon&)bag[i]);
    }
    cout<<RESET <<endl;
  }
}
const string Player::getName() const { return name; }

void Player::turn() {
  char c = 0;
  bool b = false;
  while(!b){
    system("stty raw");
    c = getchar();
    system("stty cooked");
    cout << endl;
    if(c != 'o' && c != 'k' && c != 'l' && c != 'm' && c != 'h' && c != 'q' && c!='i' && c!='w' && c!='c')
      cout << RED << "Wrong command, try again : k(left), o(up), l(down), m(right),i(list_of_item),w(your Weapon),c(change weapon),h(help), q(quit)\n" << RESET;
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
    cout << "\'i\' - list of your Item " << endl;
    cout << "\'w\' - your Weapon " << endl;
    cout << "\'c\' - change your Weapon " << endl;
  }
  else if (c=='i')
    lookbag();
  else if (c=='c')
    change_Weapon();
  else if (c=='w')
    cout << RED << "the weapon you use is: "<<getWeapon().getName()<<RESET<<endl;
  else if(c == 'q')
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
      if(interact(*floor->getCase(i-1,j))){
	floor->setBoard(i-1,j,*this);
	setSymbole('^');
	floor->setBoard(i,j);
	setI(i-1);
      }
    }
  }else if( c == 'l'){
    if(i < floor->getN()-1){
      if(interact(*floor->getCase(i+1,j))){
	floor->setBoard(i+1,j,*this);
	setSymbole('v');
	floor->setBoard(i,j);
	setI(i+1);
      }
    }
  }else if(c == 'm'){
    if(j < floor->getM()-1){
      if(interact(*floor->getCase(i,j+1))){
	floor->setBoard(i,j+1,*this);
	setSymbole('>');
	floor->setBoard(i,j);
	setJ(j+1);
      }
    }
  }
  setPlayed(true);
}

bool Player::interact(Case & c){
  if(c.typeOf() == EMPTY)
    return true;
  else if(c.typeOf() == ITEM)
    return false;
  else if(c.typeOf()==WEAPON){
    askUseOrStore((Weapon&)c);
    return true;
  }else if((c.typeOf()%10) == POTION){
    return askUseOrStore((Potion&)c);
  }else if(c.typeOf() == MONSTER){
    attack((People&)c);
    return false;
  }
}

bool Player::askUseOrStore(Potion &potion){
  char answer = 0;
  bool b = true;
  char c;
  cout << "Do you want to use(u) " << potion.getName() <<
    " or store(s) it in your bag ? Or do nothing (n)" << endl;
  while(b){
    system("stty raw");
    c = getchar();
    system("stty cooked");
    cout << endl;
    if(c != 'u' && c != 's' && c != 'n')
      cout << RED << "Wrong answer. Press u to use " << potion.getName()
	   <<", s to store it or n to do nothing" << RESET << endl;
    else
      b = false;
  }
  if(c == 'n')
    return false;
  if(c == 's')
    Add_item_bag(potion);
  else 
    use(potion);
  return true;
}
/*
void Player::askUseOrStore(Item &item){
  //TODO si cest juste un objet ne peut que le stocker
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
  if(c == 's')
    Add_item_bag(item);
}
*/
void Player::askUseOrStore(Weapon &weapon){
  char answer = 0;
  bool b = true;
  char c;
  cout << "Do you want to use(u) " << weapon.getName() <<
    " or store(s) it in your bag ?" << endl;
  while(b){
    system("stty raw");
    c = getchar();
    system("stty cooked");
    cout << endl;
    if(c != 'u' && c != 's')
      cout << RED << "Wrong answer. Press u to use " << weapon.getName()
	   <<" or s to store it" << RESET << endl;
    else
      b = false;
  }
  if(c == 's'){
    Add_item_bag(weapon);
  }
  else {//ces conditions cté just pour tester si le changement de weapon marche
    if(weapon.typeOf()==WEAPON)
      {
	cout << GREEN << "you use " <<weapon.getName()<<" Now"<<RESET << endl;
	setWeapon((Weapon &)weapon);
      }


  }
}

int Player::typeOf() const{ return PLAYER; }

void Player::use(Potion &p){
  if(p.typeOf() == POSION){
    if(life - p.getEffect() <= 0)
      die();
    else
      life -= p.getEffect();
    cout << "Your drunk posion, not potion ... Now " << getName() << " have "
	 <<getLife()<<" hp" << endl;
  }else if(p.typeOf() == RESI_UP)
    resi += (double)p.getEffect();
  else if(p.typeOf() == RESI_DOWN)
    resi -= (double)p.getEffect();
  else if(p.typeOf() == HEALING){
    if(life + p.getEffect() > MAX_LIFE)
      life = MAX_LIFE;
    else
      life += p.getEffect();
    cout << "Healing Potion used. Now " << getName() << " have "
	 <<getLife()<<" hp" << endl;
  }
}
