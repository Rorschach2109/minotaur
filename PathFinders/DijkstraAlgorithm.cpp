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
#include <chrono>

using namespace Minotaur;

extern unsigned long long g_stackMemoryAllocated;
extern unsigned long long g_stackMemoryFreed;

CDijkstraAlgorithm::CDijkstraAlgorithm( const AbstractDijkstraRelaxation& relaxationProvider ) : 
	IPathFinder(),
	m_relaxationProvider( relaxationProvider )
{

}

CDijkstraAlgorithm::~CDijkstraAlgorithm( void )
{
	
}

void CDijkstraAlgorithm::t_ComputeHeapMemoryUsage( void )
{
	t_minotaurHeapMemoryUsage = 4 * sizeof(CNodeModel) + 2 * sizeof(unsigned int) + sizeof( std::shared_ptr < CPathModel > ) + 
					sizeof(bool) + 2 * sizeof( std::set < CNodeModel, CNodeModel::SNodeModelLess > ) + 
					sizeof( std::vector < CNodeModel > ) + sizeof(CDijkstraAlgorithm) + 
					m_relaxationProvider.heapMemoryUsed;
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
	unsigned long long stackMemoryAllocatedBefore = g_stackMemoryAllocated;
	unsigned long long stackMemoryFreedBefore = g_stackMemoryFreed;

	auto startTime = std::chrono::high_resolution_clock::now();

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
			
			t_minotaurHeapMemoryUsage += ( relaxed );
			
			if ( relaxed )
			{
				openNodes.insert(neighborNode);
			}
		}
	}

	auto endTime = std::chrono::high_resolution_clock::now();
	auto executionTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	t_executionTime = executionTime.count();

	std::shared_ptr < CPathModel > shortestPath = m_relaxationProvider.BuildPath(graphModel, nodeFrom, nodeTo);
	
	t_minotaurStackMemoryAllocated = g_stackMemoryAllocated - stackMemoryAllocatedBefore;
	t_minotaurStackMemoryFreed = g_stackMemoryFreed - stackMemoryFreedBefore;

	t_ComputeHeapMemoryUsage();

	return ( shortestPath );
}
