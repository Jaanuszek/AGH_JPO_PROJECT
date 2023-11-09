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

using std::cout;
using std::cin;
using std::endl;
using std::string;
//using namespace std;
int main()
{
	int num{};
	string pattern, color;
	std::random_device rd;
	std::uniform_int_distribution<int>  dist(0, 36);
	Game start;
	while (1) {
		start.choice();
		cout << "Pattern: " << pattern <<endl;
		num = dist(rd);
		RouletteWheel p(num);
		cout << "Parity: " << p.isOdd(num) << endl;;
		color = p.color(num);
		cout << color << endl;
		pattern += p.color(num) + " " +std::to_string(num);
		start.checkAnswer(color);
		for (int i = 10; i >=0;i--) {
			cout << "Time left: " << i << endl;
			Sleep(1000);
		}
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
