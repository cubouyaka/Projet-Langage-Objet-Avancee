#ifndef PLAYER_H
#define PLAYER_H
#include "People.hpp"
#include <vector>

//TODO END DEF ect..
#define MAX_ITEM 10
class Player : public People {
<<<<<<< HEAD
private:
  const char * name;
=======
private: 
  const string name;
>>>>>>> ccafb6b75eb7b2b1f4b4e3593b016536820f6408
  mutable std::vector<Item> bag;

public:
<<<<<<< HEAD
  Player(int i = -1, int j = -1, const char* n = "?", int l = MAX_LIFE_PLAYER,
	 const double r = 1,const int s = 1, int va = 5,
	 const Weapon w = DEFAULT_WEAPON);
=======
  Player(Floor* f = NULL, int i = -1, int j = -1, const string n = "???", 
	 int l = MAX_LIFE_PLAYER, const double r = 1,const int s = 1, 
	 int va = 5, const Weapon w = DEFAULT_WEAPON);
>>>>>>> ccafb6b75eb7b2b1f4b4e3593b016536820f6408

  void setSymbole(char s);
  const string getName() const;
  void turn();
  void move(char c);
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
