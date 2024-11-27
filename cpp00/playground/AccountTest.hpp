
#pragma once
#ifndef ACCOUNTTEST_HPP
#define ACCOUNTTEST_HPP

#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

#define B "\e[1m"
#define BRED "\e[1;31m"
#define GREEN "\e[32m"
#define DARK "\e[2m"
#define BYEL "\e[1;33m"
#define UYEL "\e[4;33m"
#define N "\e[0m"


class AccountTest
{
private:
	/* data */
public:
	typedef AccountTest		me;

	AccountTest(int initial_deposit);
	~AccountTest( void );
};



#endif
