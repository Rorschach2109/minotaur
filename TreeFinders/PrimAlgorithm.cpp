/*
 * This file is part of minotaur.
 *
 * File: PrimAlgorithm.cpp
 * Brief: Implementation of prim algorithm class.
 *
 * Date: 23.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "PrimAlgorithm.h"
#include "TreeModel.h"

#include <limits>
#include <utility>

using namespace Minotaur;

CPrimAlgorithm::CCut::CCut( const IGraphModel& graphModel, const CNodeModel& nodeRoot ) : 
	m_graphModel( graphModel )
{
	m_mstNodes.push_back(nodeRoot);
	m_AddValidEdgesToMST(nodeRoot);
}

CPrimAlgorithm::CCut::~CCut( void )
{
	
}			

CEdgeModel CPrimAlgorithm::CCut::m_FindCheapestEdge( void )
{
	CEdgeModel cheapestEdge = CEdgeModel();
	double cheapestWeight = std::numeric_limits< double >::infinity();
	
	for ( auto edge : m_cutEdges )
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

void CPrimAlgorithm::CCut::m_AddValidEdgesToMST( const CNodeModel& node )
{
	std::vector < CNodeModel > nodeNeighbors = m_graphModel.GetNeighbors( node );
	for ( auto neighborNode : nodeNeighbors )
	{
		CEdgeModel edgeToAdd = m_graphModel.GetGraphModelEdge( node.GetNodeId(), neighborNode.GetNodeId() );
		
		bool vectorsContainEdge = (
									( m_VectorContainsEdge(edgeToAdd, m_cutEdges) ) &&
									( m_VectorContainsEdge(edgeToAdd, m_mstEdges) )
									);
		if ( !vectorsContainEdge )
		{
			m_cutEdges.push_back(edgeToAdd);
		}
	}
}

void CPrimAlgorithm::CCut::m_RemoveInvalidEdges( void )
{
	std::vector < CEdgeModel > invalidEdges;
	for ( auto edge : m_cutEdges )
	{
		unsigned int nodeFromId = edge.GetNodeFromId();
		unsigned int nodeToId = edge.GetNodeToId();
		bool mstContainsNode = (
									( m_VectorContainsNode(nodeFromId, m_mstNodes) ) &&
									( m_VectorContainsNode(nodeToId, m_mstNodes) )
									);
		if ( mstContainsNode )
		{
			invalidEdges.push_back(edge);
		}
	}
		
	for ( auto invalidEdge : invalidEdges )
	{
		m_EraseEdge(invalidEdge);
	}
}

bool CPrimAlgorithm::CCut::m_VectorContainsNode( const unsigned int& nodeIdToCheck, const std::vector < CNodeModel >& nodesVector )
{
	bool vectorContainsNode = false;
	CNodeModel nodeToCheck = m_graphModel.GetGraphModelNode(nodeIdToCheck);
	
	for ( auto node : nodesVector )
	{
		if ( nodeToCheck == node )
		{
			vectorContainsNode = true;
			break;
		}
	}

	return vectorContainsNode;
}

bool CPrimAlgorithm::CCut::m_VectorContainsEdge( CEdgeModel& edgeToCheck, const std::vector < CEdgeModel >& edgesVector )
{
	bool vectorContainsEdge = false;
	
	for ( auto edge : edgesVector )
	{
		if ( edgeToCheck == edge )
		{
			vectorContainsEdge = true;
			break;
		}
	}
	
	return vectorContainsEdge;
}

void CPrimAlgorithm::CCut::m_EraseEdge( CEdgeModel& edgeToErase )
{
	for ( auto graphRemainingEdgesIterator = m_cutEdges.begin(); 
			graphRemainingEdgesIterator != m_cutEdges.end();
			++graphRemainingEdgesIterator )
	{
		if ( edgeToErase == ( *graphRemainingEdgesIterator ) )
		{
			m_cutEdges.erase( graphRemainingEdgesIterator );
			break;
		}
	}
}

CNodeModel CPrimAlgorithm::CCut::m_AddNodeToMST( const CEdgeModel& cheapestMSTEdge )
{
	unsigned int nodeFromId = cheapestMSTEdge.GetNodeFromId();
	unsigned int nodeToId = cheapestMSTEdge.GetNodeToId();
	
	CNodeModel nodeFrom = m_graphModel.GetGraphModelNode(nodeFromId);
	CNodeModel nodeTo = m_graphModel.GetGraphModelNode(nodeToId);
	
	CNodeModel nodeToAdd = ( m_VectorContainsNode(nodeFromId, m_mstNodes) )? nodeTo : nodeFrom;
	
	m_mstNodes.push_back(nodeToAdd);
	
	return nodeToAdd;
}

void CPrimAlgorithm::CCut::ExpandMST( void )
{
	CEdgeModel cheapestMSTEdge = m_FindCheapestEdge();
	m_EraseEdge( cheapestMSTEdge );
	
	m_mstEdges.push_back(cheapestMSTEdge);
	CNodeModel addedNodeToMST = m_AddNodeToMST(cheapestMSTEdge);
	
	m_AddValidEdgesToMST(addedNodeToMST);
	m_RemoveInvalidEdges();
}

bool CPrimAlgorithm::CCut::CanExpandMST( void )
{
	return ( 0 < ( m_cutEdges.size() ) );
}

bool CPrimAlgorithm::CCut::GraphModelContained( void )
{
	bool graphModelContained = ( ( m_mstNodes.size() ) == ( m_graphModel.GetNodesNumber() ) );
	return graphModelContained;
}

std::shared_ptr < CTreeModel > CPrimAlgorithm::CCut::BuildMST( void )
{
	std::vector < std::pair < unsigned int, unsigned int > > mstEdgeDefinition;
	for ( auto mstEdge : m_mstEdges )
	{
		unsigned int nodeFromId = mstEdge.GetNodeFromId();
		unsigned int nodeToId = mstEdge.GetNodeToId();
		mstEdgeDefinition.push_back( std::make_pair(nodeFromId, nodeToId) );
	}
	
	std::shared_ptr < CTreeModel > mstPrim( new CTreeModel(m_graphModel, mstEdgeDefinition) );
	return mstPrim;
}

CPrimAlgorithm::CPrimAlgorithm( void ) : 
	ITreeFinder()
{
	
}

CPrimAlgorithm::~CPrimAlgorithm( void )
{
	
}

std::shared_ptr < CTreeModel > CPrimAlgorithm::FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot )
{
	CCut cut = CCut(graphModel, nodeRoot);
	
	while ( !( cut.GraphModelContained() ) && ( cut.CanExpandMST() ) )
	{
		cut.ExpandMST();
	}
		
	return ( cut.BuildMST() );
}
