#pragma once
class Player
{
private:
	float fAccountBalance{};
public:
	Player(float AccountBalance = 1000);

	float get_balace(void)const;
};

