#ifndef NAVE_H
#define NAVE_H
#include<string>

using namespace std;

class Nave{
public:
    Nave();
	bool Check_affondata();
	void Position();
	void Reposition();
	std::string Get_name();
    void Set_name(string);
	int Get_ID();
    void Set_ID(int);
	int Get_lunghezza();
    void Set_lunghezza(int);
    void Colpito();
    void Set_xmin(int);
    void Set_xmax(int);
    void Set_ymin(int);
    void Set_ymax(int);
    int Get_xmin();
    int Get_xmax();
    int Get_ymin();
    int Get_ymax();
	bool Get_posizionata();

private:
	std::string name;
	int ID;
	int colpi;
	bool posizionata;
	bool affondata;
	int lunghezza;
    int xmin;
    int xmax;
    int ymin;
    int ymax;
};



#endif
