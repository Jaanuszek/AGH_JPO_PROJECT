#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using std::cout;
using std::endl;

class Player
{
private:
	float fAccountBalance{};
public:
	Player(float AccountBalance = 1000);

	float get_balace(void)const;
};
#endif 
