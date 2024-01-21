#include "Game.h"


	Game::Game()
	{
		cout << "**********************************************************************" << endl;
		cout << "Welcome to roulette game!" << endl;
		cout << "Choose your bet please:" << endl;
		cout << "**********************************************************************" << endl;
	}
	float Game::get_bet(void)const {
		return fbet;
	}
	bool Game::get_isWin(void) const {
		return fisWin;
	}
	char Game::get_MainChoice(void)const {
		return fMainChoice;
	}
	string Game::get_SideChoice(void)const {
		return fSideChoice;
	}
	void Game::profitLoss(const float& balance) const{
		if (fisWin == 1) {
			cout << "(+" << balance << ")" << endl; 
		}
		else{
			cout << "(-" << fbet << ")"<<endl;
		}
	}
	void Game::choseBet(const float& balance) {
		cout << "What is your bet? " << endl;
		try {
			cin >> fbet;
			if (cin.fail()) { // iswdigit, bo zwykle isdigit jest do 255
				cin.clear();
				cin.ignore(10000, '\n');
				fErrorHandler = 1;
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
		system("CLS");
	}
	void Game::choice(const float& accBalance) { //wybor 
		fUserDecided = false;
		while (!fUserDecided) {
			cout << "1. Colour" << endl;
			cout << "2. Parity" << endl;
			cout << "3. Number" << endl;
			cout << "4. Quit" << endl;
			try{
				cin >> fMainChoice;
				if (fMainChoice == '1' || fMainChoice == '2' || fMainChoice == '3' || fMainChoice == '4') {
					fUserDecided = true;
				}
				else {
					throw "Wrong option!";
				}
			}
			catch(const char* choiceError){
				fErrorHandler = 1;
				fbet = 0;
				system("CLS");
				cerr << choiceError<<endl;
				break;
			}
		}
		if (fUserDecided) {
			switch (fMainChoice) {
			case '1':
				cout << "Which colour? (Red, Black, Green)" << endl;
				cout << "Type BACK to return to main menu"  << endl;
				cin >> fSideChoice;
				fSideChoice = lowerCase(fSideChoice);
				if (fSideChoice == "back") {
					fBack = 1;
					system("CLS");
					break;
				}
				choseBet(accBalance);
				break;
			case '2':
				cout << "What parity? (Odd, Even)" <<endl;
				cout << "Type BACK to return to main menu" << endl;
				cin >> fSideChoice;
				fSideChoice = lowerCase(fSideChoice);
				if (fSideChoice == "back") {
					fBack = 1;
					system("CLS");
					break;
				}
				choseBet(accBalance);
				break;
			case '3':
				cout << "What number?" << endl;
				cout << "Type BACK to return to main menu" << endl;
				cin >> fSideChoice;
				fSideChoice = lowerCase(fSideChoice);
				if (fSideChoice == "back") {
					fBack = 1;
					system("CLS");
					break;
				}
				choseBet(accBalance);
				break;
			case '4':
				exit(0);
			default:
				cout << "You did not make a decission" << endl;
				break;
			}
		}
	}
	void Game::checkAnswer(string result, bool isOdd, const int& numResult) { //sprawdza czy gracz dobrze postawi³
		result=lowerCase(result);
		if (fMainChoice == '1') {
			if (result == fSideChoice) {
				fisWin = 1;
				cout << "Win!";
			}
			else if (!fUserDecided||fErrorHandler==1) {
				fisWin = 0;
				fbet = 0; //w razie zlego wyboru nie pobiera kredytow
			}
			else if(fSideChoice== "red"|| fSideChoice == "black"|| fSideChoice == "green") {
				fisWin = 0;
				cout << "Try again!";
			}
			else {
				fisWin = 0;
				fbet = 0;
			}

		}
		else if (fMainChoice == '2') {
			if (fSideChoice != "back") {
				try {
					if (fSideChoice == "odd") {
						fcheckParityAnswer = 1;
					}
					else if (fSideChoice == "even") {
						fcheckParityAnswer = 0;
					}
					else {
						throw "This is not a proper answer";
					}
					if (fcheckParityAnswer == isOdd) {
						fisWin = 1;
						cout << "Win!";
					}
					else if (!fUserDecided || fErrorHandler == 1) {
						fisWin = 0;
						fbet = 0;
					}
					else {
						fisWin = 0;
						cout << "Try again!";
					}
				}
				catch (const char* exception) {
					cerr << exception <<endl;
					fbet = 0;
				}
			}
		}
		else if (fMainChoice == '3') {
			int number{};
			if (fSideChoice != "back") {
				try {
					int number = stoi(fSideChoice);//zeby zamienic string na int w przypadku wybrania liczby 
					if (number < 0 || number>36) {
						throw 123;
					}
					if (numResult == number) {
						fisWin = 1;
						cout << "Win!";
					}
					else if (!fUserDecided || fErrorHandler == 1) {
						fisWin = 0;
						fbet = 0;
					}
					else {
						fisWin = 0;
						cout << "Try again!";
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
				fbet = 0;
			}
		}
	}
	void Game::savePattern(const string& col, const int& number) {
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
	void Game::stop(const float& balance) { // Gdy gracz nie ma kredytow, gra sie konczy
		if (balance <= 0) {
			exit(EXIT_SUCCESS);
		}
	}

	string Game::lowerCase(string txt) {
		string newTxt;
		for (auto i : txt) { // W razie gdyby ktos wpisal z duzych liter albo z malych i zeby nie wyrzuca³o bledu
			i = tolower(i);
			newTxt += i;
		}
		return newTxt;
	}