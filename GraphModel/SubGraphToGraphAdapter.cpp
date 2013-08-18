/*
 * This file is part of minotaur.
 *
 * File: SubGraphToGraphAdapter.cpp
 * Brief: Implementation of subgraph to graph adapter class.
 *
 * Date: 15.08.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#include "SubGraphToGraphAdapter.h"
#include <set>
 
using namespace Minotaur;
 
CSubGraphToGraphAdapter::CSubGraphToGraphAdapter( const CSubGraphModel& subGraphModel ) : 
	IGraphModel(),
	m_parentGraphModel( subGraphModel.GetParentGraph() ),
	m_subGraphModel(subGraphModel)
{
	
}

CSubGraphToGraphAdapter::~CSubGraphToGraphAdapter( void )
{
	
}
	
bool CSubGraphToGraphAdapter::ContainsNode( const unsigned int& nodeId ) const
{
	bool containsNode = false;
	for ( auto edgeDef : m_subGraphModel.GetSubGraphEdges() )
	{
		if ( ( nodeId == edgeDef.first ) || ( nodeId == edgeDef.second ) )
		{
			containsNode = true;
		} 
	}
	return containsNode;
}

CNodeModel CSubGraphToGraphAdapter::GetGraphModelNode( const unsigned int& nodeId ) const
{
	for ( auto edgeDef : m_subGraphModel.GetSubGraphEdges() )
	{
		if ( ( nodeId == edgeDef.first ) || ( nodeId == edgeDef.second ) )
		{
			return m_parentGraphModel.GetGraphModelNode(nodeId);
		} 
	}
	return CNodeModel();
}

const std::vector < CNodeModel > CSubGraphToGraphAdapter::GetGraphModelNodes( void ) const
{
	std::set < unsigned int > subGraphNodesIdSet;
	for ( auto edgeDef : m_subGraphModel.GetSubGraphEdges() )
	{
		subGraphNodesIdSet.insert(edgeDef.first);
		subGraphNodesIdSet.insert(edgeDef.second);
	}

	std::vector < CNodeModel > subGraphNodes;
	for ( auto setIterator : subGraphNodesIdSet )
	{
		CNodeModel subGraphNode = m_parentGraphModel.GetGraphModelNode(setIterator);
		subGraphNodes.push_back(subGraphNode);
	}
	
	return subGraphNodes;
}

unsigned int CSubGraphToGraphAdapter::GetNodesNumber( void ) const
{
	std::set < unsigned int > subGraphNodesIdSet;
	for ( auto edgeDef : m_subGraphModel.GetSubGraphEdges() )
	{
		subGraphNodesIdSet.insert(edgeDef.first);
		subGraphNodesIdSet.insert(edgeDef.second);
	}
	return ( subGraphNodesIdSet.size() );
}

std::vector < CNodeModel > CSubGraphToGraphAdapter::GetNeighbors ( const CNodeModel& nodeFrom ) const
{
	std::set < unsigned int > subGraphNodesIdSet;
	const unsigned int currentNodeId = nodeFrom.GetNodeId();
	
	for ( auto edgeDef : m_subGraphModel.GetSubGraphEdges() )
	{
		if ( currentNodeId == edgeDef.first )
		{
			subGraphNodesIdSet.insert( edgeDef.second );
		}
	}

	std::vector <  CNodeModel > neighborNodes;
	for ( auto nodeId : subGraphNodesIdSet )
	{
		neighborNodes.push_back( m_parentGraphModel.GetGraphModelNode(nodeId) );
	}
	
	return neighborNodes;
}

bool CSubGraphToGraphAdapter::ContainsEdge( const unsigned int& nodeFromId, const unsigned int& nodeToId ) const
{
	bool containsNode = false;
	for ( auto edgeDef : m_subGraphModel.GetSubGraphEdges() )
	{
		if ( ( nodeFromId == edgeDef.first ) && ( nodeToId == edgeDef.second ) )
		{
			containsNode = true;
		} 
	}
	return containsNode;
}

CEdgeModel CSubGraphToGraphAdapter::GetGraphModelEdge( const unsigned int& nodeFromId, const unsigned int& nodeToId ) const
{
	for ( auto edgeDef : m_subGraphModel.GetSubGraphEdges() )
	{
		if ( ( nodeFromId == edgeDef.first ) && (  nodeToId == edgeDef.second ) )
		{
			CEdgeModel edgeToReturn = m_parentGraphModel.GetGraphModelEdge(nodeFromId, nodeToId);
			return edgeToReturn;
		} 
	}
	return CEdgeModel();
}

const std::vector < CEdgeModel > CSubGraphToGraphAdapter::GetGraphModelEdges( void ) const
{
	std::vector < CEdgeModel > subGraphEdges;
	
	for ( auto edgeDef : m_subGraphModel.GetSubGraphEdges() )
	{
		CEdgeModel subGraphEdge = m_parentGraphModel.GetGraphModelEdge(edgeDef.first, edgeDef.second);
		subGraphEdges.push_back(subGraphEdge);
	}
	
	return subGraphEdges;
}

unsigned int CSubGraphToGraphAdapter::GetEdgesNumber( void ) const
{
	return ( m_subGraphModel.GetSubGraphEdges().size() );
}