/*
 * This file is part of minotaur.
 *
 * File: KruskalAlgorithm.cpp
 * Brief: Implementation of kruskal algorithm class.
 *
 * Date: 21.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "KruskalAlgorithm.h"
#include "TreeModel.h"

#include <limits>
#include <utility>
#include <chrono>

using namespace Minotaur;

extern unsigned long long g_stackMemoryAllocated;
extern unsigned long long g_stackMemoryFreed;

CKruskalAlgorithm::CEdgeSet::CEdgeSet( const IGraphModel& graphModel ) : 
	m_graphModel( graphModel ),
	heapMemoryUsed( 0 )
{
	m_mstEdges.clear();
	m_graphModelRemaningEdges = graphModel.GetGraphModelEdges();

	for ( auto graphModelNode : ( graphModel.GetGraphModelNodes() ) )
	{
		unsigned int nodeModelId = graphModelNode.GetNodeId();
		m_forest[graphModelNode] = nodeModelId;
	}
}

CKruskalAlgorithm::CEdgeSet::~CEdgeSet( void )
{
	
}

CEdgeModel CKruskalAlgorithm::CEdgeSet::m_FindCheapestEdge( void )
{
	CEdgeModel cheapestEdge = CEdgeModel();
	double cheapestWeight = std::numeric_limits< double >::infinity();

	for ( auto edge : m_graphModelRemaningEdges )
	{
		double currentEdgeWeight = edge.GetEdgeWeight();
		if ( currentEdgeWeight < cheapestWeight )
		{
			cheapestEdge = edge;
			cheapestWeight = currentEdgeWeight;
		}
	}
	
	return cheapestEdge;
}

void CKruskalAlgorithm::CEdgeSet::m_EraseEdge( CEdgeModel& edgeToErase )
{
	for ( auto graphRemainingEdgesIterator = m_graphModelRemaningEdges.begin(); 
			graphRemainingEdgesIterator != m_graphModelRemaningEdges.end();
			++graphRemainingEdgesIterator )
	{
		if ( edgeToErase == ( *graphRemainingEdgesIterator ) )
		{
			m_graphModelRemaningEdges.erase( graphRemainingEdgesIterator );
			break;
		}
	}
}

void CKruskalAlgorithm::CEdgeSet::m_AddEdgeToForest( const CEdgeModel& edgeToAdd )
{
	unsigned int nodeFromId = edgeToAdd.GetNodeFromId();
	unsigned int nodeToId = edgeToAdd.GetNodeToId();
	
	CNodeModel nodeFrom = m_graphModel.GetGraphModelNode(nodeFromId);
	CNodeModel nodeTo = m_graphModel.GetGraphModelNode(nodeToId);
	
	if ( m_forest[nodeFrom] != m_forest[nodeTo] )
	{
		unsigned int minNodeId = ( m_forest[nodeFrom] < m_forest[nodeTo] )? m_forest[nodeFrom] : m_forest[nodeTo];
		unsigned int maxNodeId = ( minNodeId == m_forest[nodeFrom] )? m_forest[nodeTo] : m_forest[nodeFrom];
		
		m_forest[nodeFrom] = minNodeId;
		m_forest[nodeTo] = minNodeId;

		for ( auto& forestNodePair : m_forest )
		{
			forestNodePair.second = ( forestNodePair.second == maxNodeId )? minNodeId : forestNodePair.second;
		}
		
		m_mstEdges.push_back(edgeToAdd);
	}
}

void CKruskalAlgorithm::CEdgeSet::ExpandMST( void )
{
	CEdgeModel cheapestMSTEdge = m_FindCheapestEdge();
	m_EraseEdge( cheapestMSTEdge );
	m_AddEdgeToForest( cheapestMSTEdge );
}

bool CKruskalAlgorithm::CEdgeSet::CanExpandMST( void )
{
	bool canExpandMST = false;

	for ( auto remainingEdge : m_graphModelRemaningEdges )
	{
		CNodeModel nodeFrom = m_graphModel.GetGraphModelNode( remainingEdge.GetNodeFromId() );
		CNodeModel nodeTo = m_graphModel.GetGraphModelNode( remainingEdge.GetNodeToId() );
		if ( m_forest[nodeFrom] != m_forest[nodeTo] )
		{
			canExpandMST = true;
			break;
		}
	}

	return canExpandMST;
}

std::shared_ptr < CTreeModel > CKruskalAlgorithm::CEdgeSet::BuildMST( const CNodeModel& nodeRoot )
{
	std::vector < std::pair < unsigned int, unsigned int > > mstEdgeDefinition;

	for ( auto mstEdge : m_mstEdges )
	{
		unsigned int nodeFromId = mstEdge.GetNodeFromId();
		unsigned int nodeToId = mstEdge.GetNodeToId();
		CNodeModel nodeFrom = m_graphModel.GetGraphModelNode( nodeFromId );

		if ( m_forest[nodeRoot] == m_forest[nodeFrom] )
		{
			mstEdgeDefinition.push_back( std::make_pair(nodeFromId, nodeToId) );
		}
	}
	
	std::shared_ptr < CTreeModel > mstKruskal( new CTreeModel(m_graphModel, mstEdgeDefinition) );
	
	return mstKruskal;
}

CKruskalAlgorithm::CKruskalAlgorithm( void ) : 
	ITreeFinder()
{
	
}

CKruskalAlgorithm::~CKruskalAlgorithm( void )
{
	
}

void CKruskalAlgorithm::t_ComputeHeapMemoryUsage( void )
{
        t_minotaurHeapMemoryUsage =  sizeof(CEdgeSet) + 2 * sizeof(std::shared_ptr < CTreeModel > ) +
					5 * sizeof(CEdgeModel) + 6 * sizeof(CNodeModel) + 7 * sizeof(unsigned int) +
					sizeof(bool) + 2 * sizeof(double) + sizeof( std::vector < std::pair < unsigned int, unsigned int > > ) + 
					sizeof(CKruskalAlgorithm);
}

	
std::shared_ptr < CTreeModel > CKruskalAlgorithm::FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot )
{
	unsigned long long stackMemoryAllocatedBefore = g_stackMemoryAllocated;
	unsigned long long stackMemoryFreedBefore = g_stackMemoryFreed;

	auto startTime = std::chrono::high_resolution_clock::now();

	CEdgeSet edgeSet = CEdgeSet( graphModel );

	while ( edgeSet.CanExpandMST() )
	{
		edgeSet.ExpandMST();
	}

	std::shared_ptr < CTreeModel > mstKruskal = edgeSet.BuildMST( nodeRoot );
	
	auto endTime = std::chrono::high_resolution_clock::now();
	auto executionTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
	t_executionTime = executionTime.count();
	
	t_minotaurStackMemoryAllocated = g_stackMemoryAllocated - stackMemoryAllocatedBefore;
	t_minotaurStackMemoryFreed = g_stackMemoryFreed - stackMemoryFreedBefore;

	t_ComputeHeapMemoryUsage();

	return ( mstKruskal );
}
