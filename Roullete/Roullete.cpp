﻿// Roullete.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

//#include "RouletteWheel.h"
#include <iostream>
#include <random>
#include <windows.h>
#include "RouletteWheel.h"
#include "Bet.h"
#include "Game.h"
#include <string>
#include <vector>
#include "Player.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
//using namespace std;
int main()
{
	int num{},bet{};
	string color;
	float balance=1000;
	std::vector<string> pattern;
	std::random_device rd;
	std::uniform_int_distribution<int>  dist(0, 36);
	Game start; //Game.h
	Bet zaklad; //Bet.h
	
while (1) {
		Player account(balance); //sprawdza na biezaco ilosc kredytow i aktualizuje co kazde wywolanie petli
		start.stop(account.get_balace());
		//cout << "Account balace: " << account.get_balace() << endl;
		start.choice();
		//bet=start.choiceBet();
		num = dist(rd);
		RouletteWheel p(num);
		cout << "Parity: " << p.isOdd(num) << endl;;
		color = p.color(num);
		cout << color << endl;
		pattern.push_back(start.showPattern(color, num));
		cout << "Pattern: ";
		for (auto const& znak : pattern) {
			cout << znak;
		}
		cout << endl;
		start.checkAnswer(color,p.get_is_odd(), num); //tutaj nie ma wywolania czy liczba jest parzysta czy nie
		balance = zaklad.multiplier(start.get_MainChoice(), start.get_isWin(), account.get_balace(), start.get_bet());
		start.wait();
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
