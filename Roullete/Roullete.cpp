
#include <iostream>
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
		start.savePattern(color, num); // zeby zapisac poprzedni los
		start.checkAnswer(color, p.get_is_odd(), num); //tutaj nie ma wywolania czy liczba jest parzysta czy nie
		balance = zaklad.multiplier(start.get_MainChoice(),start.get_SideChoice(), start.get_isWin(), account.get_balace(), start.get_bet());
		start.profitLoss(zaklad.get_result());
	}
}
