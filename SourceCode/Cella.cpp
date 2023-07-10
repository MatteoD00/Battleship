#include<string>
#include<iostream>
#include "Cella.h"


Cella::Cella(){
	occupazione=new Acqua();
	sparo=false;
}

Cella::~Cella(){
	delete occupazione;
}

bool Cella::Colpito(){
	if(sparo==false){
		sparo=true;
		std::cout<<((occupazione->Get_lunghezza()==0)? "\n\t\tAcqua...\n" : "\n\t\tCOLPITO!\n" ) <<std::endl;
        if(occupazione->Get_lunghezza()!=0){
            occupazione->Colpito();
        }
        return true;
		}
	else{
		std::cout<<"La cella selezionata e' gia' stata colpita, selezionarne un'altra"<<std::endl;
		return false;
		}
}

Nave* Cella::Get_occupazione(){
	return occupazione;
}

void Cella::Set_occupazione(Nave* nave){
	if(occupazione->Get_lunghezza()==0){
		delete occupazione;
	}
	occupazione=nave;
}

bool Cella::Get_sparo(){
	return sparo;
}
