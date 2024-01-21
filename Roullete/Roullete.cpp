
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "RouletteWheel.h"
#include "Bet.h"
#include "Game.h"
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int num{},bet{};
	string color;
	float balance=1000;
	vector<string> pattern;
	std::fstream file("C:\\Users\\Kuba\\Desktop\\studia\\SEMESTR 5\\jpo\\JPO_project\\Roullete\\Money.txt");
	Game start; //Game.h
	Bet zaklad; //Bet.h
	RouletteWheel p;

	if (file.is_open()) {
		while (1) {
			file >> balance;
			Player account(balance); //sprawdza na biezaco ilosc kredytow i aktualizuje co kazde wywolanie petli
			start.stop(account.get_balace());
			start.choice(account.get_balace());
			p.randomNumber();
			num = p.get_number();
			p.showNumber();
			cout << "Parity: " << p.isOdd() << endl;;
			color = p.color();
			cout << color << endl;
			cout << "Pattern: ";
			start.savePattern(color, num); // zeby zapisac poprzedni los
			start.checkAnswer(color, p.get_is_odd(), num); //tutaj nie ma wywolania czy liczba jest parzysta czy nie
			balance = zaklad.multiplier(start.get_MainChoice(), start.get_SideChoice(), start.get_isWin(), account.get_balace(), start.get_bet());
			start.profitLoss(zaklad.get_result());
			file.seekg(0, std::ios::beg);
			file << "                                      "; //wyczyszczenie całej linii
			file.seekg(0, std::ios::beg); //przejscie do poczatku lini
			file << balance; //wpisanie wartości kredytów gracza do pliku
			file.close();
			file.open("C:\\Users\\Kuba\\Desktop\\studia\\SEMESTR 5\\jpo\\JPO_project\\Roullete\\Money.txt");
		}
		file.close();
	}
}
