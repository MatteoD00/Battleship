#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Client.cpp"

using namespace std;


int main(){


    cout<<"---BATTAGLIA NAVALE---\n\n\n";
    cout<<"Benvenuti capitani\nVolete conoscere le regole del gioco? (Y/N)\n";
    char input;
    cin>>input;

    if(input=='Y'){
        ifstream rules;
        string line;
        rules.open("Rules.txt");
        if (rules.is_open()){
            while ( getline (rules,line) ){
                cout << line << '\n';
            }
            rules.close();
        }
        char temp;
            cout<<"Premere un tasto qualsiasi per continuare:\n";
            cin>>temp;
    }

    Client client;
    int next=client.setgame();
    if(next==1){
        cout<<"Il giocatore 1 ha abbandonato, vince il giocatore 2\n";
        return 0;
    }
    else if(next==2){
        cout<<"Il giocatore 2 ha abbandonato, vince il giocatore 1\n";
        return 0;
    }
    else if(next==0){
        next=client.playgame();
        if(next==0){
            cout<<"\nVince il giocatore 1\n";
            return 0;
        }
        else if(next==1){
            cout<<"\nVince il giocatore 2\n";
            return 0;
        }
        return 10;
    }


    return 11;
}
