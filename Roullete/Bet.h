#pragma once
class Bet
{
private:
	//int fBet{}; // ile pieniedzy zostalo postawione
	//int fChoice;
public:
	Bet()
	{}
	float multiplier(char mainChoice, bool isWin, float balance, float betValue) {
	
		float result{};
		if (mainChoice=='1' && isWin==1) { // adnotacja (1.1) w game.h
			result = betValue * 2;//mnoznik 2 w przypadku kolorow
			return balance += result;
		}
		else {
			return balance = balance - betValue; 	//odjecie wartosci betu z jego kredytów przed poznaniem wynikow
		}
		if (mainChoice=='2' && isWin==1) {
			result = betValue * 2;//mnoznik 2 w przypadku parzystosci
			return balance += result;
		}
		else {
			return balance = balance - betValue;
		}
		if (mainChoice='3' && isWin==1) { //sprawdzic czy to dziala
			result = betValue * 10;//mnoznik 10 w przypadku wybrania dobrej liczby
			return balance += result;
		}
		else {
			return balance = balance - betValue;
		}
	}
};

