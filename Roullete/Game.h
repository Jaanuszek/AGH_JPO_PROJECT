#pragma once
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
class Game
{
private:
	int fChoice{};
	int fDelayTime{};
	float fbet{};
	char fMainChoice{};
	std::string fSideChoice{};
	std::string fCheck{};
	bool fisWin = 0;
	bool fisTimer = 1;
	bool fUserDecided = 0;
	bool fcheckParityAnswer=0;
	bool fErrorHandler = 0;
public:
	Game(int delayTime = 10): fDelayTime{delayTime}
	{
		std::cout << "Welcome to roulette game!" << std::endl;
		std::cout << "Please make your decission in 5 sek" << std::endl;
	}
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
		fUserDecided = false;
		//start licznika czasu
		auto start_time = std::chrono::high_resolution_clock::now();
		//petla ktora sprawdza czy uzytkownik cos wpisal, jezeli nie to sprawdza czy uplyn¹³ czas, jezeli tak to petla sie przerywa
		while (!fUserDecided && std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count() < fDelayTime) {
			std::cout << "1. Colour" << std::endl;
			std::cout << "2. Parity" << std::endl;
			std::cout << "3. Number" << std::endl;
			std::cout << "4. Quit" << std::endl;
			std::cin >> fMainChoice; //problemem jest ten cin bo sie blokuje
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> dur = end - start_time;
			if (dur < std::chrono::seconds(fDelayTime)) { // sprawdza czy uzytkownik dokonal wyboru w ci¹gu 5 sekund, jezeli nie to wypisuje na ekranie ze nic nie wybral
				fUserDecided = true;
			}
		}
		if (fUserDecided) {
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
			//koniec licznika czasu
			auto end_time = std::chrono::high_resolution_clock::now();
			//jak dlugo zajelo podjecie decyzji graczu
			std::chrono::duration<double> duration = end_time - start_time;
			//opoznienie jakie nalezy dodac po wyborze gracza
			auto delay = std::chrono::seconds(fDelayTime) - duration;
			// zaokraglenie opoznienia by nie bylo liczb jak na przyklad 3,857483s
			delay = std::chrono::round<std::chrono::seconds>(delay);
			//petla ktora wypisuje pozostaly czas
			std::cout << "Time remaining:";
			while (delay > std::chrono::seconds(0)) {
				std::cout << delay << '\b'<<'\b';
				delay = delay - std::chrono::seconds(1);
				// funkcja sleep ktora opoznia petle o 1 sekunde
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			std::cout << '\n';
			system("CLS");
		}
		else if (!fUserDecided) {
				std::cout << "You did not type your choice in time!" << std::endl;
				fSideChoice = "";
				fbet = 0;
			}
		}
	void checkAnswer(std::string result,bool isOdd, int numResult) { //sprawdza czy gracz dobrze postawi³
		for (auto& i : fSideChoice) { //w razie gdyby ktos wpisal z duzych liter albo z malych i zeby nie wywalalo bledu
			i = tolower(i);
		}
		for (auto& n : result) { //w razie gdyby ktos wpisal z duzych liter albo z malych i zeby nie wywalalo bledu
			n = tolower(n);
		}
		//if(fSideChoice == "red" || fSideChoice == "black" || fSideChoice == "green") {
		if (fMainChoice=='1') {
			if (result == fSideChoice) {
				std::cout << "Win!" << std::endl;
				fisWin = 1;
			}
			else if (!fUserDecided) {
				fisWin = 0;
			}
			else {
				std::cout << "Try again!" << std::endl;
				fisWin = 0;
			}
			
		}
		//else if (fSideChoice == "odd" || fSideChoice == "even") { 
		else if (fMainChoice=='2') {
			if (fSideChoice == "odd") { //dodac obsluge bledow, ze jak sie wpisuje red w pole parity to wywaluje error
				fcheckParityAnswer = 1;
			}
			else if (fSideChoice == "even") {
				fcheckParityAnswer = 0;
			}
			else {
				std::cout << "This is not proper answer" << std::endl;
				fErrorHandler=1;
			}
			if (fcheckParityAnswer == isOdd) {
				std::cout << "Win!" << std::endl;
				fisWin = 1;
			}
			else if (!fUserDecided) {
				fisWin = 0;
			}
			else if (fErrorHandler=1) {
				fisWin = 0;
			}
			else {
				std::cout << "Try again!" << std::endl;
				fisWin = 0;
			}

		}
		else if (fMainChoice=='3') {
			// tutaj dodac try catch funkcje zeby obsluzyc blad gdyby uzytkownik zamiast liczby wpisal cos innego glupiego,. ale zostawie to bo na jpo tera to bedziemy miec
			int number = stoi(fSideChoice);//zeby zamienic string na int w przypadku wybrania liczby 
			if (numResult==number) { 
				std::cout << "Win!" << std::endl;
				fisWin = 1;
			}
			else if (!fUserDecided) {
				fisWin = 0;
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
	//chyba o to mozna usunac
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

