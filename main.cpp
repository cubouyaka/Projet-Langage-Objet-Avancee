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
  string file;
  ifstream fileC;
  cout<<"Select the file to load the game"<<endl;
  cin>>file;
  fileC.open(file.c_str());
  while(fileC.fail()){
    cout <<"Wrong input, try again"<<endl;
    cin >> file;
  }
  fileC.close();

  loadFile(file);
}

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
	    Posion *posion = new Posion();
	    floors[k]->setBoard(i,j,posion);
	  }else if(contenu[j]=='H'){
	    HealingPotion *healposion = new HealingPotion();
	    floors[k]->setBoard(i,j,healposion);
	  }else if(contenu[j]=='R'){
	    ResiUpPotion * residup = new ResiUpPotion();
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
	}
	i++;
      }
    }
    game.setCurrentFloor((int)(rand()%nb_floors));
    game.play();
  }
}
