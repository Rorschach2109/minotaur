/*
 * This file is part of minotaur.
 *
 * File: AbstractRootOptionPage.cpp
 * Brief: Implementation of abstract user interface root option page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "AbstractRootOptionPage.h"
#include "AlgorithmUIPage.h"
#include "AbstractInputGraphManager.h"
#include "AbstractOutputGraphManager.h"

#include <cstdlib>
#include <iostream>
#include <unistd.h>

using namespace Minotaur;

AbstractRootOptionPage::AbstractRootOptionPage( void ) :
		AbstractUIPage(),
		t_graphName(""),
		t_graphStream(nullptr),
		t_inputGraphManager(nullptr)
{

}

AbstractRootOptionPage::~AbstractRootOptionPage( void )
{
	if ( nullptr != t_graphStream )
	{
		delete t_graphStream;
		t_graphStream = nullptr;
	}
	if ( nullptr != t_inputGraphManager )
	{
		delete t_inputGraphManager;
		t_inputGraphManager = nullptr;
	}
}

void AbstractRootOptionPage::t_GetGraphName( void ) const
{
	printf("\nWrite Graph Name To Load: ");
	std::cin >> t_graphName;
}

void AbstractRootOptionPage::t_ProcessChooseAlgorithm( void ) const
{
	if ( ( nullptr != t_graphStream ) && ( t_graphStream->good() ) )
	{
		CAlgorithmUIPage* algorithmUIPage = new CAlgorithmUIPage(t_inputGraphManager);

		algorithmUIPage->RunPage();

		delete algorithmUIPage;
	}
	else
	{
		printf("%s", t_noFileLoadedMessage.c_str() );
	}
}

void AbstractRootOptionPage::t_ProcessPrintGraph( void ) const
{
	if ( ( nullptr != t_graphStream ) && ( t_graphStream->good() ) )
	{
	}
	else
	{
		printf("%s", t_noFileLoadedMessage.c_str() );
	}
}

void AbstractRootOptionPage::ExecuteOption( void ) const
{
	switch( t_optionId )
	{
	case ERootOptionId::LOAD_GRAPH_FILE:
		t_ProcessLoadFile();
		break;
	case ERootOptionId::CONVERT_FILE:
		t_ProcessConvertFile();
		break;
	case ERootOptionId::CHOOSE_ALGORITHM:
		t_ProcessChooseAlgorithm();
		break;
	case ERootOptionId::PRINT_GRAPH:
		t_ProcessPrintGraph();
		break;
	case ERootOptionId::EXIT:
		break;
	default:
		printf("%s", t_wrongOptionMessage.c_str() );
		this->RunPage();
	}
}
