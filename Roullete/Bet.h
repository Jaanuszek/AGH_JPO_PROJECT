#ifndef BET_H// jesli nie istnieje zmienna BET_H to wykonaj blok
#define BET_H //tworzy zmienn¹ o nazwie BET_H

#include <string>

using std::string;

class Bet
{
private:
	float fresult{};
public:
	Bet()
	{}
	float get_result(void) const; // Funkcja zwracaj¹ca zmienn¹ fresult bêd¹c¹ wartoœci¹ wygranej po zastosowaniu mno¿nika
	// Funkcja zwracaj¹ca bilans kredytów po wygranej/przegranej
	float multiplier(const char& mainChoice, const std::string& sideChoice, const bool& isWin, float balance, const float& betValue);
};
#endif //koniec bloku warunkowego
