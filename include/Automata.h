#pragma once
#include <string>
#include <iostream>

enum STATE {OFF, WAIT, ACCEPT, CHECK, COOK, ERROR};

class Automata
{
public:
	Automata()
	{
		cash = 0;
		state = OFF;
	}
	
	void on();
	void off();
	void coin(int money);
	void printMenu();
	void cancel();
	STATE printState();
	int getMoney();
	bool check();
	void cook();
	void choice(int choice);
	void finish();
	void cashback();
private:
	STATE state;
	int cash;
	int pos;
	int price[6] = { 20,30,35,25,40,50 };
	std::string menu[6] = { "apple","tomat","vinegar","pineapple","cucumber","potato" };
};
