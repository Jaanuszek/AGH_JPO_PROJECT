#include "RouletteWheel.h"



RouletteWheel::RouletteWheel(int number, string colour, bool odd, bool even) : fNumber{ number }, fColour{ colour }, fIsOdd{ odd }, dist(0,36)
{}
bool RouletteWheel::get_is_odd(void) const {
	return fIsOdd;
}

int RouletteWheel::get_number(void) const {
	return fNumber;
}

void RouletteWheel::randomNumber() {
	fNumber = dist(rd);
}

string RouletteWheel::isOdd() {
	if (fNumber % 2 == 1) {
		fIsOdd = 1;
		return "Odd";
	}
	if (fNumber % 2 == 0) {
		fIsOdd = 0;
		return "Even";
	}
	else {
		return "0";
	}
}
string RouletteWheel::color() {
	vector <int> vRed = { 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36 };
	vector <int> vBlack = { 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 };
	auto findRed = find(vRed.begin(), vRed.end(), fNumber);
	auto findBlack = find(vBlack.begin(), vBlack.end(), fNumber);
	if (findRed != vRed.end()) {
		fColour = "Red";
		return fColour;
	}
	else if (findBlack != vBlack.end()) {
		fColour = "Black";
		return fColour;
	}
	else if (fNumber == 0) {
		fColour = "Green";
		return fColour;
	}
	else {
		return "Error";
	}
}

 void RouletteWheel::showNumber(void) const{
	cout << "Number Drawn: " << fNumber << endl;
}
