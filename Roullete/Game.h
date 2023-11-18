#pragma once
#include <string>
class Game
{
private:
	int fChoice{};
	float fbet{};
	char fMainChoice{};
	std::string fSideChoice{};
	std::string fCheck{};
	bool fisWin = 0;
public:
	Game()
	{}
	float get_bet(void)const {
		return fbet;
	}
	bool get_isWin(void) const {
		return fisWin;
	}
	char get_MainChoice(void)const {
		return fMainChoice;
	}
	void choice() { //wybor 
		std::cout << "1. Colour" << std::endl;
		std::cout << "2. Parity" << std::endl;
		std::cout << "3. Number" << std::endl;
		std::cout << "4. Quit" << std::endl;
		std::cin >> fMainChoice;
		switch (fMainChoice) {
		case '1': // tutaj mozna zrobic mape, zeby nie pisac 123 itp tylko zeby1 znaczylo kolory 2 parzystosc itp (1.1)
			std::cout << "Which colour? (Red, Black, Green)" << std::endl;
			std::cin >> fSideChoice;
			std::cout << "What is your bet? "<<std::endl;
			std::cin >> fbet;
			break;
		case '2':
			std::cout << "What parity? (Odd, Even)" << std::endl;
			std::cin >> fSideChoice;
			std::cout << "What is your bet? " << std::endl;
			std::cin >> fbet;
			break;
		case '3':
			std::cout << "What number?" << std::endl;
			std::cin >> fSideChoice;
			std::cout << "What is your bet? " << std::endl;
			std::cin >> fbet;
			break;
		case '4':
			exit(0);
		default:
			std::cout << "You did not make a decission" << std::endl;
			break;
		}
	}
	//int choiceBet() {
	//	int bet{};
	//	std::cout << "Insert your bet:";
	//	std::cin >> bet;
	//	if (!std::cin) {
	//		std::cout << "Invalid input." << std::endl;
	//	}
	//	return bet; // w tej metodzie jest cos nie tak, bo jak daje sie cos innego niz cyfre to program sie wykrzacza
	//}
	void checkAnswer(std::string result,int numResult) { //sprawdza czy gracz dobrze postawi³
		for (auto& i : fSideChoice) { //w razie gdyby ktos wpisal z duzych liter albo z malych i zeby nie wywalalo bledu
			i = tolower(i);
		}
		for (auto& n : result) { //w razie gdyby ktos wpisal z duzych liter albo z malych i zeby nie wywalalo bledu
			n = tolower(n);
		}
		int number = stoi(fSideChoice);//zeby zamienic string na int w przypadku wybrania liczby
		if(fSideChoice == "red" || fSideChoice == "black" || fSideChoice == "green") {
			if (result == fSideChoice) {
				std::cout << "Win!" << std::endl;
				fisWin = 1;
			}
			else {
				std::cout << "Try again!" << std::endl;
				fisWin = 0;
			}
		}
		else if (fSideChoice == "odd" || fSideChoice == "even") {
			if (result == fSideChoice) {
				std::cout << "Win!" << std::endl;
				fisWin = 1;
			}
			else {
				std::cout << "Try again!" << std::endl;
				fisWin = 0;
			}
		}
		else if (fMainChoice=='3') {
			if (numResult==number) {
				std::cout << "Win!" << std::endl;
				fisWin = 1;
			}
			else {
				std::cout << "Try again!" << std::endl;
				fisWin = 0;
			}
		}// dodac tutaj jeszcze warunek na te liczby
		else {
			std::cout << "Next time write proper answer!" << std::endl;
		}
	}
	void wait() {
		for (int i = 10; i >= 0;i--) {
			std::cout << "Time left: " << i << std::endl;
			Sleep(1000);
		}
	}
	std::string showPattern(std::string const col, int const number) {
		//std::vector<string> pattern;
		//pattern.push_back(col + std::to_string(number));
		//std::cout << "Patern: ";
		//for (auto znak : pattern) {
		//	std::cout << znak;
		//}
		//std::cout << std::endl;   //nie wiem dlaczego ale z vectorem to nie dziala, wrocic do tego!!!
		std::string pattern;
		pattern += col + " " + std::to_string(number)+ " ";
		//std::cout << "Pattern: " << pattern <<std::endl;
		return pattern;
	}
};

