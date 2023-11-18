#pragma once
class Player
{
private:
	float fAccountBalance{};
public:
	Player(float AccountBalance=1000): fAccountBalance{AccountBalance}
	{}
	float get_balace(void)const {
		return fAccountBalance;
	}
};

