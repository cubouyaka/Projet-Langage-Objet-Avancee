class Item {
private:
  const char symbole;
  const char * name;
  const int pods;

public:
  Item(const char s = '?', const char * n = "Unknown Item", const int p = 1);

  const char getSymbole() const;
  const char * getName() const;
  const int getPods() const;

};

class Potion : public Item {
private:
  const int effect;
  
public:
  Potion(const int e = 0, const char s = 'P', const char * n = "Unknown Potion");

  const int getEffect() const;
};

class Weapon : public Item {
private:
  const int attack;
  const int scope;
  mutable int durability;

public:
  Weapon(const int a = 10, int d = 10, const int sc = 1, const char s = 'W',
	 const char * n = "Unknown Weapon", const int p = 5);

  const int getAttack() const;
  const int getScope() const;
  int getDurability() const;
  bool setDurability() const;
};
