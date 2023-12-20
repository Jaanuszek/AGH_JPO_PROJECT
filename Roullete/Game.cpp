#include "Game.h"


	Game::Game(int delayTime) : fDelayTime{ delayTime }
	{
		cout << "**********************************************************************" << endl;
		cout << "Welcome to roulette game!" << endl;
		cout << "Please make your decission in 5 sek" << endl;
		cout << "**********************************************************************" << endl;
	}
	float Game::get_bet(void)const {
		return fbet;
	}
	bool Game::get_isWin(void) const {
		return fisWin;
	}
	bool Game::get_isTimer(void) const {
		return fisTimer;
	}
	char Game::get_MainChoice(void)const {
		return fMainChoice;

	}
	string Game::get_SideChoice(void)const {
		return fSideChoice;
	}
	void Game::profitLoss(float balance) {
		if (fisWin == 1) {
			// bo na pocz¹tku zmienna result ma wartosc 0 i jak sie wygra to sie wyswietla ze sie wygralo 0 dlatego to zabezpiecza przed tym zjawiskiem
			cout << "(+" << foldBalance-balance << ")" << endl; 
		}
		else {
			cout << "(-" << fbet << ")"<<endl;
		}
	}
	void Game::choseBet(float balance) {
		foldBalance = balance; // zrobic tak zeby sie zapisywala do tej zmiennej ilosc kredytow ile bylo przed postawieniem beta !!!!!!!!!!!!!!!!!!
		cout << "What is your bet? " << endl;
		try {
			cin >> fbet;
			if (cin.fail()) { // iswdigit, bo zwykle isdigit jest do 255
				cin.clear();
				cin.ignore(10000, '\n');
				throw 125;
			}
			if (fbet > balance) {
				throw "You do not have this ammount of money!";
			}
			else {
				fErrorHandler = 0;
			}
		}
		catch (int betErr) {
			fErrorHandler = 1;
			fbet = 0;
			cout << "This is wrong bet!! " << "Error type: " << betErr << endl;
		}
		catch (const char* ex) {
			fErrorHandler = 1;
			fbet = 0;
			cerr << ex << endl;
		}
	}
	void Game::choice(float accBalance) { //wybor 
		fUserDecided = false;
		//start licznika czasu
		auto start_time = std::chrono::high_resolution_clock::now();
		//petla ktora sprawdza czy uzytkownik cos wpisal, jezeli nie to sprawdza czy uplyn¹³ czas, jezeli tak to petla sie przerywa
		while (!fUserDecided && std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count() < fDelayTime) {
			cout << "1. Colour" << endl;
			cout << "2. Parity" << endl;
			cout << "3. Number" << endl;
			cout << "4. Quit" << endl;
			cin >> fMainChoice; //problemem jest ten cin bo sie blokuje
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> dur = end - start_time;
			if (dur < std::chrono::seconds(fDelayTime)) { // sprawdza czy uzytkownik dokonal wyboru w ci¹gu 5 sekund, jezeli nie to wypisuje na ekranie ze nic nie wybral
				fUserDecided = true;
			}
		}
		if (fUserDecided) {
			switch (fMainChoice) {
			case '1':
				cout << "Which colour? (Red, Black, Green)" << endl;
				cin >> fSideChoice;
				choseBet(accBalance);
				break;
			case '2':
				cout << "What parity? (Odd, Even)" <<endl;
				cin >> fSideChoice;
				choseBet(accBalance);
				break;
			case '3':
				cout << "What number?" << endl;
				cin >> fSideChoice;
				choseBet(accBalance);
				break;
			case '4':
				exit(0);
			default:
				cout << "You did not make a decission" << endl;
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
			cout << "Time remaining:";
			while (delay > std::chrono::seconds(0)) {
				cout << delay << '\b' << '\b';
				delay = delay - std::chrono::seconds(1);
				// funkcja sleep ktora opoznia petle o 1 sekunde
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
			cout << '\n';
			system("CLS");
		}
		else if (!fUserDecided) {
			cout << "You did not type your choice in time!" << endl;
			fSideChoice = "";
			fbet = 0;
		}
	}
	void Game::checkAnswer(string result, bool isOdd, int numResult, float balance ) { //sprawdza czy gracz dobrze postawi³
		for (auto& i : fSideChoice) { //w razie gdyby ktos wpisal z duzych liter albo z malych i zeby nie wywalalo bledu
			i = tolower(i);
		}
		for (auto& n : result) { //w razie gdyby ktos wpisal z duzych liter albo z malych i zeby nie wywalalo bledu
			n = tolower(n);
		}
		if (fMainChoice == '1') {
			if (result == fSideChoice) {
				fisWin = 1;
				cout << "Win!";
				profitLoss(balance);
			}
			else if (!fUserDecided||fErrorHandler==1) {
				fisWin = 0;
				fbet = 0; //w razie zlego wyboru nie pobiera kredytow
			}
			else if(fSideChoice== "red"|| fSideChoice == "black"|| fSideChoice == "green") {
				fisWin = 0;
				cout << "Try again!";
				profitLoss(balance);
			}
			else {
				fisWin = 0;
				fbet = 0;
			}

		}
		else if (fMainChoice == '2') {
			try {
				if (fSideChoice == "odd") { //dodac obsluge bledow, ze jak sie wpisuje red w pole parity to wywaluje error
					fcheckParityAnswer = 1;
				}
				else if (fSideChoice == "even") {
					fcheckParityAnswer = 0;
				}
				else {
					throw 124;
				}
				if (fcheckParityAnswer == isOdd) {
					fisWin = 1;
					cout << "Win!";
					profitLoss(balance);
				}
				else if (!fUserDecided || fErrorHandler == 1) {
					fisWin = 0;
					fbet = 0;
				}
				else {
					fisWin = 0;
					cout << "Try again!";
					profitLoss(balance);
				}
			}
			catch (int parityError) {
				cout << "This is not proper answer" << " Error type:" << parityError << endl;
				fbet = 0;
			}
		}
		else if (fMainChoice == '3') {
			// tutaj dodac try catch funkcje zeby obsluzyc blad gdyby uzytkownik zamiast liczby wpisal cos innego glupiego,. ale zostawie to bo na jpo tera to bedziemy miec
			int number{};
			try {
				int number = stoi(fSideChoice);//zeby zamienic string na int w przypadku wybrania liczby 
				if (number < 0 || number>36) {
					throw 123;
				}
				if (numResult == number) {
					fisWin = 1;
					cout << "Win!";
					profitLoss(balance);
				}
				else if (!fUserDecided || fErrorHandler == 1) {
					fisWin = 0;
					fbet = 0;
				}
				else {
					fisWin = 0;
					cout << "Try again!";
					profitLoss(balance);
				}
			}
			catch (const std::invalid_argument& ia) {
				cerr << "Invalid argument: " << ia.what() << endl;
				fbet = 0;
			}
			catch (const std::out_of_range& oor) {
				cerr << "Out of Range error:" << oor.what() << endl;
				fbet = 0;
			}
			catch (int rangeErr) {
				cout << "The number is out of range (0-36)" << "Error type:" << rangeErr << endl;
				fisWin = 0;
				fbet = 0;
			}
		}
		else {
			cout << "Next time write proper answer!" << endl;
		}
	}
	void Game::savePattern(string const col, int const number) {
		string pattern;
		pattern += col + " " + std::to_string(number) + " ";
		fpattern.push_back(pattern);
		if (fpattern.size() > 4) {
			fpattern.erase(fpattern.begin());
		}
		for (auto const& i : fpattern) {
			cout << i;
		}
		cout << endl;
	}
	void Game::stop(float balance) { //gdy gracz nie ma kredytow, gra sie konczy
		if (balance <= 0) {
			exit(EXIT_SUCCESS);
		}
	}