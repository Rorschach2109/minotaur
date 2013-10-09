/*
 * This file is part of minotaur.
 *
 * File: AKUIPage.cpp
 * Brief: Implementation of ak user interface page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "AKUIPage.h"

#include <iostream>
#include <unistd.h>

using namespace Minotaur;

CAKUIPage::CAKUIPage( void ) :
		AbstractRootOptionPage()
{

}

CAKUIPage::~CAKUIPage( void )
{

}

void CAKUIPage::DisplayOptions( void ) const
{
	std::cout << "*****Root Page*****\n\n";
	std::cout << "1.\tLoad AK Graph File\n";
	std::cout << "2.\tConvert to Dot Graph File\n";
	std::cout << "3.\tChoose Algorithm\n";
	std::cout << "4.\tPrint Graph\n";
	std::cout << "\n*******************\n";
	std::cout << "99.\tEnd\n\n";
}

void CAKUIPage::ExecuteOption( void ) const
{
	switch( t_optionId )
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		std::cout << "\n\nWrong Option!\n\n";
		sleep(2);
		this->RunPage();
	}
}
