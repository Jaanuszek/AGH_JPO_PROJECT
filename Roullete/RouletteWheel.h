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

class RouletteWheel //klasa odpowiadaj�ca za ko�o ruletki
{
private:
	int fNumber{};
	std::string fColour;
	bool fIsOdd;
	std::random_device rd;
	std::uniform_int_distribution<int> dist;
public:

	RouletteWheel(int number = 0, std::string colour = "", bool odd = 0, bool even = 0); // Konstruktor

	bool get_is_odd(void) const; // Zwraca warto�� fIsOdd, kt�ra sprawdza parzysto�� wylosowanej liczby
	
	int get_number(void) const; // Zwraca fNumber, zmienna zawiera wylosowany numer

	void randomNumber(); // Funkcja odpowiada za wylosowanie numeru od 0-36

	std::string isOdd(); //Funkcja sprawdzaj�ca parzysto�� liczby. Zwraca parzysto�� w formie napisu

	std::string color(); // Sprawdza jaki kolor sie kryje pod dan� liczb�, zwraca kolor w formie napisu

	void showNumber(void) const; // Wyswietla wylosowany numer
};
#endif

