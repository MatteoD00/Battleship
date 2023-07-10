#include "Player.h"
#include<vector>

Player::Player(int Name){
    name=Name;
    mappa=new Mappa();
    flotta=new Flotta();
}

Player::~Player(){
    delete flotta;
    delete mappa;
}

//funzione per inserire nave nelle celle
void Player::insert_in_cells(int x0, int y0, int xf, int yf, Nave* ship){
    for(int i=x0;i<xf+1;i++){
        for(int j=y0;j<yf+1;j++){
        mappa->griglia[i][j].Set_occupazione(ship);
        }
    }
    ship->Set_xmin(x0);
    ship->Set_ymin(y0);
    ship->Set_xmax(xf);
    ship->Set_ymax(yf);
};

void Player::position(int n_nave){
    vector<Nave*>::const_iterator ship=flotta->Flotta_begin()+n_nave;
	bool direzioni[4]={false,false,false,false};
    char punticard[4]={'n','e','s','o'};
    int x,y;
	bool c=false;
    cout<<"\nOra bisogna posizionarla. Si ricordi che ai bordi della mappa e' piu' facile per il nemico ricostruire la posizione della nave.\n";
	//scegli la posizione e controlla che sia valida
	while(c==false){
        x=1000;
        y=1000;
        while(x<0 || x>=mappa->GetDim()){
            cout<<"Inserire la lettera (maiuscola) della colonna:\n"<<endl;
            char temp;
            cin>>temp;
            x=int(temp)-int('A');
        }
        while(y<0 || y>=mappa->GetDim()){
            cout<<"Inserire il numero della riga:\n"<<endl;
	    string temp;
            cin>>temp;
	    if(temp[1]=='\0'){
	    	y=int(temp[0])-int('1');
	    }
	    else{
	    	y=(int(temp[0])-int('1')+1)*10+(int((temp[1]))-int('1'));
            }
        }
		int l=(*ship)->Get_lunghezza();
		c=mappa->checknave(x,y,l,direzioni); //falso se si sovrappone con una nave
		if(!c){
            cout<<"C'e' gia' una nave in quella posizione, selezionane un'altra\n";
		}
	}

	//stampa le direzioni disponibili
    cout<<"Le elenco le direzioni disponibili, capitano:\n";
	for(int j=0;j<4;j++){
		if(direzioni[j]){
			cout<<punticard[j]<<endl;
		}
	}

    //richiede posizione e verifica che sia valida
	char dir='x';
    c=false;
    int p;
	while(c==false){
		cout<<"Scelga la direzione:";
		cin>>dir;
        for(int j=0;j<4;j++){
            if(punticard[j]==dir){
                if(direzioni[j]){
                    c=true;
                    p=j;
                }
                else{
                cout<<"Direzione non valida."<<endl;
                }
            }
        }
	}


    int l= (*ship)->Get_lunghezza();
    int range[16]={x,y-l+1,x,y,x,y,x+l-1,y,x,y,x,y+l-1,x-l+1,y,x,y};

    insert_in_cells(range[4*p],range[4*p+1],range[4*p+2],range[4*p+3], (*ship));

    (*ship)->Position();
    flotta->Aggiungi_Nave();
}

void Player::remove(int n_nave){
	vector<Nave*>::const_iterator ship=flotta->Flotta_begin()+n_nave;

    for(int i=(*ship)->Get_xmin();i<(*ship)->Get_xmax()+1;i++){
        for(int j=(*ship)->Get_ymin();j<(*ship)->Get_ymax()+1;j++){
            mappa->griglia[i][j].Get_occupazione()->Reposition();
            mappa->griglia[i][j].Set_occupazione(new Acqua());
        }
    }
    (*ship)->Set_xmin(0);
    (*ship)->Set_ymin(0);
    (*ship)->Set_xmax(0);
    (*ship)->Set_ymax(0);
    flotta->Rimuovi_Nave();
}

Flotta* Player::Get_Flotta(){
	return flotta;
}

Mappa* Player::Get_Mappa(){
    return mappa;
}

bool Player::shoot(){
    bool c=false;
    int x,y;
    cout<<"Capitano, e' ora di sparare, si ricordi che due navi possono essere adiacenti sulla mappa.\n";
    while(c==false){
        x=-2;
        y=-2;
        while(x<0 || x>=mappa->GetDim()){
            cout<<"Inserire la lettera (maiuscola) della colonna:"<<endl;
            char temp2;
            cin>>temp2;
            x=int(temp2)-int('A');
        }
        while(y<0 || y>=mappa->GetDim()){
            cout<<"Inserire il numero della riga:"<<endl;
            cin>>y;
            y--;
        }
        c = mappa->checkcolpo(x,y);
    }
    cout<<"\n--La mappa del nostro avversario--\n";
    mappa->Draw(false);

    if(mappa->griglia[x][y].Get_occupazione()->Get_lunghezza()!=0){
        if(mappa->griglia[x][y].Get_occupazione()->Check_affondata()){
            cout<<"Eccellente, capitano! abbiamo affondato una nave: "<<mappa->griglia[x][y].Get_occupazione()->Get_name()<<endl;
            flotta->Affonda_Nave();
            if(flotta->Check_affondata()){
                cout<<"I miei complimenti capitano, la flotta nemica e' stata affondata\n";
                return true;
            }

        }
    }
    return false;

}
