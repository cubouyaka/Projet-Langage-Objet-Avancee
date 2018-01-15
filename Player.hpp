#ifndef PLAYER_H
#define PLAYER_H
#include "Game.hpp"
#include <vector>
#include <typeinfo>

#define MAX_ITEM 3

class Game;

class Player : public People {
private:
  const string name;
  mutable std::vector<Item> bag;

public:
  Game * game;
  Player(Game  *g = NULL, Floor* f = NULL, int i = -1, int j = -1, 
	 const string n = "???",
	 int l = MAX_LIFE_PLAYER, const double r = 1,const int s = 1,
	 int va = 5, const Weapon w = DEFAULT_WEAPON);
  virtual ~Player();
  void setSymbole(char s);
  const string getName() const;

  int typeOf() const;
  void turn(); //one turn of the player
  void move(char c);
  bool interact(Case & c);
  void print() const;
  //methode pour voir les items du joueur
  void lookbag() const;
  //methode pour ajouter un item dans le sac
  void Add_item_bag(Item &item) ;
  //metho pour supprimer un item dans le sac
  void remove_item_bag() ;
  //methode pour changer d'arme
  void change_Weapon();
  bool askUseOrStore(Weapon &weapon);
  bool askUseOrStore(Potion &potion);
  void use(Potion &p);
  bool healSource(); //get all your life back thanks to the source
};

#endif
