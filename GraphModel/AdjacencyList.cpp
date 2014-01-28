/*
 * This file is part of minotaur.
 *
 * File: AdjacencyList.cpp
 * Brief: Implementation of adjacency list class.
 *
 * Date: 29.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "AdjacencyList.h"

#include <set>

using namespace Minotaur;

CAdjacencyList::CAdjacencyList( const AdjacencyMap& adjacencyMap, const NodesMap& nodesMap ) : 
	IGraphModel(),
	m_adjacencyMap( adjacencyMap ),
	m_nodesMap( nodesMap )
{
	
}

CAdjacencyList::~CAdjacencyList( void )
{
	m_adjacencyMap.clear();
	m_nodesMap.clear();
}

bool CAdjacencyList::operator==( CAdjacencyList& adjacencyListToCompare )
{
	bool adjacencyListsEqual = ( adjacencyListToCompare.m_adjacencyMap.size() == m_adjacencyMap.size() );
	adjacencyListsEqual = adjacencyListsEqual && ( adjacencyListToCompare.m_nodesMap.size() == m_nodesMap.size() );
	
	if ( adjacencyListsEqual )
	{
		adjacencyListsEqual = adjacencyListsEqual && m_CompareNodesMaps(adjacencyListToCompare.m_nodesMap);
		adjacencyListsEqual = adjacencyListsEqual && m_CompareAdjacencyMaps(adjacencyListToCompare.m_adjacencyMap);
	}
	return adjacencyListsEqual;
}

bool CAdjacencyList::m_CompareNodesMaps( NodesMap& toCompareNodesMap )
{
	bool nodesMapsEqual = true;
	unsigned int nodesMapSize = m_nodesMap.size();
	auto nodesMapIteratorToCompare = toCompareNodesMap.begin();
	auto nodesMapIterator = m_nodesMap.begin();
	
	for ( unsigned int nodesMapIndex = 0; nodesMapIndex < nodesMapSize; ++nodesMapIndex, ++nodesMapIteratorToCompare, ++nodesMapIterator )
	{
		bool equalInside = ( ( nodesMapIteratorToCompare->first ) == ( nodesMapIterator->first ) );
		equalInside = equalInside && ( ( nodesMapIteratorToCompare->second ) == ( nodesMapIterator->second ) );
		if ( !equalInside )
		{
			nodesMapsEqual = false;
			break;
		}
	}
	return nodesMapsEqual;
}

bool CAdjacencyList::m_CompareAdjacencyMaps( AdjacencyMap& toCompareAdjacencyMap )
{
	bool adjacencyMapsEqual = true;
	unsigned int adjacencyMapSize = m_adjacencyMap.size();
	auto adjacencyMapIteratorToCompare = toCompareAdjacencyMap.begin();
	auto adjacencyMapIterator = m_adjacencyMap.begin();
	
	for ( unsigned int adajcencyMapIndex = 0; adajcencyMapIndex < adjacencyMapSize; ++adajcencyMapIndex, ++adjacencyMapIteratorToCompare, ++adjacencyMapIterator )
	{
		bool equalInside = ( ( adjacencyMapIteratorToCompare->first ) == ( adjacencyMapIterator->first ) );
		equalInside = equalInside && ( ( adjacencyMapIteratorToCompare->second.size() ) == ( adjacencyMapIterator->second.size() ) );
		if ( equalInside )
		{
			for ( unsigned int edgesVectorIndex = 0; edgesVectorIndex < adjacencyMapIterator->second.size(); ++edgesVectorIndex )
			{
				try
				{
					equalInside = equalInside && ( ( adjacencyMapIteratorToCompare->second.at(edgesVectorIndex).first ) == 
						( adjacencyMapIterator->second.at(edgesVectorIndex).first ) );
					equalInside = equalInside && ( ( adjacencyMapIteratorToCompare->second.at(edgesVectorIndex).second ) == 
						( adjacencyMapIterator->second.at(edgesVectorIndex).second ) );
					if ( !equalInside )
					{
						adjacencyMapsEqual = false;
					}
				}
				catch( ... )
				{
					//NOPE
					return adjacencyMapsEqual;
				}
			}
		}
	}
	return adjacencyMapsEqual;
}
		
		
bool CAdjacencyList::ContainsNode( const unsigned int& nodeId ) const
{
	return ( ( m_nodesMap.end() ) != ( m_nodesMap.find(nodeId) ) );
}

CNodeModel CAdjacencyList::GetGraphModelNode( const unsigned int& nodeId ) const
{
	auto nodesMapIterator = m_nodesMap.find(nodeId);
	if ( ( m_nodesMap.end() ) != nodesMapIterator )
	{
		return nodesMapIterator->second;
	}
	return ( CNodeModel() );
}

const std::vector < CNodeModel > CAdjacencyList::GetGraphModelNodes( void ) const
{
	std::vector< CNodeModel > graphModelNodes;
	for ( auto nodesMapIterator : m_nodesMap )
	{
		graphModelNodes.push_back( nodesMapIterator.second );
	}
	return graphModelNodes;
}

unsigned int CAdjacencyList::GetNodesNumber( void ) const
{
	return ( m_nodesMap.size() );
}
std::vector < CNodeModel > CAdjacencyList::GetNeighbors ( const CNodeModel& nodeFrom ) const
{
	std::vector< CNodeModel > graphModelNodeNeighbors;
	unsigned int nodeFromId = nodeFrom.GetNodeId();
	
	try
	{
		for ( auto edgesVectorIndex : m_adjacencyMap.at(nodeFromId) )
		{
			CNodeModel neighborNode = GetGraphModelNode( edgesVectorIndex.second );
			graphModelNodeNeighbors.push_back(neighborNode);
		}
	}
	catch( ... )
	{
		// nothing special
		// returning empty vector
	} 
	
	return graphModelNodeNeighbors;
}

bool CAdjacencyList::ContainsEdge( const unsigned int& nodeFromId, const unsigned int& nodeToId ) const
{
	bool containsEdge = false;
	
	auto adjMapIterator = m_adjacencyMap.find( nodeFromId );
	if ( ( m_adjacencyMap.end() ) != ( adjMapIterator ) )
	{
		for ( unsigned int vectorIndex = 0; vectorIndex < adjMapIterator->second.size(); ++vectorIndex )
		{
			try
			{
				if ( nodeToId == adjMapIterator->second.at(vectorIndex).second )
				{
					containsEdge = true;
					break;
				}
			}
			catch( ... )
			{
				//NOPE
				return containsEdge;
			}
		}
	}	
	return containsEdge;
}

CEdgeModel CAdjacencyList::GetGraphModelEdge( const unsigned int& nodeFromId, const unsigned int& nodeToId ) const
{
	auto adjMapIterator = m_adjacencyMap.find( nodeFromId );
	if ( ( m_adjacencyMap.end() ) != ( adjMapIterator ) )
	{
		for ( unsigned int vectorIndex = 0; vectorIndex < adjMapIterator->second.size(); ++vectorIndex )
		{
			try
			{
				if ( nodeToId == adjMapIterator->second.at(vectorIndex).second )
				{
					return ( adjMapIterator->second.at(vectorIndex).first );
				}
			}
			catch( ... )
			{
				break;
			}
		}
	}	
	return ( CEdgeModel() );
}

const std::vector < CEdgeModel > CAdjacencyList::GetGraphModelEdges( void ) const
{
	std::set < CEdgeModel, CEdgeModel::SEdgeModelLess > graphModelEdgesSet;
	
	for ( auto adjacencyMapIterator : m_adjacencyMap )
	{
		for ( auto adjacencyMapVectorIterator : adjacencyMapIterator.second )
		{
			graphModelEdgesSet.insert( adjacencyMapVectorIterator.first );
		}
	}
	std::vector< CEdgeModel > graphModelEdges( graphModelEdgesSet.begin(), graphModelEdgesSet.end() );
	
	return graphModelEdges;
}

unsigned int CAdjacencyList::GetEdgesNumber( void ) const
{
	std::set < CEdgeModel, CEdgeModel::SEdgeModelLess > graphModelEdgesSet;
	
	for ( auto adjacencyMapIterator : m_adjacencyMap )
	{
		for ( auto adjacencyMapVectorIterator : adjacencyMapIterator.second )
		{
			graphModelEdgesSet.insert( adjacencyMapVectorIterator.first );
		}
	}
	return ( graphModelEdgesSet.size() );
}

