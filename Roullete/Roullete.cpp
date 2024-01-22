
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
	int num{};
	string color;
	float balance=1000;
	vector<string> pattern;
	std::fstream file("C:\\Users\\Kuba\\Desktop\\studia\\SEMESTR 5\\jpo\\JPO_project\\Roullete\\Money.txt");
	Game start; //Game.h
	Bet zaklad; //Bet.h
	RouletteWheel p;

	if (file.is_open()) { // Jezeli plik jest prawidlowo otwarty to wykonuje petle
		while (1) {
			file >> balance; // Wczytanie wartosci stanu konta z pliku
			Player account(balance); // Sprawdza na biezaco ilosc kredytow i aktualizuje co kazde wywolanie petli
			start.stop(account.get_balace()); // Sprawdza czy gracz ma jeszcze kredyty, jezeli nie, to przerywa grę
			start.choice(account.get_balace());
			num = p.randomNumber(); // Losowanie numeru
			p.showNumber(); // Wypisanie numeru na ekranie
			cout << "Parity: " << p.isOdd() << endl; // Wypisanie parzystości na ekranie
			color = p.color(); // Przypisanie zmiennej color, wylosowanego koloru
			cout << color << endl; // Wypisanie na ekranie koloru
			cout << "Pattern: ";
			start.savePattern(color, num); // Wypisanie na ekranie patternu
			start.checkAnswer(color, p.get_is_odd(), num); // Sprawdza czy zakład jest wygrany czy przegrany
			balance = zaklad.multiplier(start.get_MainChoice(), start.get_SideChoice(), start.get_isWin(), account.get_balace(), start.get_bet());
			start.profitLoss(zaklad.get_result()); // Wypisuje wartość wygranej/przegranej
			file.seekg(0, std::ios::beg); // Przejscie do poczatku lini
			file << "                                      "; // Wyczyszczenie całej linii
			file.seekg(0, std::ios::beg); // Przejscie do poczatku lini
			file << balance; // Wpisanie wartości kredytów gracza do pliku
			file.close(); // Zamkniecie pliku do zapisu
			file.open("C:\\Users\\Kuba\\Desktop\\studia\\SEMESTR 5\\jpo\\JPO_project\\Roullete\\Money.txt"); // Otwarcie pliku do oczytu
		}
		file.close();
	}
}
