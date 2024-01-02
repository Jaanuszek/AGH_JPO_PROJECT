#ifndef ROULETTEWHEEL_H
#define ROULETTEWHEEL_H

#include <iostream>
#include <string>
#include <vector>
#include <random>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class RouletteWheel //klasa odpowiadaj¹ca za ko³o ruletki
{
private:
	int fNumber{};
	std::string fColour;
	bool fIsOdd;
	std::random_device rd;
	std::uniform_int_distribution<int> dist;
public:

	RouletteWheel(int number = 0, std::string colour = "", bool odd = 0, bool even = 0);

	bool get_is_odd(void) const;
	
	int get_number(void) const;

	void randomNumber();

	std::string isOdd();

	std::string color();

	void showNumber(void) const;
};
#endif

