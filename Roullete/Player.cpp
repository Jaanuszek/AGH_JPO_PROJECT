#include "Player.h"
#include <iostream>


Player::Player(float AccountBalance) : fAccountBalance{AccountBalance}
	{
		if (fAccountBalance > 0) {
			std::cout << "Account balace: " << fAccountBalance << std::endl;
		}
		else {
			std::cout << "You've lose all your money!" << std::endl;
		}
	}

float Player::get_balace(void)const {
	return fAccountBalance;
}