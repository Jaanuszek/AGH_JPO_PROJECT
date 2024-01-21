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
	Player(float AccountBalance = 1000); // Konstruktor wypisujacy stan konta gracza. Na pocz¹tku gry przypisuje graczowi 1000 kredytów

	float get_balace(void)const; // Zwraca wartoœæ fBalance, jest to iloœæ posiadanych przez gracza kredytów
};
#endif 
