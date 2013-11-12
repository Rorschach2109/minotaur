/*
 * This file is part of minotaur.
 *
 * File: DotOutputGraphManager.cpp
 * Brief: Implementation of dot output graph manager class.
 *
 * Date: 29.09.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "DotOutputGraphManager.h"
#include "StreamOutputGraphManager.h"

using namespace Minotaur;

CDotOutputGraphManager::CDotOutputGraphManager( std::ostream& graphOutputStream ) :
		AbstractOutputGraphManager( graphOutputStream ),
		m_streamOutputGraphManager( NULL )
{

}

CDotOutputGraphManager::~CDotOutputGraphManager( void )
{
	if ( NULL != m_streamOutputGraphManager )
	{
		delete m_streamOutputGraphManager;
		m_streamOutputGraphManager = NULL;
	}
}

void CDotOutputGraphManager::t_WriteDtoNodesEdges( const CGraphDto& dtoGraph ) const
{

}

void CDotOutputGraphManager::t_WriteDtoGraphName( const CGraphDto& dtoGraph ) const
{

}

void CDotOutputGraphManager::t_WriteDtoNodes( void ) const
{

}

void CDotOutputGraphManager::t_WriteDtoEdges( void ) const
{

}

void CDotOutputGraphManager::WriteGraphToOutput( const CGraphDto& dtoGraph ) const
{
	m_streamOutputGraphManager = new CStreamOutputGraphManager(t_dtoGraphOutputStream, 1);
	m_streamOutputGraphManager->WriteGraphToOutput(dtoGraph);

	std::string systemCommand = "perl ./../PerlParser/AKToDotConverter.pl " + dtoGraph.GetDtoGraphName();
	std::system( systemCommand.c_str() );
}
