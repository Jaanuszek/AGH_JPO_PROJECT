#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::vector;
using std::string;

class Game
{
private:
	int fChoice{};
	float fbet{};
	char fMainChoice{};
	std::string fSideChoice{};
	bool fisWin = 0;
	bool fUserDecided = 0;
	bool fcheckParityAnswer=0;
	bool fErrorHandler = 0;
	bool fBack = 0;
	std::vector<std::string> fpattern;
public:
	Game(); // Konstruktor wyswietlaj¹cy ekran powitalny
	float get_bet(void)const; // Zwraca zmienn¹ fbet, która zawiera wysokoœæ zak³¹du
	bool get_isWin(void) const; // Zwraca zmienn¹ fisWin, która informuje czy zak³ad jest wygrany czy przegrany
	char get_MainChoice(void)const; // Zwraca zmienn¹ fMainChoice, która mówi o wyborze gracza (kolor, parzystosc, numer)
	std::string get_SideChoice(void)const; // Zwraca zmienn¹ fSideChoice, która mówi o bardziej dok³adnym wyborze gracza (konkretny kolor, konkretna parzystosc, konkretna liczba)
	void profitLoss(const float& balance) const; // Funkcja wypisuj¹ca na ekranie wartoœæ wygranego b¹dŸ przegranego zak³adu
	void choseBet(const float& balance); // Funkcja pozwalaj¹ca u¿ytkownikowi wybraæ wysokoœæ zak³adu. Zawiera obs³uge b³êdów
	void choice(const float& accBalance); // Funkcja odpowiadaj¹ca za mozliwosc wyboru 
	void checkAnswer(std::string result, bool isOdd, const int& numResult); // Funkcja sprawdzaj¹ca czy wybór gracza pokrywa sie z wylosowan¹ liczb¹/kolorem/parzystoœci¹
	void savePattern(const std::string& col, const int& number); // Funkcja zapisuje do wektora wartosci poprzednich losów, i wyswietla je na ekranie
	void stop(const float& balance); // Funkcja odpowiadaj¹ca za przerwanie gry w momencie gdy gracz ju¿ nie ma kredytów
	string lowerCase(string txt); // Zwraca zmienn¹ typu string z samymi ma³ymi literami
};
#endif
