#pragma once
class Game
{
private:
	int fChoice{};
	char fMainChoice{};
	std::string fSideChoice{};
	std::string fCheck{};
public:
	Game()
	{}
	void choice() {
		std::cout << "1. Colour" << std::endl;
		std::cout << "2. Parity" << std::endl;
		std::cout << "3. Number" << std::endl;
		std::cout << "4. Quit" << std::endl;
		std::cin >> fMainChoice;
		switch (fMainChoice) {
		case '1':
			std::cout << "Which colour? (Red, Black, Green)" << std::endl;
			std::cin >> fSideChoice;
			std::cout << "Your choice:" <<fSideChoice<< std::endl;
			break;
		case '2':
			std::cout << "What parity? (Odd, Even)" << std::endl;
			std::cin >> fSideChoice;
			std::cout << "Your choice:" << fSideChoice << std::endl;
			break;
		case '3':
			std::cout << "What number?" << std::endl;
			std::cin >> fSideChoice;
			std::cout << "Your choice:" << fSideChoice << std::endl;
			break;
		case '4':
			exit(0);
		default:
			std::cout << "You did not make a decission" << std::endl;
			break;
		}
	}
	void checkAnswer(std::string result) {
		if(fSideChoice == "Red" || fSideChoice == "Black" || fSideChoice == "Green") {
			if (result == fSideChoice) {
				std::cout << "Win!" << std::endl;
			}
			else {
				std::cout << "Try again!" << std::endl;
			}
		}
		if (fSideChoice == "Odd" || fSideChoice == "Even") {
			if (result == fSideChoice) {
				std::cout << "Win!" << std::endl;
			}
			else {
				std::cout << "Try again!" << std::endl;
			}
		}
	}
};

