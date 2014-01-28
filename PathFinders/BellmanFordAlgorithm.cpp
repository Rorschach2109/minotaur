/*
 * This file is part of minotaur.
 *
 * File: BellmanFordAlgorithm.cpp
 * Brief: Implementation of bellman-ford algorithm class.
 *
 * Date: 25.08.2013
 * Author: Andrzej Korycinski
 *
 * */


#include "BellmanFordAlgorithm.h"

#include <chrono>

using namespace Minotaur;

extern unsigned long long g_stackMemoryAllocated;
extern unsigned long long g_stackMemoryFreed;

CBellmanFordAlgorithm::CBellmanFordAlgorithm( const CRelaxationProvider& relaxationProvider ) : 
	IPathFinder(),
	m_relaxationProvider( relaxationProvider )
{
	t_minotaurHeapMemoryUsage += sizeof( m_relaxationProvider );	
}

CBellmanFordAlgorithm::~CBellmanFordAlgorithm( void )
{
	
}

void CBellmanFordAlgorithm::t_ComputeHeapMemoryUsage( void )
{
	t_minotaurHeapMemoryUsage = 5 * sizeof(CNodeModel) + 2 * sizeof(unsigned int) + sizeof(CEdgeModel) +
					sizeof( std::shared_ptr < CPathModel > ) + sizeof( CBellmanFordAlgorithm) +
					m_relaxationProvider.heapMemoryUsed;
}

std::shared_ptr < CPathModel > CBellmanFordAlgorithm::FindShortestPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo )
{
	unsigned long long stackMemoryAllocatedBefore = g_stackMemoryAllocated;
	unsigned long long stackMemoryFreedBefore = g_stackMemoryFreed;

	auto startTime = std::chrono::high_resolution_clock::now();

	CNodeModel::SNodeModelLess nodeModelLess = CNodeModel::SNodeModelLess();
	CNodeModel nodeRoot = ( nodeModelLess(nodeFrom, nodeTo) )? nodeFrom : nodeTo;
	CNodeModel nodeDestination = ( nodeRoot.operator ==(nodeFrom) )? nodeTo : nodeFrom;
	
	m_relaxationProvider.Reset(graphModel, nodeRoot);

	for ( auto graphModelEdge : graphModel.GetGraphModelEdges() )
	{
		unsigned int currentEdgeNodeFromId = graphModelEdge.GetNodeFromId();
		unsigned int currentEdgeNodeToId = graphModelEdge.GetNodeToId();
		CNodeModel currentEdgeNodeFrom = graphModel.GetGraphModelNode(currentEdgeNodeFromId);
		CNodeModel currentEdgeNodeTo = graphModel.GetGraphModelNode(currentEdgeNodeToId);
		
		m_relaxationProvider.Relax(graphModel, currentEdgeNodeFrom, currentEdgeNodeTo);
		m_relaxationProvider.Relax(graphModel, currentEdgeNodeTo, currentEdgeNodeFrom);
	}

	auto endTime = std::chrono::high_resolution_clock::now();
	auto executionTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	t_executionTime = executionTime.count();
	
	std::shared_ptr < CPathModel > shortestPath = m_relaxationProvider.BuildPath(graphModel, nodeRoot, nodeDestination);
	
	t_minotaurStackMemoryAllocated = g_stackMemoryAllocated - stackMemoryAllocatedBefore;
	t_minotaurStackMemoryFreed = g_stackMemoryFreed - stackMemoryFreedBefore;

	t_ComputeHeapMemoryUsage();

	return ( shortestPath );
}
