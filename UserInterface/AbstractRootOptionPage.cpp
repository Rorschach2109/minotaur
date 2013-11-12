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
		t_graphName( "" ),
		t_graphStream( nullptr ),
		t_algorithmUIPage( nullptr ),
		t_inputGraphManager( nullptr ),
		t_outputGraphManager( nullptr ),
		t_resultGraph( nullptr ),
		t_resultGraphName( "" )
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
	if ( nullptr != t_outputGraphManager )
	{
		delete t_outputGraphManager;
		t_outputGraphManager = nullptr;
	}
	if ( nullptr != t_algorithmUIPage )
	{
		delete t_algorithmUIPage;
		t_algorithmUIPage = nullptr;
	}
	t_resultGraph.reset();
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
		if ( nullptr != t_resultGraph )
		{
			t_resultGraph.reset();
			t_resultGraph = nullptr;
		}
		t_algorithmUIPage = new CAlgorithmUIPage(t_inputGraphManager, t_graphName);
		t_algorithmUIPage->RunPage();
		t_resultGraphName = t_algorithmUIPage->GetSubGraphName();
		delete t_algorithmUIPage;
		t_algorithmUIPage = nullptr;
	}
	else
	{
		printf("%s", t_noFileLoadedMessage.c_str() );
	}
	t_ProcessLoadFile();
}

void AbstractRootOptionPage::ExecuteOption( void ) const
{
	switch( t_optionId )
	{
	case ERootOptionId::LOAD_GRAPH_FILE:
		t_GetGraphName();
		t_ProcessLoadFile();
		break;
	case ERootOptionId::CONVERT_INPUT_FILE:
		t_ProcessConvertInputFile();
		break;
	case ERootOptionId::CHOOSE_ALGORITHM:
		t_ProcessChooseAlgorithm();
		break;
	case ERootOptionId::PRINT_INPUT_GRAPH:
		t_ProcessPrintInputGraph();
		break;
	case ERootOptionId::PRINT_RESULT_GRAPH:
		t_ProcessPrintResultGraph();
		break;	
	case ERootOptionId::EXIT:
		break;
	default:
		printf("%s", t_wrongOptionMessage.c_str() );
		this->RunPage();
	}
}
