#include "Bet.h"

float Bet::get_result() {
	return fresult;
}

float Bet::multiplier(char mainChoice, string sideChoice, bool isWin, float balance, float betValue) {

	if (mainChoice == '1' && isWin == 1) {
		if (sideChoice == "green") {
			fresult = betValue * 35;//mnoznik 2 w przypadku zielonego koloru
			return balance += fresult;
		}
		else {
			fresult = betValue * 2;//mnoznik 2 w przypadku kolorow
			return balance += fresult;
		}
	}
	else if (mainChoice == '2' && isWin == 1) {
		fresult = betValue * 2;//mnoznik 2 w przypadku parzystosci
		return balance += fresult;
	}
	else if (mainChoice = '3' && isWin == 1) { //sprawdzic czy to dziala
		fresult = betValue * 10;//mnoznik 35 w przypadku wybrania dobrej liczby
		return balance += fresult;
	}
	else {
		return balance = balance - betValue;
	}
}

