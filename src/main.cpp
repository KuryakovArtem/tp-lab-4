#define _CRT_SECURE_NO_WARNINGS
#include "automata.h"
#include <iostream>

using namespace std;

int main()
{
	Automata automata;
	automata.on();
	automata.printMenu();
	automata.coin(50);
	automata.choice(2);
	automata.cook();
	automata.cashback();
	automata.cancel();
	automata.finish();
}