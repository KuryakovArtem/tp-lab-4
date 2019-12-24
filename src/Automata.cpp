#include "automata.h"
#include <string>


void Automata::on()
{
	state = WAIT;
	std::cout << "Working process began! " << std::endl;
}

void Automata::off() 
{
	std::cout << "Shut down! " << std::endl;
	state = OFF;
	cancel();
}

void Automata::coin(int money)
{
	if (state == ACCEPT || state == WAIT || state == CHECK)
	{
		state = ACCEPT;
		cash += money;
		std::cout << "Balance: " << getMoney() << std::endl;
	}
	else state = ERROR;
}

void Automata::printMenu()
{
	for (int i = 0; i < 6; i++)
	{
		std::cout << i + 1 <<" "<< menu[i] << "juice " << price[i] << std::endl;
	}
}

void Automata::cancel()
{
	cashback();
	state = WAIT;
}

STATE Automata::printState()
{
	switch (state)
	{
	case OFF:
		std::cout << "Turn on the mashine!!! " << std::endl;
		return OFF;		
	case WAIT:
		std::cout << "Cooking! Wait a little.. " << std::endl;
		return WAIT;
	case ACCEPT:
		std::cout << "Continue... " << std::endl;
		return ACCEPT;
	case CHECK:
		std::cout << "Counting... " << std::endl;
		return CHECK;
	case COOK:
		std::cout << "Cooking... " << std::endl;
		return COOK;
	default:
		std::cout << "ERROR! " << std::endl;
		return ERROR;
	}
}

int Automata::getMoney()
{
	return cash;
}

bool Automata::check()
{
	return(cash >= price[pos] ? 1 : 0);
}

void Automata::cook()
{
	if (state == CHECK || state == ACCEPT)
	{
		if (check())
		{
			cash -= price[pos];
			state = COOK;
		}
		else std::cout << "We need more gold! " << std::endl;
	}
	else
	{
		state = ERROR;
		return;
	}
}

void Automata::choice(int choice)
{
	if (state == ACCEPT)
	{
		state = CHECK;
	}
	else
	{
		state = ERROR;
		return;
	}
	pos = choice;
	if (choice > 6)
	{
		state = ERROR;
		return;
	}
	std::cout << "You choose " << menu[choice] << " and it costs " << price[choice] << std::endl;
}

void Automata::finish()
{
	if (state == COOK)
	{
		state = WAIT;
	}
	else
		state = ERROR;
}

void Automata::cashback()
{
	std::cout << "Cashback: " << cash << std::endl;
	cash = 0;
}

