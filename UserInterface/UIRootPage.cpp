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

#include <cstdlib>
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
	printf("*****Root Page*****\n\n");
	printf("1.\tAK Graph File\n");
	printf("2.\tDot Graph File\n");
	printf("\n*******************\n");
	printf("99.\tEnd\n\n");
}

void CUIRootPage::ExecuteOption( void ) const
{
	switch( t_optionId )
	{
	case ERootOption::AK_GRAPH_FILE:
		m_ProcessAKGraphFile();
		break;
	case ERootOption::DOT_GRAPH_FILE:
		m_ProcessDotGraphFile();
		break;
	case ERootOption::EXIT_ROOT:
		printf("\nExit");
		break;
	default:
		printf("%s", t_wrongOptionMessage.c_str() );
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
