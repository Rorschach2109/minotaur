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
#include <unistd.h>

using namespace Minotaur;

AbstractUIPage::AbstractUIPage( void ) :
		t_optionId( std::numeric_limits<unsigned int>::max() ),
		t_noFileLoadedMessage("\nAt First Load Graph File!\n\n"),
		t_goodFileMessage("\nFile Opened\n\n"),
		t_wrongFileMessage("\nWrong File!\n\n"),
		t_wrongOptionMessage("\nWrong Option!\n\n"),
		t_wrongCommandMessage("\nWrong Command!\n\n")
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
	while ( true )
	{
		std::system("clear");
		DisplayOptions();
		t_optionId = t_WaitForInput();
		if ( EUIPageOption::EXIT_PAGE != t_optionId )
		{
			ExecuteOption();
			if ( EUIPageOption::EXIT_PAGE == t_optionId )
			{
				return;
			}
			sleep(1);
			std::system("clear");
			t_optionId = std::numeric_limits<unsigned int>::max();
		}
		else
		{
			return;
		}
	}
	std::system("clear");
}
