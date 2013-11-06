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
	t_GetGraphName();
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

void CAKUIPage::t_ProcessConvertFile( void ) const
{
	if ( ( nullptr != t_graphStream ) && ( t_graphStream->good() ) )
	{
		std::string systemCommand = "perl ./../PerlParser/AKToDotConverter " + t_graphName;

		if ( 0 != system( systemCommand.c_str() ) )
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

void CAKUIPage::DisplayOptions( void ) const
{
	printf("*****AK Page*****\n\n");
	printf("1.\tLoad AK Graph File\n");
	printf("2.\tConvert to Dot Graph File\n");
	printf("3.\tChoose Algorithm\n");
	printf("4.\tPrint Graph\n");
	printf("\n*******************\n");
	printf("99.\tEnd\n\n");
}
