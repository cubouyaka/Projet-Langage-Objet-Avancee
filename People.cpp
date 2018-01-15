#include "People.hpp"

People::People(Floor* f,int i, int j, char s, int l,double r, const int S,int va,
	       Weapon w,Item it) : Case(s,f,i,j), life(l), resi(r),
					 size(S), visual_area(va), weapon(w),
					 item(it){ played = false; }
People::People(const People &p) :
  Case(p.getSymbole(),p.getFloor(),p.getI(),p.getJ()),life(p.getLife()),
  resi(p.getResi()), size(p.getSize()), visual_area(p.getVArea()),
  weapon(p.getWeapon()),item(p.getItem()) { played = false;}

People::~People(){
  //TODO ?
}

People& People::operator=(const People &p){
  life = p.getLife();
  resi = p.getResi();
  visual_area = p.getVArea();
  weapon = p.getWeapon();
}


const string People::getName() const{};
bool People::getPlayed() const{ return played; }
int People::getLife() const { return life; }
double People::getResi() const { return resi; }
const int People::getSize() const { return size; }
int People::getVArea() const { return visual_area; }
Weapon People::getWeapon() const { return weapon; }
Item People::getItem() const { return item; }
void People::setPlayed(bool b) { played = b; }

void People::setWeapon(Weapon &w) { 
  weapon = w;
  cout << BOLDGREEN<<"Now you use " << weapon.getName() <<RESET << endl;
}

void People::setWeapon(int a){  weapon.setAttack(a); }

bool People::attacked(const People &p){
  if(life-p.getWeapon().getAttack()*resi < 0)
    life = 0;
  else
    life -= p.getWeapon().getAttack()*resi;
  cout << p.getName() << " attacked " << getName() <<". Now "<<getName()
       <<" has " << getLife() <<" hp"<<endl ;

  return (life<= 0);
}

void People::attack(People &p){
  if(p.attacked(*this))
    p.die();
  if(weapon.setDurability()){ //if the weapon is over
    cout << BOLDMAGENTA << getWeapon().getName() <<
      " is over, now you're using your hands" << RESET << endl;
    Weapon w = DEFAULT_WEAPON;
    setWeapon(w);//replace it with DEFAULT_WEAPON (cf People.hpp)
  }
}
/*
void People::drinkPotion(const HealingPotion  &p) {
  if(life + p.getEffect() > MAX_LIFE)
    life = MAX_LIFE;
  else
    life += p.getEffect();
}

void People::drinkPotion(const Posion  &p) {
  if(life - p.getEffect() <= 0)
    die();
  else
    life -= p.getEffect();
}

void People::drinkPotion(const ResiUpPotion  &p){ resi += (double)p.getEffect();}

void People::drinkPotion(const ResiDownPotion &p){resi -= (double)p.getEffect();}
*/
void People::die() {
  if (typeOf()==PLAYER) {
    cout <<BOLDRED << getName() <<" YOU LOSE , die in case ("<<getI()<<";"
	 <<getJ()<<")"<<RESET<<endl;
    exit(0);
  }
  cout << getName() <<" die in case ("<<getI()<<";"<<getJ()<<")"<<endl;
  getFloor()->setBoard(getI(),getJ());
}
