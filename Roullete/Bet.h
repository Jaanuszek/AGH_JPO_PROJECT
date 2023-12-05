#ifndef BET_H// jesli nie istnieje zmienna BET_H to wykonaj blok
#define BET_H //tworzy zmienn¹ o nazwie BET_H

#include <string>

using std::string;

class Bet
{
private:
public:
	Bet()
	{}
	float multiplier(char mainChoice, std::string sideChoice, bool isWin, float balance, float betValue);
};
#endif //koniec bloku warunkowego
