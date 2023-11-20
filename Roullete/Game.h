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
	bool fisTimer = 1;
public:
	Game()
	{}
	float get_bet(void)const {
		return fbet;
	}
	bool get_isWin(void) const {
		return fisWin;
	}
	bool get_isTimer(void) const {
		return fisTimer;
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
				std::cout << "What is your bet? " << std::endl;
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
	void checkAnswer(std::string result,bool isOdd, int numResult) { //sprawdza czy gracz dobrze postawi³
		for (auto& i : fSideChoice) { //w razie gdyby ktos wpisal z duzych liter albo z malych i zeby nie wywalalo bledu
			i = tolower(i);
		}
		for (auto& n : result) { //w razie gdyby ktos wpisal z duzych liter albo z malych i zeby nie wywalalo bledu
			n = tolower(n);
		}
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
		else if (fSideChoice == "odd" || fSideChoice == "even") { // to chyba nie dziala
			bool checkParityAnswer;
			if (fSideChoice == "odd") {
				checkParityAnswer = 1;
			}
			else if (fSideChoice == "even") {
				checkParityAnswer = 0;
			}
			if (checkParityAnswer==isOdd) {
				std::cout << "Win!" << std::endl;
				fisWin = 1;
			}
			else {
				std::cout << "Try again!" << std::endl;
				fisWin = 0;
			}
		}
		else if (fMainChoice=='3') {
			int number = stoi(fSideChoice);//zeby zamienic string na int w przypadku wybrania liczby 
			if (numResult==number) {
				std::cout << "Win!" << std::endl;
				fisWin = 1;
			}
			else {
				std::cout << "Try again!" << std::endl;
				fisWin = 0;
			}
		}
		else {
			std::cout << "Next time write proper answer!" << std::endl;
		}
	}
	void wait() { //dodac obsluge w¹tków, by ten licznik sie wykonwal a uzytkownik mogl dalej sobie grac
		std::cout << "Time left: ";
		for (int i = 15; i >= 0;i--) {
			fisTimer = 1;
			if (i >= 10) { //tutaj jest robione, by ten timer dzialal w ten sposob ze zliacza czas w jednej lini
				std::cout << '\b';
				std::cout << '\b';
			}
			else if (i==9) {
				std::cout << '\b';
				std::cout << '\b';
				std::cout << " ";
			}
			else {
				std::cout << '\b';
			}
			std::cout << i;
			Sleep(1000);
		}
		fisTimer = 0;
		std::cout << std::endl;
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
		return pattern;
	}
	void stop(float balance) { //gdy gracz nie ma kredytow, gra sie konczy
		if (balance <= 0) {
			exit(EXIT_SUCCESS);
		}
	}
};

