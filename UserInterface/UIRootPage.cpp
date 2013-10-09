/*
 * This file is part of minotaur.
 *
 * File: UIRootPage.cpp
 * Brief: Implementation of user interface root page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "UIRootPage.h"

#include "AKUIPage.h"
#include "DotUIPage.h"

#include <iostream>
#include <unistd.h>

using namespace Minotaur;

CUIRootPage::CUIRootPage( void ) :
		m_rootOptionPage(nullptr)
{
	RunPage();
}

CUIRootPage::~CUIRootPage( void )
{
	if ( nullptr != m_rootOptionPage )
	{
		delete m_rootOptionPage;
		m_rootOptionPage = nullptr;
	}
}


void CUIRootPage::DisplayOptions( void ) const
{
	std::cout << "*****Root Page*****\n\n";
	std::cout << "1.\tAK Graph File\n";
	std::cout << "2.\tDot Graph File\n";
	std::cout << "\n*******************\n";
	std::cout << "99.\tEnd\n\n";
}

void CUIRootPage::ExecuteOption( void ) const
{
	switch( t_optionId )
	{
	case 1:
		m_ProcessAKGraphFile();
		break;
	case 2:
		m_ProcessDotGraphFile();
		break;
	default:
		std::cout << "\n\nWrong Option!\n\n";
		sleep(2);
		this->RunPage();
	}
}

void CUIRootPage::m_ProcessAKGraphFile( void ) const
{
	m_rootOptionPage = new CAKUIPage();

	m_rootOptionPage->RunPage();

	delete m_rootOptionPage;
	m_rootOptionPage = nullptr;
}

void CUIRootPage::m_ProcessDotGraphFile( void ) const
{
	m_rootOptionPage = new CDotUIPage();

	m_rootOptionPage->RunPage();

	delete m_rootOptionPage;
	m_rootOptionPage = nullptr;
}
