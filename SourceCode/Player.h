#ifndef PLAYER_H
#define PLAYER_H
#include "Flotta.cpp"
#include "mappa.cpp"

class Player{
private:
	Flotta* flotta;
	Mappa* mappa;
	int name;
	void insert_in_cells(int,int,int,int, Nave*);

public:
	Player(int);
	~Player();
	void position(int);
    void remove(int);
	bool shoot();
	Flotta* Get_Flotta();
    Mappa* Get_Mappa();

};

#endif
