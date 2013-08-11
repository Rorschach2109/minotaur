/*
 * This file is part of minotaur.
 *
 * File: StreamInputGraphManager.cpp
 * Brief: Implementation of stream input graph manager class.
 *
 * Date: 23.07.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "StreamInputGraphManager.h"

using namespace Minotaur;

CStreamInputGraphManager::CStreamInputGraphManager( std::istream& graphInputStream, const unsigned int& graphsCount ) :
	AbstractInputGraphManager(graphInputStream),
	m_graphsCount(0),
	m_graphName(""),
	m_nodesCount(0),
	m_edgesCount(0),
	m_graphCounter(0)
{
	m_SetGraphsCount(graphsCount);
}

CStreamInputGraphManager::~CStreamInputGraphManager( void )
{

}

void CStreamInputGraphManager::m_SetGraphsCount( const unsigned int& graphsCount )
{
	unsigned int graphsFileCount = 0;
	t_dtoGraphInputStream >> graphsFileCount;
	m_graphsCount = ( graphsFileCount < graphsCount )? graphsFileCount : graphsCount;
}
		
CGraphDto CStreamInputGraphManager::GetNextGraph( void )
{
	if ( m_HasNextGraph() )
	{
		++m_graphCounter;

		t_dtoGraphInputStream >> m_graphName;

		t_dtoGraphInputStream >> m_nodesCount;
		t_dtoGraphInputStream >> m_edgesCount;

		std::vector < CNodeDto > dtoNodes;
		m_GetDtoNodes(dtoNodes);

		std::vector < CEdgeDto > dtoEdges;
		m_GetDtoEdges(dtoEdges);
		
		CGraphDto dtoGraph(m_graphName, dtoNodes, dtoEdges);
		
		return dtoGraph;
	}
	return ( CGraphDto() );
}

bool CStreamInputGraphManager::m_HasNextGraph( void ) const
{
	return ( m_graphsCount > m_graphCounter );
}	

void CStreamInputGraphManager::m_GetDtoNodes( std::vector < CNodeDto >& dtoNodes )
{
	unsigned int nodeDtoId = 0;
	unsigned int nodeDtoX = 0;
	unsigned int nodeDtoY = 0;
	
	for ( unsigned int nodeCounter = 0; nodeCounter < m_nodesCount; ++nodeCounter )
	{
		t_dtoGraphInputStream >> nodeDtoId;
		t_dtoGraphInputStream >> nodeDtoX;
		t_dtoGraphInputStream >> nodeDtoY;
		dtoNodes.push_back( CNodeDto(nodeDtoId, nodeDtoX, nodeDtoY) );
	}
}

void CStreamInputGraphManager::m_GetDtoEdges( std::vector < CEdgeDto >& dtoEdges )
{
	unsigned int nodeFromId = 0;
	unsigned int nodeToId = 0;
	double edgeWeight = 0.0;
	
	for ( unsigned int edgeCounter = 0; edgeCounter < m_edgesCount; ++edgeCounter )
	{
		t_dtoGraphInputStream >> nodeFromId;
		t_dtoGraphInputStream >> nodeToId;
		t_dtoGraphInputStream >> edgeWeight;
		dtoEdges.push_back( CEdgeDto(nodeFromId, nodeToId, edgeWeight) );
	}
}