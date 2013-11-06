/*
 * This file is part of minotaur.
 *
 * File: DotUIPage.cpp
 * Brief: Implementation of dot user interface page class.
 *
 * Date: 09.10.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "DotUIPage.h"
#include "DotInputGraphManager.h"

#include <fstream>
#include <cstdlib>

using namespace Minotaur;

CDotUIPage::CDotUIPage( void ) :
		AbstractRootOptionPage()
{

}

CDotUIPage::~CDotUIPage( void )
{
	if ( nullptr != t_graphStream )
	{
		delete t_graphStream;
		t_graphStream = nullptr;
	}
}

void CDotUIPage::t_ProcessLoadFile( void ) const
{
	t_GetGraphName();
	std::string graphFilePath = "./../GraphFiles/DotGraphs/" + t_graphName;

	t_graphStream = new std::ifstream( graphFilePath.c_str() );

	if ( ( nullptr != t_graphStream ) && ( t_graphStream->good() ) )
	{
		printf("%s", t_goodFileMessage.c_str() );
	}
	else
	{
		printf("%s", t_wrongFileMessage.c_str() );
	}
	t_inputGraphManager = new CDotInputGraphManager(*t_graphStream);
}

void CDotUIPage::t_ProcessConvertFile( void ) const
{
	if ( ( nullptr != t_graphStream ) && ( t_graphStream->good() ) )
	{
		std::string systemCommand = "perl ./../PerlParser/DotToAKConverter " + t_graphName;

		if ( 0 != system( systemCommand.c_str() ) )
		{
			printf("\n\nDot file saved in GraphFiles/AKGraphs Directory.\nName of File: %s", t_graphName.c_str());
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

void CDotUIPage::DisplayOptions( void ) const
{
	printf("*****Dot Page*****\n\n");
	printf("1.\tLoad Dot Graph File\n");
	printf("2.\tConvert to AK Graph File\n");
	printf("3.\tChoose Algorithm\n");
	printf("4.\tPrint Graph\n");
	printf("\n*******************\n");
	printf("99.\tEnd\n\n");
}
