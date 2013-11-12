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
#include "StreamInputGraphManager.h"
#include "StreamOutputGraphManager.h"

#include "GraphModelToGraphDTO.h"
#include "IGraphModel.h"
#include "GraphDTO.h"

#include <fstream>
#include <cstdlib>

using namespace Minotaur;

CAKUIPage::CAKUIPage( void ) :
		AbstractRootOptionPage()
{

}

CAKUIPage::~CAKUIPage( void )
{
	if ( nullptr != t_graphStream )
	{
		delete t_graphStream;
		t_graphStream = nullptr;
	}
}

void CAKUIPage::t_ProcessLoadFile( void ) const
{
	if ( nullptr != t_inputGraphManager )
	{
		delete t_inputGraphManager;
		t_inputGraphManager = nullptr;
	}
	
	std::string graphFilePath = "./../GraphFiles/AKGraphs/" + t_graphName;

	t_graphStream = new std::ifstream( graphFilePath.c_str() );

	if ( ( nullptr != t_graphStream ) && ( t_graphStream->good() ) )
	{
		printf("%s", t_goodFileMessage.c_str() );
	}
	else
	{
		printf("%s", t_wrongFileMessage.c_str() );
	}
	t_inputGraphManager = new CStreamInputGraphManager(*t_graphStream, 1);
}

void CAKUIPage::t_ProcessConvertInputFile( void ) const
{
	if ( ( nullptr != t_graphStream ) && ( t_graphStream->good() ) )
	{
		std::string systemCommand = "perl ./../PerlParser/AKToDotConverter.pl " + t_graphName;

		if ( 0 == system( systemCommand.c_str() ) )
		{
			printf("\n\nDot file saved in GraphFiles/DotGraphs Directory.\nName of file: %s.dot", t_graphName.c_str());
		}
		else
		{
			printf("%s", t_wrongCommandMessage.c_str() );
		}
	}
	else
	{
		printf("%s", t_noFileLoadedMessage.c_str() );
	}
}

void CAKUIPage::t_ProcessPrintInputGraph( void ) const
{
	if ( nullptr != t_inputGraphManager )
	{
		std::string systemCommand = "dot -Tpng ./../GraphFiles/DotGraphs/" + t_graphName + ".dot -o ./../GraphFiles/" + t_graphName + ".png";
		if ( 0 == system( systemCommand.c_str() ) )
		{
			systemCommand = "eog ./../GraphFiles/" + t_graphName + ".png";
			if ( 0 == system( systemCommand.c_str() ) )
			{
				printf( "eog Error\n\n" );
			}
		}
		else
		{
			printf("%s", t_wrongCommandMessage.c_str() );
		}
	}
	else
	{
		printf("%s", t_noFileLoadedMessage.c_str() );		
	}
}

void CAKUIPage::t_ProcessPrintResultGraph( void ) const
{
	if ( nullptr != t_inputGraphManager )
	{
		std::string systemCommand = "dot -Tpng ./../GraphFiles/DotGraphs/" + t_resultGraphName + ".dot -o ./../GraphFiles/" + t_resultGraphName + ".png";
		if ( 0 == system( systemCommand.c_str() ) )
		{
			systemCommand = "eog ./../GraphFiles/" + t_resultGraphName + ".png";
			if ( 0 == system( systemCommand.c_str() ) )
			{
				printf( "eog Error\n\n" );
			}
		}
		else
		{
			printf("%s", t_wrongCommandMessage.c_str() );
		}
	}
	else
	{
		printf("%s", t_noFileLoadedMessage.c_str() );		
	}	
}

void CAKUIPage::DisplayOptions( void ) const
{
	printf("*****AK Page*****\n\n");
	printf("1.\tLoad AK Graph File\n");
	printf("2.\tConvert to Dot Graph Input File\n");
	printf("3.\tChoose Algorithm\n");
	printf("4.\tPrint Input Graph\n");
	printf("5.\tPrint Result Graph\n");
	printf("\n*******************\n");
	printf("99.\tEnd\n\n");
}
