#include "Nave.h"

Nave::Nave(){
    posizionata=false;
	affondata=false;
    xmin=0;
    xmax=0;
    ymin=0;
    ymax=0;
}


bool Nave::Check_affondata(){
	if(lunghezza==colpi){
		affondata=true;
		return true;
	}
    else{
        return false;
    }
}

bool Nave::Get_posizionata(){
	return posizionata;
}

void Nave::Colpito(){
    colpi++;
}

void Nave::Position(){
	posizionata=true;
}

void Nave::Reposition(){
	posizionata=false;
}

std::string Nave::Get_name(){
	return name;
}

void Nave::Set_name(string N){
    name=N;
}

int Nave::Get_ID(){
    return ID;
}

void Nave::Set_ID(int temp){
    ID = temp;
}

int Nave::Get_lunghezza(){
	return lunghezza;
}

void Nave::Set_lunghezza(int L){
    lunghezza=L;
}

void Nave::Set_xmin(int temp){
    xmin = temp;
}

void Nave::Set_xmax(int temp){
    xmax = temp;
}

void Nave::Set_ymin(int temp){
    ymin = temp;
}

void Nave::Set_ymax(int temp){
    ymax = temp;
}

int Nave::Get_xmin(){
    return xmin;
}

int Nave::Get_xmax(){
    return xmax;
}

int Nave::Get_ymin(){
    return ymin;
}

int Nave::Get_ymax(){
    return ymax;
}
