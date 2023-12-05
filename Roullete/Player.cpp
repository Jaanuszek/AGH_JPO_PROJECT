#include "Player.h"


Player::Player(float AccountBalance) : fAccountBalance{AccountBalance}
	{
		if (fAccountBalance > 0) {
			cout << "Account balace: " << fAccountBalance << endl;
		}
		else {
			cout << "You've lose all your money!" << endl;
		}
	}

float Player::get_balace(void)const {
	return fAccountBalance;
}