#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <conio.h>

using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::vector;
using std::string;

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
	bool fUserDecided = 0;
	bool fcheckParityAnswer=0;
	bool fErrorHandler = 0;
	std::vector<std::string> fpattern;
public:
	Game(int delayTime = 10);
	float get_bet(void)const;
	bool get_isWin(void) const;
	char get_MainChoice(void)const;
	std::string get_SideChoice(void)const;
	void profitLoss(const float& balance) const;
	void choseBet(const float& balance);
	void choice(const float& accBalance);
	void checkAnswer(std::string result, bool isOdd, const int& numResult);
	void savePattern(const std::string& col, const int& number);
	void stop(const float& balance);
};
#endif
