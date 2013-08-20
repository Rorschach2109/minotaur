/*
 * This file is part of minotaur.
 *
 * File: AdjacencyListFactory.cpp
 * Brief: Implementation of adjacency list factory class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "AdjacencyListFactory.h"
#include "AdjacencyList.h"

using namespace Minotaur;

CAdjacencyListFactory::CAdjacencyListFactory( void ) : 
	AbstractGraphModelFactory()
{
	
}

CAdjacencyListFactory::~CAdjacencyListFactory( void )
{
	
}

std::shared_ptr < IGraphModel > CAdjacencyListFactory::CreateFromVectors( const std::vector < CNodeModel >& graphModelNodes, const std::vector < CEdgeModel >& graphModelEdges )
{
	std::map < unsigned int, CNodeModel > graphModelNodesMap;
	std::map < unsigned int, std::vector < std::pair < CEdgeModel, unsigned int > > > graphModelAdjacencyMap;
	
	m_CreateGraphModelNodesMap(graphModelNodesMap, graphModelNodes);
	m_CreateGraphModelAdjacencyMap(graphModelAdjacencyMap, graphModelEdges);
	
	std::shared_ptr < CAdjacencyList > adjacencyList( new CAdjacencyList( graphModelAdjacencyMap, graphModelNodesMap ) );
	
	return adjacencyList;
}

void CAdjacencyListFactory::m_CreateGraphModelNodesMap( std::map < unsigned int, CNodeModel >& graphModelNodesMap, const std::vector < CNodeModel >& graphModelNodes )
{
	graphModelNodesMap.clear();
	for ( auto graphModelNode : graphModelNodes )
	{
		graphModelNodesMap[ graphModelNode.GetNodeId() ] = graphModelNode;
	}
}

void CAdjacencyListFactory::m_CreateGraphModelAdjacencyMap( std::map < unsigned int, std::vector < std::pair < CEdgeModel, unsigned int > > >& graphModelAdjacencyMap,
																const std::vector < CEdgeModel >& graphModelEdges )
{
	graphModelAdjacencyMap.clear();
	
	for ( auto graphModelEdge : graphModelEdges )
	{	
		unsigned int nodeFromId = graphModelEdge.GetNodeFromId();
		unsigned int nodeToId = graphModelEdge.GetNodeToId();
		
		graphModelAdjacencyMap[nodeFromId].push_back( std::make_pair( graphModelEdge, nodeToId ) );
		graphModelAdjacencyMap[nodeToId].push_back( std::make_pair( graphModelEdge, nodeFromId ) );
	}
}