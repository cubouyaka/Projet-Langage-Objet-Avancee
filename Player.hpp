#ifndef PLAYER_H
#define PLAYER_H
#include "People.hpp"
#include <vector>

//TODO END DEF ect..
#define MAX_ITEM 10
class Player : public People {
private:
  const char * name;
  mutable std::vector<Item> bag;

public:
  Player(int i = -1, int j = -1, const char* n = "?", int l = MAX_LIFE_PLAYER,
	 const double r = 1,const int s = 1, int va = 5,
	 const Weapon w = DEFAULT_WEAPON);

  void setSymbole(char s);
  const char * getName() const;
  void print() const;
  //methode pour voir les items du joueur
  void lookbag() const;
  //methode pour ajouter un item dans le sac
  void Add_item_bag( Item &item) const;
  //metho pour supprimer un item dans le sac
  void remove_item_bag() ;
  //methode pour changer d'arme
  void change_Weapon();
};

#endif
