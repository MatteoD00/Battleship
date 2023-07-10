#ifndef CELLA_H
#define CELLA_H
#include<vector>
#include "Nave.h"


class Cella{
public:
	Cella();
	~Cella();
	bool Colpito();
	Nave* Get_occupazione();
	void Set_occupazione(Nave*);
	bool Get_sparo();
private:
	Nave* occupazione;
	bool sparo;
};

#endif
