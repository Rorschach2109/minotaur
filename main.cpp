#include <iostream>

#include "MinotaurTestManager.h"
#include "AbstractUIPage.h"
#include "UIRootPage.h"

int main( void )
{
	//Minotaur::CMinotaurTestManager testManager = Minotaur::CMinotaurTestManager();
	//testManager.RunAllTests();
	//testManager.DisplayTestStatistic();
	Minotaur::CUIRootPage* rootPage = new Minotaur::CUIRootPage();
	rootPage->RunPage();
	delete rootPage;
	
	return 0;
}
