#include "Game.hpp"
Game::Game(int nb_f):nb_floor(nb_f){
  floors = new Floor * [nb_floor];
  srand(time(NULL));
  i_current_floor = (int)(rand() % nb_floor);
  nb_tours = 0;
}

void Game::setFloor(int n, Floor* f){ floors[n] = f; }

void Game::play(){
  floors[i_current_floor]->turn();
  nb_tours++;
}
  void Game::Loadfile(string fichier)
  {
    int n=0,m=0;
    int i=0;
    ifstream file(fichier.c_str(), ios::in);  // on ouvre en lecture
    if(file)  // si l'ouverture a fonctionné
    {

      string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
            // on met dans "contenu" la ligne
      while(getline(file, contenu)){

        for(int j=0; j<contenu.size(); j++)
          {

            if(contenu[i]=='.')
              floors[0]->setBoard(i,j);
            if(contenu[i]=='#')
              floors[0]->setBoard(i,j,'#');
              if(contenu[i]==' ')
                floors[0]->setBoard(i,j,' ');
            if (contenu[j]=='C')
              {
                Cavalier cav(i,j);
                floors[0]->setBoard(i,j,cav);
            }
            if (contenu[j]=='N')
              {
                Ninja ninja(i,j);
                floors[0]->setBoard(i,j,ninja);
            }
            if (contenu[j]=='m')
              {
                Monster monster(i,j);
                floors[0]->setBoard(i,j,monster);
            }
            if (contenu[j]=='h')
              {
                Posion posion(i+10);
                floors[0]->setBoard(i,j,posion);
              }
              if (contenu[j]=='H')
                {
                  HealingPotion healposion(i+5);
                  floors[0]->setBoard(i,j,healposion);
                }
                if (contenu[j]=='R')
                  {
                    ResiUpPotion residup(i+5);
                    floors[0]->setBoard(i,j,residup);
                  }
                  if (contenu[j]=='r')
                    {
                      ResiDownPotion resdown(i);
                      floors[0]->setBoard(i,j,resdown);
                    }
              if (contenu[j]=='I' or contenu[j]=='?' )
                {
                  Item item(floors[0],contenu[j]);
                  floors[0]->setBoard(i,j,item);
                }
                if (contenu[j]=='W')
                  {
                    Warrior warrior(i,j);
                    floors[0]->setBoard(i,j,warrior);
                    warrior.setFloor(floors[0]);
                  }
              if (contenu[j]=='w')
                {
                  Weapon weapon(i+5,j,'w');
                  floors[0]->setBoard(i,j,weapon);
                }
                if (contenu[j]=='<'|| contenu[j]=='>' ||contenu[j]=='^'||contenu[j]=='v')
                 {
                   Player player(floors[0],i,j,"Ida");

                    floors[0]->setBoard(i,j,player);
                  }

          }
          cout<<endl;
          i++;
      }

      file.close();
      floors[0]->print();
    }
    else
            cerr << "Impossible d'ouvrir le fichier !" << endl;
}
