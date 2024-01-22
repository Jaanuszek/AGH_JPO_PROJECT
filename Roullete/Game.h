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
	Game(); // Konstruktor wyswietlaj�cy ekran powitalny
	float get_bet(void)const; // Zwraca zmienn� fbet, kt�ra zawiera wysoko�� zak��du
	bool get_isWin(void) const; // Zwraca zmienn� fisWin, kt�ra informuje czy zak�ad jest wygrany czy przegrany
	char get_MainChoice(void)const; // Zwraca zmienn� fMainChoice, kt�ra m�wi o wyborze gracza (kolor, parzystosc, numer)
	std::string get_SideChoice(void)const; // Zwraca zmienn� fSideChoice, kt�ra m�wi o bardziej dok�adnym wyborze gracza (konkretny kolor, konkretna parzystosc, konkretna liczba)
	void profitLoss(const float& balance) const; // Funkcja wypisuj�ca na ekranie warto�� wygranego b�d� przegranego zak�adu
	void choseBet(const float& balance); // Funkcja pozwalaj�ca u�ytkownikowi wybra� wysoko�� zak�adu. Zawiera obs�uge b��d�w
	void choice(const float& accBalance); // Funkcja odpowiadaj�ca za mozliwosc wyboru 
	void checkAnswer(std::string result, bool isOdd, const int& numResult); // Funkcja sprawdzaj�ca czy wyb�r gracza pokrywa sie z wylosowan� liczb�/kolorem/parzysto�ci�
	void savePattern(const std::string& col, const int& number); // Funkcja zapisuje do wektora wartosci poprzednich los�w, i wyswietla je na ekranie
	void stop(const float& balance); // Funkcja odpowiadaj�ca za przerwanie gry w momencie gdy gracz ju� nie ma kredyt�w
	string lowerCase(string txt); // Zwraca zmienn� typu string z samymi ma�ymi literami
};
#endif
