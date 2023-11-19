#pragma once
class Player
{
private:
	float fAccountBalance{};
public:
	Player(float AccountBalance=1000): fAccountBalance{AccountBalance}
	{
		if (fAccountBalance > 0) {
			std::cout << "Account balace: " << fAccountBalance << std::endl;
		}
		else {
			std::cout << "You lose all your money!" << std::endl;
		}

	}
	float get_balace(void)const {
		return fAccountBalance;
	}
};

