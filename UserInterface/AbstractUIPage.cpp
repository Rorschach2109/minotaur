/*
 * This file is part of minotaur.
 *
 * File: AbstractUIPage.cpp
 * Brief: Implementation of abstract user interface page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "AbstractUIPage.h"

#include <limits>
#include <iostream>

using namespace Minotaur;

AbstractUIPage::AbstractUIPage( void ) :
		t_optionId( std::numeric_limits<unsigned int>::max() )
{

}

AbstractUIPage::~AbstractUIPage( void )
{

}

unsigned int AbstractUIPage::t_WaitForInput( void ) const
{
	unsigned int optionId = std::numeric_limits < unsigned int >::max();
	while( true )
	{
	        std::cin >> optionId;
	        if ( std::cin.fail())
	        {
	                std::cout << "Not a number\n";
	                std::cin.clear();
	                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        }
	        else
	        {
	                break;
	        }
	}
	return optionId;
}

void AbstractUIPage::RunPage( void ) const
{
	while ( 99 != t_optionId )
	{
		system("CLS");
		DisplayOptions();
		t_optionId = t_WaitForInput();
		ExecuteOption();
	}
}
