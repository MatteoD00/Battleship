#ifndef CLIENT_H
#define CLIENT_H
#include "Player.h"
#include<vector>
using std::vector;

class Client{
public:
	int setgame();
	int playgame();
	~Client();
private:
	Player* player[2];

};
#endif
