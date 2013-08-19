/*
 * This file is part of minotaur.
 *
 * File: KruskalAlgorithm.cpp
 * Brief: Implementation of kruskal algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "KruskalAlgorithm.h"

#include <limits>
#include <utility>

using namespace Minotaur;

CKruskalAlgorithm::CEdgeSet::CEdgeSet( const IGraphModel& graphModel ) : 
	m_graphModel( graphModel )
{
	m_graphModelNodesNumber = graphModel.GetNodesNumber();
	
	m_mstTreeEdges.clear();
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
		
		m_mstTreeEdges.push_back(edgeToAdd);
	}
	
}

void CKruskalAlgorithm::CEdgeSet::ExpandMSTTree( void )
{
	CEdgeModel cheapestMSTEdge = m_FindCheapestEdge();
	m_EraseEdge( cheapestMSTEdge );
	m_AddEdgeToForest( cheapestMSTEdge );
}

bool CKruskalAlgorithm::CEdgeSet::CanExpandMSTTree( void )
{
	bool canExpandMSTTree = false;
	for ( auto remaningEdge : m_graphModelRemaningEdges )
	{
		CNodeModel nodeFrom = m_graphModel.GetGraphModelNode( remaningEdge.GetNodeFromId() );
		CNodeModel nodeTo = m_graphModel.GetGraphModelNode( remaningEdge.GetNodeToId() );
		if ( m_forest[nodeFrom] != m_forest[nodeTo] )
		{
			canExpandMSTTree = true;
			break;
		}
	}
	return canExpandMSTTree;
}

std::shared_ptr < CTreeModel > CKruskalAlgorithm::CEdgeSet::BuildMSTTree( const CNodeModel& nodeRoot )
{
	std::vector < std::pair < unsigned int, unsigned int > > mstEdgeDefinition;
	for ( auto mstEdge : m_mstTreeEdges )
	{
		unsigned int nodeFromId = mstEdge.GetNodeFromId();
		unsigned int nodeToId = mstEdge.GetNodeToId();
		CNodeModel nodeFrom = m_graphModel.GetGraphModelNode( nodeFromId );

		if ( m_forest[nodeRoot] == m_forest[nodeFrom] )
		{
			mstEdgeDefinition.push_back( std::make_pair(nodeFromId, nodeToId) );
		}
	}
	
	std::shared_ptr < CTreeModel > mstTree( new CTreeModel(m_graphModel, mstEdgeDefinition) );
	return mstTree;
}

CKruskalAlgorithm::CKruskalAlgorithm( void ) : 
	ITreeFinder()
{
	
}

CKruskalAlgorithm::~CKruskalAlgorithm( void )
{
	
}
	
std::shared_ptr < CTreeModel > CKruskalAlgorithm::FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot )
{
	CEdgeSet edgeSet = CEdgeSet( graphModel );
	while ( edgeSet.CanExpandMSTTree() )
	{
		edgeSet.ExpandMSTTree();
	}
	return ( edgeSet.BuildMSTTree( nodeRoot ) );
}

