#pragma once
class RouletteWheel //klasa odpowiadaj¹ca za ko³o ruletki
{
private:
	int fNumber{};
	std::string fColour;
	bool fIsOdd;
public:
	bool get_is_odd(void) const {
		return fIsOdd;
	}
	RouletteWheel(int number = 0, std::string colour="", bool odd = 0, bool even = 0) : fNumber{number}, fColour{colour}, fIsOdd{odd}
	{
		std::cout << "The number drawn: " << number << std::endl;
	}
	std::string isOdd(const int number) {
		if (number % 2 == 1) {
			fIsOdd = 1;
			return "Odd";
		}
		if (number % 2 == 0) {
			fIsOdd = 0;
			return "Even";
		}
		else {
			return "0";
		}
	}
	std::string color(const int number) {
		std::vector <int> vRed = { 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36 };
		std::vector <int> vBlack = { 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 };
		auto findRed = find(vRed.begin(), vRed.end(), number);
		auto findBlack = find(vBlack.begin(), vBlack.end(), number);
		if (findRed != vRed.end()) {
			fColour = "Red";
			return fColour;
		}
		else if (findBlack != vBlack.end()) {
			fColour = "Black";
			return fColour;
		}
		else if (number == 0) {
			fColour = "Green";
			return fColour;
		}	
		else {
			return "Error";
		}
	}
};


