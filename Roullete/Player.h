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
	Player(float AccountBalance = 1000); // Konstruktor wypisujacy stan konta gracza. Na pocz�tku gry przypisuje graczowi 1000 kredyt�w

	float get_balace(void)const; // Zwraca warto�� fBalance, jest to ilo�� posiadanych przez gracza kredyt�w
};
#endif 
