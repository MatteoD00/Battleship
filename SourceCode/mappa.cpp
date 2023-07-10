#include <iostream>
#include <iomanip>

#include "mappa.h"

using namespace std;

Mappa::Mappa(){
    griglia=new Cella*[dimensione];
	for(int i=0;i<dimensione;i++){
        griglia[i]=new Cella[dimensione];
		}
}

Mappa::~Mappa(){
	for(int i=0;i<dimensione;i++){
		for(int j=0;j<dimensione;j++){
			delete &griglia[i][j];
		}
	}
}

void Mappa::Draw(bool printNave)
{
    //stampo la prima riga con le lettere delle colonne
    for(int i=0; i<dimensione+1; i++){
         if(i==0){
            cout<<setfill(' ')<<setw(3)<<right<<" "
                <<setw(3)<<" |";;
        }
        else{
            cout<<setw(3)<<char(64+i)
                <<setw(3)<<" |";
        }
    }

    //stampo la matrice  avendo come prima colonna il numero della riga
    cout<<endl
        <<setfill('-')<<setw(6*(dimensione+1)+1)<<" "<<endl;

    for(int j=0; j<dimensione; j++){
        for(int i=0; i<dimensione+1; i++){

            if(i==0){
                cout<<setfill(' ')<<setw(3)<<j+1
                    <<setw(3)<<" |";
            }
            else
            {
                if(printNave)
                {

                    cout<<setfill(' ')<<setw(3);
                    if(griglia[i-1][j].Get_occupazione()->Get_lunghezza() == 0){cout<<" ";}else{cout<<griglia[i-1][j].Get_occupazione()->Get_ID();}
                        cout<<((((griglia[i-1][j]).Get_sparo()) == false) ? " " : ((((griglia[i-1][j]).Get_occupazione()->Get_lunghezza()) == 0) ? "*" : "X" ))
                        <<setw(2)<<" |";
                }
                else
                {
                    cout<<setfill(' ')<<setw(3)<<((((griglia[i-1][j]).Get_sparo()) == false) ? " " : (((((griglia[i-1][j]).Get_occupazione()->Get_lunghezza())) == 0) ? "*" : "#" ))
                        <<setw(3)<<" |";
                }

            }
        }
        cout<<endl<<setfill('-')<<setw(6*(dimensione+1)+1)<<" "<<endl;
    }
}

int Mappa::GetDim()
{
    return dimensione;
}

bool Mappa::checkcolpo(int x, int y)
{
    if(x>=0 && x<dimensione && y>=0 && y<dimensione)    //verifica che il colpo sia nella mappa
    {
        bool colpito = griglia[x][y].Colpito();
        if(colpito) //verifica che il colpo sia in una cella in cui non si è ancora sparato
        {
            return true;
        }
        else
        {
            cout<<"\nColpo non valido perche' in una casella già colpita\n";
            return false;
        }
    }
    else
    {
        cout<<"\nColpo non valido perche' fuori dalla mappa\n";
        return false;
    }
}


bool Mappa::checknave(int x0, int y0, int lung, bool* direction)
{
    if(x0<dimensione && x0>=0 && y0<dimensione && y0>=0) //indici: 0=nord 1=est 2=sud 3=ovest
    {
        direction[0]=Scorri(x0,y0-lung+1,x0,y0);
        direction[1]=Scorri(x0,y0,x0+lung-1,y0);
        direction[2]=Scorri(x0,y0,x0,y0+lung-1);
        direction[3]=Scorri(x0-lung+1,y0,x0,y0);
    }
    else
    {
        cout<<"Posizione non valida: nave fuori dalla mappa\n";
        for(int i=0; i<4; i++)
        {
            direction[i]=false;
        }
        return false;
    }

    for(int k=0; k<4; k++)
    {
        if(direction[k])
        {
            return true;
        }
    }
    return false;
}

bool Mappa::Scorri(int x0, int y0, int xf, int yf)
{
    if(x0<0 || xf>dimensione-1 || y0<0 || yf>dimensione-1)
    {
        return false;
    }
    else
    {
        for(int y=y0; y<yf+1; y++)
        {
            for(int x=x0; x<xf+1; x++)
            {
                if((griglia[x][y].Get_occupazione())->Get_lunghezza() != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
}
