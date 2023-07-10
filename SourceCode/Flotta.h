#ifndef FLOTTA_H
#define FLOTTA_H
#include<vector>

#include "Nave.h"

class Flotta{
public:
	Flotta();
	~Flotta();
	std::vector<Nave*>::const_iterator Flotta_begin();
	std::vector<Nave*>::const_iterator Flotta_end();
	bool Check_affondata();
	void Aggiungi_Nave();
	void Rimuovi_Nave();
	void Affonda_Nave();
	int Get_NaviTotali();
	int Get_NumeroPosizionate();
private:
	int numero_navi;
	int numero_affondate;
	int numero_posizionate;
	std::vector<Nave*> nave;
	bool affondata;
};

#endif
