/*
 * This file is part of minotaur.
 *
 * File: DijkstraAlgorithm.cpp
 * Brief: Implementation of dijkstra algorithm class.
 *
 * Date: 25.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "DijkstraAlgorithm.h"

#include <vector>

using namespace Minotaur;

CDijkstraAlgorithm::CDijkstraAlgorithm( const AbstractDijkstraRelaxation& relaxationProvider ) : 
	IPathFinder(),
	m_relaxationProvider( relaxationProvider )
{
	
}

CDijkstraAlgorithm::~CDijkstraAlgorithm( void )
{
	
}

CNodeModel CDijkstraAlgorithm::m_GetCheapestNode( const std::set < CNodeModel, CNodeModel::SNodeModelLess >& openNodes )
{
	CNodeModel cheapestNode = *(openNodes.begin() );
	for ( auto openNode : openNodes )
	{
		if ( m_relaxationProvider.IsCheaper(openNode, cheapestNode) )
		{
			cheapestNode = openNode;
		}
	}
	return cheapestNode;
}

std::shared_ptr < CPathModel > CDijkstraAlgorithm::FindShortestPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo )
{
	std::set < CNodeModel, CNodeModel::SNodeModelLess > openNodes;
	std::set < CNodeModel, CNodeModel::SNodeModelLess > closedNodes;
	
	openNodes.insert(nodeFrom);
	m_relaxationProvider.Reset(graphModel, nodeFrom);
	
	while ( !( openNodes.empty() ) )
	{
		CNodeModel cheapestNode = m_GetCheapestNode(openNodes);
		openNodes.erase(cheapestNode);
		closedNodes.insert(cheapestNode);
		
		std::vector < CNodeModel > cheapestNodeNeigbors = graphModel.GetNeighbors(cheapestNode);
		
		for ( auto neighborNode : cheapestNodeNeigbors )
		{
			if ( ( closedNodes.find(neighborNode) ) != ( closedNodes.end() ) )
			{
				continue;
			}

			bool relaxed = m_relaxationProvider.Relax(graphModel, cheapestNode, neighborNode);
			if ( relaxed )
			{
				openNodes.insert(neighborNode);
			}
		}
	}

	return ( m_relaxationProvider.BuildPath(graphModel, nodeFrom, nodeTo) );
}
