/*
 * This file is part of minotaur.
 *
 * File: DotInputGraphManager.cpp
 * Brief: Implementation of dot input graph manager class.
 *
 * Date: 29.09.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "DotInputGraphManager.h"
#include "StreamInputGraphManager.h"

#include <limits>
#include <fstream>
#include <iostream>

using namespace Minotaur;

CDotInputGraphManager::CDotInputGraphManager( std::istream& graphInputStream ) :
		AbstractInputGraphManager( graphInputStream ),
		m_graphName( "" ),
		m_streamInputGraphManager(NULL)
{

}

CDotInputGraphManager::~CDotInputGraphManager( void )
{
	if ( NULL != m_streamInputGraphManager )
	{
		delete m_streamInputGraphManager;
		m_streamInputGraphManager = NULL;
	}
}

void CDotInputGraphManager::m_SetGraphName( void )
{
	t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), ' ' );
	t_dtoGraphInputStream >> m_graphName;
}

void CDotInputGraphManager::m_IgnoreStyle()
{
	char tempChar = ' ';
	while ( '\n' != tempChar )
	{
		t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), '\n' );
		tempChar = t_dtoGraphInputStream.peek();
	}
	t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), '\n' );
}

void CDotInputGraphManager::t_GetDtoNodes( std::vector < CNodeDto >& dtoNodes )
{
	unsigned int dtoNodeId = 0;
	unsigned int dtoNodeX = 0;
	unsigned int dtoNodeY = 0;

	char tempChar = ' ';
	while ( '\n' != tempChar )
	{
		t_dtoGraphInputStream >> dtoNodeId;

		t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), '"' );
		t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), ' ' );
		t_dtoGraphInputStream >> dtoNodeX;

		t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), ' ' );
		t_dtoGraphInputStream >> dtoNodeY;

		dtoNodes.push_back( CNodeDto(dtoNodeId, dtoNodeX, dtoNodeY) );

		t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), '\n' );

		tempChar = t_dtoGraphInputStream.peek();
	}
	t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), '\n' );
}

void CDotInputGraphManager::t_GetDtoEdges( std::vector < CEdgeDto >& dtoEdges )
{
	unsigned int dtoNodeFromId = 0;
	unsigned int dtoNodeToId = 0;
	double dtoEdgeWeight = 0.0;

	char tempChar = ' ';
	while ( '}' != tempChar )
	{
		t_dtoGraphInputStream >> dtoNodeFromId;

		t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), '-' );
		t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), ' ' );
		t_dtoGraphInputStream >> dtoNodeToId;

		t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), '"' );
		t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), ' ' );
		t_dtoGraphInputStream >> dtoEdgeWeight;

		dtoEdges.push_back( CEdgeDto(dtoNodeFromId, dtoNodeToId, dtoEdgeWeight) );

		t_dtoGraphInputStream.ignore( std::numeric_limits < std::streamsize > :: max(), '\n' );

		tempChar = t_dtoGraphInputStream.peek();
	}
}

CGraphDto CDotInputGraphManager::GetNextGraph( void )
{
	m_SetGraphName();

	std::string systemCommand = "perl ./PerlParser/DotToAKConverter.pl " + m_graphName;
	std::system( systemCommand.c_str() );

	std::string filePath = "./GraphFiles/AKGraphs/" + m_graphName;

	std::ifstream inputFileStream( filePath );
	if ( inputFileStream.is_open() )
	{
		m_streamInputGraphManager = new CStreamInputGraphManager(inputFileStream, 1);
		return ( m_streamInputGraphManager->GetNextGraph() );
	}
	else
	{
		std::cout << "ERROR\n";
		return( CGraphDto() );
	}
}
