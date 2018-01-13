#include "Monster.hpp"
#include "Player.hpp"
#include "Warrior.hpp"
#include "Wizard.hpp"
#include "Floor.hpp"
#include "Weapon.hpp"
#include "Item.hpp"
#include <iostream>

using namespace std;


int main(){
  Floor floor(15,10);
  Posion poison(10);
  floor.setBoard(0,0,poison);
  Player player(&floor,3,7,"Ida");
  floor.setBoard(3,7,player);
  Monster monster(1,2);
  floor.setBoard(1,2,monster);
  monster.setFloor(&floor);
  Monster monster2(3,2);
  floor.setBoard(3,2,monster2);
  monster2.setFloor(&floor);
  Monster monster3(7,6);
  floor.setBoard(7,6,monster3);
  monster3.setFloor(&floor);
  floor.print();
  floor.turn();
  cout << "TRRT"<<endl;
  /*Floor f(10,10);
  Item p;
  for(int i = 0; i < 10 ; i++)
    for(int j = 0; j< 10; j++)
      f.setBoard(i,j,pp);
  f.setBoard(4,5,p);
  f.print();
  Item it('i',"boisson magique");
  Item it2('c',"baguette magique");
  Item it3('a',"golden apple");
  Item it4('d',"Sword");
  Item it5('f',"phone");
  Weapon fireBall(15,-1,5,'B',"FireBall");
  Weapon Shuriken (10,10,5,'?',"Shuriken");
  Weapon sword(15,20,1,'S',"Sword II");
  Player p;
  p.Add_item_bag(it);
  p.Add_item_bag(it2);
  p.Add_item_bag(it3);
  p.Add_item_bag(it4);
  p.Add_item_bag(fireBall);
  p.Add_item_bag(sword);
  p.Add_item_bag(Shuriken);
  p.lookbag();
  p.remove_item_bag();
  Potion pos(10,'p',"pop drink");
  pos.print();*/
  /*
Wizard w(0,0);
  People p(10,1);

  People t(12,45,'T',1000,2,4,4,fireBall);
  cout << GREEN << p.getSymbole() << endl;
  p = t;
  cout << GREEN << p.getSymbole() << endl;
  Weapon re;
  re = fireBall;
  cout<<WHITE <<re.getSymbole()<<YELLOW<<w.getWeapon().getSymbole()<<endl;
  p.setWeapon(fireBall);
  cout<<BLUE<<p.getWeapon().getName()<<RESET;
=======
  string name = "Ivan LE TERRILE";
  Player p1(&f, 3,7,name);
  f.setBoard(3,7,p1);
  Potion pp(10,'P',"eau de vie");
  f.setBoard(1,0,pp);
  f.print();
  Wizard w(0,0);
  People p(&f,10,1);
  Weapon fireBall(15,-1,5,'?',"FireBall");
  People t(&f,12,45,'T',1000,2,4,4,fireBall);
>>>>>>> ccafb6b75eb7b2b1f4b4e3593b016536820f6408
  cout << p.getLife() << endl;

  w.attack(p);
<<<<<<< HEAD
  cout << p.getLife() << endl;
  f.turn();
  //*/

  /*  mo.setSymbole('^');
  mo.print();
  Warrior w;
  w.print();
  Ninja N;
  N.print();
  N.getposition();
  N.teleportation();
  N.getposition();
  Cavalier C;
  C.print();
  */
}
