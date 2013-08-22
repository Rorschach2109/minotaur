#include <iostream>

#include "MinotaurTestManager.h"

int main( void )
{
	Minotaur::CMinotaurTestManager testManager = Minotaur::CMinotaurTestManager();
	testManager.RunAllTests();
	testManager.DisplayTestStatistic();
	
	return 0;
}
