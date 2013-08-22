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

#include "DTO/NodeDTO.h"
#include "DTO/EdgeDTO.h"

#include <string>
#include <vector>

using namespace Minotaur;

CStreamOutputGraphManager::CStreamOutputGraphManager( std::ostream& graphOutputStream, const unsigned int& graphsCount ) : 
	AbstractOutputGraphManager(graphOutputStream),
	m_graphsCount(graphsCount),
	m_graphsCounter(0)
{
	t_dtoGraphOutputStream << m_graphsCount << "\n\n";	
}

CStreamOutputGraphManager::~CStreamOutputGraphManager( void )
{
	
}

void CStreamOutputGraphManager::WriteGraphToOutput( const CGraphDto& dtoGraph ) const
{
	while ( m_graphsCount > m_graphsCounter )
	{
		m_WriteDtoGraphName(dtoGraph);
		m_WriteDtoNodesEdges(dtoGraph);
		++m_graphsCounter;	
	}
}

void CStreamOutputGraphManager::m_WriteDtoGraphName( const CGraphDto& dtoGraph ) const
{
	std::string dtoGraphName = dtoGraph.GetDtoGraphName();
	t_dtoGraphOutputStream << dtoGraphName << "\n\n";
}

void CStreamOutputGraphManager::m_WriteDtoNodesEdges( const CGraphDto& dtoGraph ) const
{
	m_dtoNodes = dtoGraph.GetNodesDto();
	m_dtoEdges = dtoGraph.GetEdgesDto();
	
	size_t nodesCount = m_dtoNodes.size();
	size_t edgesCount = m_dtoEdges.size();
	
	t_dtoGraphOutputStream << nodesCount << "\t" << edgesCount << "\n\n";
	
	m_WriteDtoNodes();
	m_WriteDtoEdges();
}

void CStreamOutputGraphManager::m_WriteDtoNodes( void ) const
{
	for ( auto dtoNode : m_dtoNodes )
	{
		t_dtoGraphOutputStream << dtoNode.GetNodeId() << "\t";
		t_dtoGraphOutputStream << dtoNode.GetNodeX() << "\t";
		t_dtoGraphOutputStream << dtoNode.GetNodeY() << "\n";
	}
	t_dtoGraphOutputStream << "\n";
}

void CStreamOutputGraphManager::m_WriteDtoEdges( void ) const
{
	for ( auto dtoEdge : m_dtoEdges )
	{
		t_dtoGraphOutputStream << dtoEdge.GetNodeFromId() << "\t";
		t_dtoGraphOutputStream << dtoEdge.GetNodeToId() << "\t";
		t_dtoGraphOutputStream << dtoEdge.GetEdgeWeight() << "\n";
	}
	t_dtoGraphOutputStream << "\n";
}