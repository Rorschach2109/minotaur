/*
 * This file is part of minotaur.
 *
 * File: AbstractGraphModelFactory.cpp
 * Brief: Implementation of abstract graph model factory class.
 *
 * Date: 11.08.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
 #include "AbstractGraphModelFactory.h"
 
 using namespace Minotaur;
 
AbstractGraphModelFactory::AbstractGraphModelFactory( void )
{
	
}

AbstractGraphModelFactory::~AbstractGraphModelFactory( void )
{
	
}

std::shared_ptr < IGraphModel > AbstractGraphModelFactory::CreateFromDto( const std::vector < CNodeDto >& graphDtoNodes, const std::vector < CEdgeDto >& graphDtoEdges )
{
	std::vector < CNodeModel > graphModelNodes = m_ConvertDtoNodesToModel(graphDtoNodes);
	std::vector < CEdgeModel > graphModelEdges = m_ConvertDtoEdgesToModel(graphDtoEdges);
	
	return ( CreateFromVectors(graphModelNodes, graphModelEdges) );
}

std::vector < CNodeModel > AbstractGraphModelFactory::m_ConvertDtoNodesToModel( const std::vector < CNodeDto >& graphDtoNodes )
{
	std::vector < CNodeModel > graphModelNodes;
	
	for ( auto dtoNode : graphDtoNodes )
	{
		unsigned int nodeId = dtoNode.GetNodeId();
		unsigned int nodeX = dtoNode.GetNodeX();
		unsigned int nodeY = dtoNode.GetNodeY();
		
		graphModelNodes.push_back( CNodeModel(nodeId, nodeX, nodeY) );
	}
	
	return graphModelNodes;
}

std::vector < CEdgeModel > AbstractGraphModelFactory::m_ConvertDtoEdgesToModel( const std::vector < CEdgeDto >& graphDtoEdges )
{
	std::vector < CEdgeModel > graphModelEdges;
	
	for ( auto dtoEdge : graphDtoEdges )
	{
		unsigned int nodeFromId = dtoEdge.GetNodeFromId();
		unsigned int nodeToId = dtoEdge.GetNodeToId();
		double edgeWeight = dtoEdge.GetEdgeWeight();
		
		graphModelEdges.push_back( CEdgeModel(nodeFromId, nodeToId, edgeWeight) );
	}
	
	return graphModelEdges;
}