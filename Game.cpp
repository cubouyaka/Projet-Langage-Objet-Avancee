#include "Game.hpp"

Game::Game(int nb_f):nb_floor(nb_f){
  floors = new Floor * [nb_floor];
  srand(time(NULL));
  i_current_floor = (int)(rand() % nb_floor);
  nb_tours = 0;
}

void Game::setFloor(int n, Floor* f){ floors[n] = f; }

void Game::play(){
  while(true){
    nb_tours++;
    cout << "------------TOUR N°"<<nb_tours<<"----------------"<<endl;
    floors[i_current_floor]->turn();
  }
}

Floor * Game::getFloor(int n){ return floors[n]; }
