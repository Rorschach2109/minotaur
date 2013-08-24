/*
 * This file is part of minotaur.
 *
 * File: BoruvkaAlgorithm.cpp
 * Brief: Implementation of boruvka algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "BoruvkaAlgorithm.h"
#include "TreeModel.h"

#include <limits>
#include <utility>

using namespace Minotaur;


CBoruvkaAlgorithm::CCut::CCut( const IGraphModel& graphModel ) :
	m_graphModel( graphModel )
{
	for ( auto graphModelNode : ( m_graphModel.GetGraphModelNodes() ) )
	{
		unsigned int nodeModelId = graphModelNode.GetNodeId();
		m_nodesMap[graphModelNode] = nodeModelId;
		m_forest[nodeModelId].push_back(graphModelNode);

	}
	m_nodeRootId = ( ( m_nodesMap.begin() )->second );
}

CBoruvkaAlgorithm::CCut::~CCut( void )
{
	
}

CEdgeModel CBoruvkaAlgorithm::CCut::m_FindCheapestEdge( const CNodeModel& currentNode )
{
	CEdgeModel cheapestEdge = CEdgeModel();
	double cheapestWeight = std::numeric_limits< double >::infinity();
	unsigned int currentNodeId = currentNode.GetNodeId();

	CNodeModel mstNode = CNodeModel();
	for ( auto neighborNode : m_graphModel.GetNeighbors(currentNode) )
	{
		if ( m_nodesMap[currentNode] != m_nodesMap[neighborNode] )
		{
			unsigned int neighborNodeId = neighborNode.GetNodeId();
			CEdgeModel edgeToNeighbor = m_graphModel.GetGraphModelEdge(currentNodeId, neighborNodeId);
			double edgeToNeighborWeight = edgeToNeighbor.GetEdgeWeight();
				
			if ( edgeToNeighborWeight < cheapestWeight )
			{
				cheapestEdge = edgeToNeighbor;
				cheapestWeight = edgeToNeighborWeight;
				mstNode = neighborNode;
			}
		}
	}
	return cheapestEdge;
}

CEdgeModel CBoruvkaAlgorithm::CCut::m_FindCheapestEdge( const std::vector< CEdgeModel >& cheapestEdges )
{
	double  cheapestWeight = std::numeric_limits< double >::infinity();
	CEdgeModel mstEdge = CEdgeModel();
	for ( auto cheapestEdge : cheapestEdges )
	{
		double currentEdgeWeight = cheapestEdge.GetEdgeWeight();
		if ( currentEdgeWeight < cheapestWeight )
		{
			cheapestWeight = currentEdgeWeight;
			mstEdge = cheapestEdge;
		}
	}
	return mstEdge;
}

void CBoruvkaAlgorithm::CCut::m_AddValidEdge( const CEdgeModel& mstEdge )
{
	CNodeModel nodeFrom = m_graphModel.GetGraphModelNode( mstEdge.GetNodeFromId() );
	CNodeModel nodeTo = m_graphModel.GetGraphModelNode( mstEdge.GetNodeToId() );
	unsigned int minNodeId = ( m_nodesMap[nodeFrom] < m_nodesMap[nodeTo] )? m_nodesMap[nodeFrom] : m_nodesMap[nodeTo];
	unsigned int maxNodeId = ( minNodeId == m_nodesMap[nodeTo] )? m_nodesMap[nodeFrom] : m_nodesMap[nodeTo];
			
	m_nodesMap[nodeFrom] = minNodeId;
	m_nodesMap[nodeTo] = minNodeId;
			
	for ( auto& nodesMapIterator : m_nodesMap )
	{
		nodesMapIterator.second = ( maxNodeId == nodesMapIterator.second )? minNodeId : nodesMapIterator.second;
	}

	m_mstEdges.push_back(mstEdge);
}

void CBoruvkaAlgorithm::CCut::m_UpdateForest( void )
{
	m_forest.clear();
	for ( auto& nodesMapIterator : m_nodesMap )
	{
		m_forest[nodesMapIterator.second].push_back( nodesMapIterator.first );
	}
}

void CBoruvkaAlgorithm::CCut::ExpandMSTBoruvka( void )
{
	for ( auto forestIterator : m_forest )
	{
		if ( CanExpandMSTBoruvka() )
		{
			std::vector < CEdgeModel > cheapestEdges;
			for ( auto currentNode : forestIterator.second )
			{
				cheapestEdges.push_back( m_FindCheapestEdge(currentNode) );
			}
			CEdgeModel mstEdge = m_FindCheapestEdge(cheapestEdges);
			m_AddValidEdge(mstEdge);
			m_UpdateForest();
		}		
	}
}

bool CBoruvkaAlgorithm::CCut::CanExpandMSTBoruvka( void )
{
	bool canExpandMST = false;
	
	for ( auto nodesMapIterator : m_nodesMap )
	{
		if ( m_nodeRootId != ( nodesMapIterator.second ) )
		{
			canExpandMST = true;
			break;
		}
	}
	
	return canExpandMST;
}

std::shared_ptr < CTreeModel > CBoruvkaAlgorithm::CCut::BuildMSTBoruvka( void )
{
	std::vector < std::pair < unsigned int, unsigned int > > mstEdgeDefinition;
	for ( auto mstEdge : m_mstEdges )
	{
		unsigned int nodeFromId = mstEdge.GetNodeFromId();
		unsigned int nodeToId = mstEdge.GetNodeToId();
		
		mstEdgeDefinition.push_back( std::make_pair(nodeFromId, nodeToId) );
	}

	std::shared_ptr < CTreeModel > mstBoruvka( new CTreeModel(m_graphModel, mstEdgeDefinition) );
	return mstBoruvka;
}


CBoruvkaAlgorithm::CBoruvkaAlgorithm( void ) : 
	ITreeFinder()
{
	
}

CBoruvkaAlgorithm::~CBoruvkaAlgorithm( void )
{
	
}
	
std::shared_ptr < CTreeModel > CBoruvkaAlgorithm::FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot )
{
	CCut cut = CCut(graphModel);
	
	while ( cut.CanExpandMSTBoruvka() )
	{
		cut.ExpandMSTBoruvka();
	}
	std::shared_ptr < CTreeModel > mstBoruvka = cut.BuildMSTBoruvka();
	
	return mstBoruvka;
}

