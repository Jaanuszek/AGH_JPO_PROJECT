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

	RouletteWheel(int number = 0, std::string colour = "", bool odd = 0, bool even = 0); // Konstruktor

	bool get_is_odd(void) const; // Zwraca wartoœæ fIsOdd, która sprawdza parzystoœæ wylosowanej liczby
	
	int get_number(void) const; // Zwraca fNumber, zmienna zawiera wylosowany numer

	void randomNumber(); // Funkcja odpowiada za wylosowanie numeru od 0-36

	std::string isOdd(); //Funkcja sprawdzaj¹ca parzystoœæ liczby. Zwraca parzystoœæ w formie napisu

	std::string color(); // Sprawdza jaki kolor sie kryje pod dan¹ liczb¹, zwraca kolor w formie napisu

	void showNumber(void) const; // Wyswietla wylosowany numer
};
#endif

