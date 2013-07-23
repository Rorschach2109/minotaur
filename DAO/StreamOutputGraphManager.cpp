/*
 * This file is part of minotaur.
 *
 * File: StreamOutputGraphManager.cpp
 * Brief: Implementation of stream output graph manager class.
 *
 * Date: 23.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "StreamOutputGraphManager.h"

#include "NodeDTO.h"
#include "EdgeDTO.h"

#include <string>
#include <vector>

using namespace Minotaur;

CStreamOutputGraphManager::CStreamOutputGraphManager( std::ostream& graphOutputStream, const unsigned int& graphsCount ) : 
	AbstractOutputGraphManager(graphOutputStream),
	m_graphsCount(graphsCount),
	m_graphsCounter(0)
{
	t_dtoGraphOutputStream << m_graphsCount << "\n";	
}

CStreamOutputGraphManager::~CStreamOutputGraphManager( void )
{
	
}

void CStreamOutputGraphManager::WriteGraphToOutput( const CGraphDto& dtoGraph ) const
{
	if ( m_graphsCount > m_graphsCounter )
	{
		m_WriteDtoGraphName(dtoGraph);
		m_WriteDtoNodes(dtoGraph);
		m_WriteDtoEdges(dtoGraph);
		++m_graphsCounter;	
	}
}

void CStreamOutputGraphManager::m_WriteDtoGraphName( const CGraphDto& dtoGraph ) const
{
	std::string dtoGraphName = dtoGraph.GetDtoGraphName();
	t_dtoGraphOutputStream << dtoGraphName << "\n";
}

void CStreamOutputGraphManager::m_WriteDtoNodes( const CGraphDto& dtoGraph ) const
{
	auto dtoNodes = dtoGraph.GetNodesDto();
	for ( auto dtoNode : dtoNodes )
	{
		t_dtoGraphOutputStream << dtoNode.GetNodeId() << "\t";
		t_dtoGraphOutputStream << dtoNode.GetNodeX() << "\t";
		t_dtoGraphOutputStream << dtoNode.GetNodeY() << "\n";
	}
}

void CStreamOutputGraphManager::m_WriteDtoEdges( const CGraphDto& dtoGraph ) const
{
	auto dtoEdges = dtoGraph.GetEdgesDto();
	for ( auto dtoEdge : dtoEdges )
	{
		t_dtoGraphOutputStream << dtoEdge.GetNodeFromId() << "\t";
		t_dtoGraphOutputStream << dtoEdge.GetNodeToId() << "\t";
		t_dtoGraphOutputStream << dtoEdge.GetWeight() << "\n";
	}
}