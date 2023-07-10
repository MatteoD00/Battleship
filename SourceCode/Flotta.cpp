#include <vector>
using std::vector;

#include "Flotta.h"
#include "Nave.cpp"
#include "Corazzata.cpp"
#include "Sottomarino.cpp"
#include "Corvetta.cpp"
#include "Lancia.cpp"
#include "Acqua.cpp"

//Costruttore
Flotta::Flotta(){

  //numero dei tipi di nave
  int n_corazzate=1;
  int n_sottomarini=3;
  int n_corvette=3;
  int n_lance=1;


  numero_navi=0;
  numero_affondate=0;
  numero_posizionate=0;
  affondata=false;

  for (int j=0; j<n_corazzate; j++){
    nave.push_back(new Corazzata(numero_navi+1));
    numero_navi++;
  }

  for (int j=0; j<n_sottomarini; j++){
    nave.push_back(new Sottomarino(numero_navi+1));
    numero_navi++;
  }
  

  for (int j=0; j<n_corvette; j++){
    nave.push_back(new Corvetta(numero_navi+1));
    numero_navi++;
  }

  for (int j=0; j<n_lance; j++){
    nave.push_back(new Lancia(numero_navi+1));
    numero_navi++;
  }
}

//Distruttore
Flotta::~Flotta(){
  vector<Nave*>::iterator i;
  for (i = nave.begin(); i!=nave.end(); i++){
    delete *i;
  }

}

//Lunghezza nave
/*int Flotta::sizeNave() const{
  return unit.size();
}
*/

vector<Nave*>::const_iterator Flotta::Flotta_begin(){
  return nave.begin();
}

vector<Nave*>::const_iterator Flotta::Flotta_end(){
  return nave.end();
}

int Flotta::Get_NaviTotali(){
  return numero_navi;
}

int Flotta::Get_NumeroPosizionate(){
    return numero_posizionate;
}

bool Flotta::Check_affondata(){
  if (numero_affondate==numero_navi){
    return true;
  }
     else {
       return false;
     }

  }

void Flotta::Aggiungi_Nave(){
	numero_posizionate++;
}

void Flotta::Rimuovi_Nave(){
	numero_posizionate--;
}

void Flotta::Affonda_Nave(){
    numero_affondate++;
}
