// Roullete.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

//#include "RouletteWheel.h"
#include <iostream>
//#include <random>
//#include <windows.h>
#include "RouletteWheel.h"
#include "Bet.h"
#include "Game.h"
#include <string>
#include <vector>
#include "Player.h"
//#include <chrono>
//#include <thread>
//#include <limits>

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
	Game start(5); //Game.h
	Bet zaklad; //Bet.h
	RouletteWheel p;

	
while (1) {
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
		start.savePattern(color, num); // zeby zapisac poprzedni lo
		start.checkAnswer(color, p.get_is_odd(), num,account.get_balace()); //tutaj nie ma wywolania czy liczba jest parzysta czy nie
		balance = zaklad.multiplier(start.get_MainChoice(),start.get_SideChoice(), start.get_isWin(), account.get_balace(), start.get_bet());
		//zrobic funkcje ktora wypisuje wybor gracza !!!!!!!!!
		//zrobic zeby to ladniej wygladalo, ale nie mam pojecia jak do tego sie zabrac
	}
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
