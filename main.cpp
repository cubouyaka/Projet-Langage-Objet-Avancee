#include "Monster.hpp"
#include "Player.hpp"
#include "Warrior.hpp"
#include "Wizard.hpp"
#include "Game.hpp"
#include "Weapon.hpp"
#include "Item.hpp"
#include <iostream>
#include <string>

using namespace std;

void loadFile(string fichier);

int main(){
  srand (time(NULL));
  loadFile("fichier.txt");
  /*Floor floor(15,10);
    Posion poison(10);
    floor.setBoard(0,0,poison);
    Warrior warrior(2,7);
    floor.setBoard(2,7,warrior);
    warrior.setFloor(&floor);
    Warrior2 warrior2(4,7);
    floor.setBoard(4,7,warrior2);
    warrior2.setFloor(&floor);
    Player player(&floor,3,7,"Ida");
    floor.setBoard(3,7,player);
    Monster monster(1,2);
    floor.setBoard(1,2,monster);
    monster.setFloor(&floor);
    Monster2 monster2(3,2);
    floor.setBoard(3,2,monster2);
    monster2.setFloor(&floor);
    Monster monster3(7,6);
    floor.setBoard(7,6,monster3);
    monster3.setFloor(&floor);

    Wall wall;
    floor.setBoard(2,2,wall);

    Source source;
    floor.setBoard(7,8,source);*/
  /*
    Weapon fireBall(15,-1,5,'B',"FireBall");
    floor.setBoard(2,5,fireBall);*/
  /*Weapon Shuriken (10,10,5,'?',"Shuriken");
    floor.setBoard(7,3,Shuriken);
    Weapon sword(15,20,1,'S',"Sword II");
    floor.setBoard(8,7,sword);*/

  /*
    Floor floor(18,10);
    Game game(1);
    game.setFloor(0,&floor);
    string toto="fichier.txt";

    game.Loadfile(toto);
  */

  //  floor.print();
  //while(1)
  ///game.play();
  //floor.turn();
}
/*
  void loadFile(string fichier){
  ifstream file(fichier.c_str(), ios::in);  // on ouvre en lecture
  int n, m, nb_floors;
  int i_floor = 0;
  if(file){
  string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
  // on met dans "contenu" la ligne      
  getline(file,contenu);
  nb_floors = atoi(contenu.c_str());
  getline(file,contenu);
  n =  atoi(contenu.c_str());
  getline(file,contenu);
  m =  atoi(contenu.c_str());
  int i = 0;

  Game game(nb_floors);
  Floor floor(n,m);
  game.setFloor(i_floor,&floor);
  Wall wall;

  while(getline(file, contenu)){
  for(int j=0; j<m; j++){
  if(contenu[j]=='.')
  floor.setBoard(i,j);
  else if(contenu[j]=='#'){
  floor.setBoard(i,j,&wall);
  }else if (contenu[j]=='c'){
  Cavalier cav(i,j);
  floor.setBoard(i,j,&cav);
  cav.setFloor(&floor);
  }else if (contenu[j]=='C'){
  Cavalier2 cav2(i,j);
  floor.setBoard(i,j,&cav2);
  cav2.setFloor(&floor);
  }else if (contenu[j]=='n'){
  Ninja ninja(i,j);
  floor.setBoard(i,j,&ninja);
  ninja.setFloor(&floor);
  }else if (contenu[j]=='N'){
  Ninja2 ninja2(i,j);
  floor.setBoard(i,j,&ninja2);
  ninja2.setFloor(&floor);
  }else if (contenu[j]=='m'){
  Monster monster(i,j);
  floor.setBoard(i,j,&monster);
  monster.setFloor(&floor);
  }else if (contenu[j]=='M'){
  Monster2 monster2(i,j);
  floor.setBoard(i,j,&monster2);
  monster2.setFloor(&floor);
  }else if(contenu[j]=='h'){
  Posion posion(i+10);
  floor.setBoard(i,j,&posion);
  }else if(contenu[j]=='H'){
  HealingPotion healposion(i+5);
  floor.setBoard(i,j,&healposion);
  }else if(contenu[j]=='R'){
  ResiUpPotion residup(i+5);
  floor.setBoard(i,j,&residup);
  }else if(contenu[j]=='r'){
  ResiDownPotion resdown(i);
  floor.setBoard(i,j,&resdown);
  }else  if (contenu[j]=='I' or contenu[j]=='?' ){
  Item item(&floor,contenu[j]);
  floor.setBoard(i,j,&item);
  }else  if (contenu[j]=='W'){
  Warrior warrior(i,j);
  floor.setBoard(i,j,&warrior);
  warrior.setFloor(&floor);
  }else  if (contenu[j]=='w'){
  Weapon weapon(i+5,j,'w');
  floor.setBoard(i,j,&weapon);
  }else if (contenu[j]=='<'|| contenu[j]=='>' ||contenu[j]=='^'||contenu[j]=='v'){
  Player player(&floor,i,j,"Ida");
  floor.setBoard(i,j,&player);
  }
  }
  i++;
  }
  floor.print();
  }
  }
  /*
  void lloadFile(string fichier)
  {
  int n, m, nb_floors;
  int i_floor = 0;
  ifstream file(fichier.c_str(), ios::in);  // on ouvre en lecture
  if(file)  // si l'ouverture a fonctionné
  {
  char c;
  file >> c;
  string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
  // on met dans "contenu" la ligne      
  getline(file,contenu);
  nb_floors = atoi(contenu.c_str());
  getline(file,contenu);
  n =  atoi(contenu.c_str());
  getline(file,contenu);
  m =  atoi(contenu.c_str());

  while(getline(file, contenu)){
  for(int i = 0; i < n; i++){
  for(int j=0; j<m; j++){
            
  }
  cout<<endl;
  }
  }

  file.close();
  floor.print();
  }
  else
  cerr << "Impossible d'ouvrir le fichier !" << endl;
  }
*/
void loadFile(string fichier){
ifstream file(fichier.c_str(), ios::in);  // on ouvre en lecture
  int n, m, nb_floors;
  if(file){
    string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
    // on met dans "contenu" la ligne      
    getline(file,contenu);
    nb_floors = atoi(contenu.c_str());
    Game game(nb_floors);
    Floor ** floors = new Floor*[nb_floors];
    for(int k = 0; k<nb_floors ; k++){
      getline(file,contenu);
      n =  atoi(contenu.c_str());
      getline(file,contenu);
      m =  atoi(contenu.c_str());
      int i = 0;

      floors[k] = new Floor(n,m);
      game.setFloor(k,floors[k]);
      Wall *wall = new Wall();
      Source *source = new Source();
      Space *space = new Space();
      StairsUp *s_up = new StairsUp();
      StairsDown *s_down = new StairsDown();
      while(i<n){
	getline(file, contenu);
	for(int j=0; j<m; j++){
	  if(contenu[j]==' ')
	    floors[k]->setBoard(i,j,space);
	  if(contenu[j]=='.')
	    floors[k]->setBoard(i,j);
	  else if(contenu[j]=='X')
	    floors[k]->setBoard(i,j,source);
	  else if(contenu[j]=='#')
	    floors[k]->setBoard(i,j,wall);
	  else if(contenu[j]=='U')
	    floors[k]->setBoard(i,j,s_up);
	  else if(contenu[j]=='D')
	    floors[k]->setBoard(i,j,s_down);
	  else if (contenu[j]=='c'){
	    Cavalier *cav = new Cavalier(i,j);
	    floors[k]->setBoard(i,j,cav);
	    cav->setFloor(floors[k]);
	  }else if (contenu[j]=='C'){
	    Cavalier2 *cav2 = new Cavalier2(i,j);
	    floors[k]->setBoard(i,j,cav2);
	    cav2->setFloor(floors[k]);
	  }else if (contenu[j]=='n'){
	    Ninja *ninja = new Ninja(i,j);
	    floors[k]->setBoard(i,j,ninja);
	    ninja->setFloor(floors[k]);
	  }else if (contenu[j]=='N'){
	    Ninja2 *ninja2 = new Ninja2(i,j);
	    floors[k]->setBoard(i,j,ninja2);
	    ninja2->setFloor(floors[k]);
	  }else if (contenu[j]=='m'){
	    Monster *monster = new Monster(i,j);
	    floors[k]->setBoard(i,j,monster);
	    monster->setFloor(floors[k]);
	  }else if (contenu[j]=='M'){
	    Monster2 *monster2 = new Monster2(i,j);
	    floors[k]->setBoard(i,j,monster2);
	    monster2->setFloor(floors[k]);
	  }else if(contenu[j]=='h'){
	    Posion *posion = new Posion(i+10);
	    floors[k]->setBoard(i,j,posion);
	  }else if(contenu[j]=='H'){
	    HealingPotion *healposion = new HealingPotion(i+5);
	    floors[k]->setBoard(i,j,healposion);
	  }else if(contenu[j]=='R'){
	    ResiUpPotion * residup = new ResiUpPotion(i+5);
	    floors[k]->setBoard(i,j,residup);
	  }else if(contenu[j]=='j'){
	    Weapon * shuriken = new Weapon(100,10,5,'j',"Shuriken");
	    floors[k]->setBoard(i,j,shuriken);
	  }else if(contenu[j]=='s'){
	    Weapon * sword = new Weapon(15,20,1,'s',"Sword");
	    floors[k]->setBoard(i,j,sword);
	  }else if(contenu[j]=='S'){
	    Weapon * sword2 = new Weapon(15,20,1,'S',"Sword II");
	    floors[k]->setBoard(i,j,sword2);
	  }else if(contenu[j]=='r'){
	    ResiDownPotion *resdown = new ResiDownPotion(i);
	    floors[k]->setBoard(i,j,resdown);
	  }else  if (contenu[j]=='I' or contenu[j]=='?' ){
	    Item * item = new Item(floors[k],contenu[j]);
	    floors[k]->setBoard(i,j,item);
	  }else  if (contenu[j]=='w'){
	    Warrior *warrior = new Warrior(i,j);
	    floors[k]->setBoard(i,j,warrior);
	    warrior->setFloor(floors[k]);
	  }else  if (contenu[j]=='z'){
	    Magician *magician = new Magician(i,j);
	    floors[k]->setBoard(i,j,magician);
	    magician->setFloor(floors[k]);
	  }else  if (contenu[j]=='Z'){
	    Magician2 *magician2 = new Magician2(i,j);
	    floors[k]->setBoard(i,j,magician2);
	    magician2->setFloor(floors[k]);
	  }else  if (contenu[j]=='W'){
	    Warrior2 *warrior2 = new Warrior2(i,j);
	    floors[k]->setBoard(i,j,warrior2);
	    warrior2->setFloor(floors[k]);
	  }
	  /*else if (contenu[j]=='<'|| contenu[j]=='>' ||contenu[j]=='^'||contenu[j]=='v'){
	    Player * player = new Player(&game,&floor,i,j,"Ida");
	    floor.setBoard(i,j,*player);
	  }
	  */
	}
	i++;
      }
    }
    game.setCurrentFloor((int)(rand()%nb_floors));
    game.play();
  }
}
