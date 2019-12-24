#include "gtest/gtest.h"
#include "Automata.h"

TEST(automata_getMoney, test1)
{
	Automata automata;
	automata.on();
	automata.coin(50);
	int money = automata.getMoney();
	EXPECT_EQ(50, money);
}

TEST(automata_isOn, test2)
{
	Automata automata;
	automata.on();
	EXPECT_EQ(automata.coin(50), true);
}

TEST(automata_isOff, test3)
{
	Automata automata;
	EXPECT_EQ(automata.coin(50), false);
}
