#pragma once
class Bet
{
private:
public:
	Bet()
	{}
	float multiplier(char mainChoice,std::string sideChoice, bool isWin, float balance, float betValue) {
	
		float result{};
		if (mainChoice=='1' && isWin==1) {
			if (sideChoice == "green"){
				result = betValue * 35;//mnoznik 2 w przypadku zielonego koloru
				return balance += result;
			}
			else {
				result = betValue * 2;//mnoznik 2 w przypadku kolorow
				return balance += result;
			}
		}
		else if (mainChoice=='2' && isWin==1) {
			result = betValue * 2;//mnoznik 2 w przypadku parzystosci
			return balance += result;
		}
		else if (mainChoice='3' && isWin==1) { //sprawdzic czy to dziala
			result = betValue * 10;//mnoznik 35 w przypadku wybrania dobrej liczby
			return balance += result;
		}
		else {
			return balance = balance - betValue;
		}
	}
};

