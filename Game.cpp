#include "Game.hpp"

Game::Game(int nb_f):nb_floor(nb_f){
  floors = new Floor * [nb_floor];
  srand(time(NULL));
  i_current_floor = (int)(rand() % nb_floor);
  nb_tours = 0;
}
Game::~Game()
{
  delete[] floors;
}
void Game::setFloor(int n, Floor* f){ floors[n] = f; }

void Game::play(){
  Player * player = new Player(this,floors[i_current_floor],1,1,"Ida");
  floors[i_current_floor]->setBoard(1,1,player);
  floors[i_current_floor]->print();
  while(true){
    nb_tours++;
    cout << "------------TOUR N°"<<nb_tours<<"----------------"<<endl;
    floors[i_current_floor]->turn();
    floors[i_current_floor]->print();
  }
}

Floor * Game::getFloor(int n){ return floors[n]; }

int Game::getNbFloor() const{ return nb_floor; }

void Game::setCurrentFloor(int n){ i_current_floor = n; }
