#include "Client.h"
#include "Player.cpp"
#include<vector>
#include<iostream>
using std::vector;
using std::cout;
using std::cin;
using std::endl;



Client::~Client(){
    delete player[0];
    delete player[1];
}

int Client::setgame(){
    cout<<"Fase di posizionamento della flotta\n";
	for(int j=0; j<2; j++){
		player[j]=new Player(j);
		cout<<"Turno del giocatore "<<j+1<<endl;
		bool c=false;
		int n;
		vector<Nave*>::const_iterator ship;

        player[j]->Get_Mappa()->Draw(true);

        cout<<"Capitano, ecco l'elenco delle navi a sua disposizione:\n";

		while(c==false){
			for(ship=player[j]->Get_Flotta()->Flotta_begin(); ship!=player[j]->Get_Flotta()->Flotta_end(); ship++){
				cout<<(*ship)->Get_ID()<<": "<<setfill(' ')<<setw(12)<<left<<(*ship)->Get_name()<<"| lunghezza:"<<(*ship)->Get_lunghezza()<<" | posizionata:"<<((*ship)->Get_posizionata()? "si" : "no")<<endl;
			}
			n=-1;
			while(n<0 or n>(player[j]->Get_Flotta()->Get_NaviTotali())){
				cout<<"Capitano, scelga la nave da posizionare:\n"<<endl;
				char temp;
				cin>>temp;
				n=int(temp)-int('1');
			}
			ship=player[j]->Get_Flotta()->Flotta_begin()+n;
			cout<<"Ha selezionato: "<<(*ship)->Get_name()<<endl;
			if((*ship)->Get_posizionata()==false){
			player[j]->position(n);
            cout<<"La nave e' stata posizionata\n"<<endl;
			}
			else{
				cout<<"La nave e' gia' stata posizionata, vuole rimuoverla? (Y/N)\n"<<endl;
				char input;
				cin>>input;
				if(input=='Y'){
					player[j]->remove(n);
					cout<<"La nave e' stata rimossa, ora puo' riposizionarla\n"<<endl;
				}
				else{
					cout<<"La nave non e' stata rimossa\n"<<endl;
				}
            }

            player[j]->Get_Mappa()->Draw(true);

            if(player[j]->Get_Flotta()->Get_NaviTotali()== player[j]->Get_Flotta()->Get_NumeroPosizionate()){
                cout<<"Ha finito di posizionare le navi? (Y/N)\n"<<endl;
                char input;
                cin>>input;
                if(input=='Y'){
                    c=true;
                }
            }
            else{
                char temp;
                cout<<"Per abbandonare premere 'q' altrimenti premere un tasto qualsiasi per continuare.\n";
                cin>>temp;
                if(temp=='q'){
                    return (j+1)%3;
                }
            }



		}
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}



   return 0;
}


int Client::playgame(){
    bool endgame;
    char temp;
    while(true){
        for(int j=0; j<2; j++){
            cout<<"\n\nTurno del giocatore "<<j+1<<endl;
            cout<<"Giocatore "<<(j+1)<<", quando sei pronto premi un tasto qualunque\n";
            cin>>temp;
            cout<<"\n--La tua mappa--\n";
            player[j]->Get_Mappa()->Draw(true);
            cout<<"\n--La mappa del nostro avversario--\n";
            player[((j+1) % 2)]->Get_Mappa()->Draw(false);

            endgame=player[((j+1) % 2)]->shoot();



            if(endgame){
                return j;
            }

            char temp;
            cout<<"Per abbandonare premere 'q' altrimenti premere un tasto qualsiasi per continuare. dopo sara' il turno del giocatore "<<(j+2)%3<<"\n";
            cin>>temp;
            if(temp=='q'){
                return (j+1)%2;
            }

            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        }
    }
}
