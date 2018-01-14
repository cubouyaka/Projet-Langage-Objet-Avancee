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
