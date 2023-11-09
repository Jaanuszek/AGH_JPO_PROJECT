#pragma once
class Bet
{
private:
	int fBet{}; // ile pieniedzy zostalo postawione
	int fChoice;
public:
	Bet(int bet = 0, int choice = 0) : fBet{ bet }, fChoice(choice)
	{}

};

