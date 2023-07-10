#ifndef MAPPA_H

#define MAPPA_H

#include "Cella.cpp"

const int dim=10;

class Mappa {

public:
    Mappa();
    ~Mappa();
    void Draw(bool);
    int GetDim();
    bool checkcolpo(int, int);
    bool checknave(int, int, int, bool*);

    Cella** griglia;

private:
    static const int dimensione=dim;
    bool Scorri(int,int,int,int);
    

};


#endif
