/*
 * This file is part of minotaur.
 *
 * File: GraphModelToGraphDTO.cpp
 * Brief: Implementation of graph model to graph dto class.
 *
 * Date: 12.11.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "GraphModelToGraphDTO.h"

#include "NodeDTO.h"
#include "EdgeDTO.h"
#include "SubGraphToGraphAdapter.h"

#include <iostream>

using namespace Minotaur;

CGraphModelToGraphDto::CGraphModelToGraphDto( std::string graphName, CSubGraphToGraphAdapter& graphModel ) : 
	m_graphName( graphName ),
	m_graphModel(graphModel)
{
	
}

CGraphModelToGraphDto::~CGraphModelToGraphDto( void )
{
	
}

void CGraphModelToGraphDto::m_ConvertNodes( void )
{
	std::cerr << "m_ConvertNodes";
	for ( auto modelNode : m_graphModel.GetGraphModelNodes() )
	{
		unsigned int nodeId = modelNode.GetNodeId();
		unsigned int nodeX = modelNode.GetNodeX();
		unsigned int nodeY = modelNode.GetNodeY();
		
		std::cout << nodeId << "\t" << nodeX << "\t" << nodeY << "\n";
		
		CNodeDto dtoNode = CNodeDto(nodeId, nodeX, nodeY);
		m_dtoNodes.push_back( dtoNode );
	}
}

void CGraphModelToGraphDto::m_ConvertEdges( void )
{
	std::cerr <<  "m_ConvertEdges";
	for ( auto modelEdge :  m_graphModel.GetGraphModelEdges() )
	{
		m_dtoEdges.push_back( CEdgeDto(modelEdge.GetNodeFromId(), modelEdge.GetNodeToId(), modelEdge.GetEdgeWeight() ) );
	}	
}
	
CGraphDto CGraphModelToGraphDto::GetDtoGraph( void )
{
	{
		printf( "Graph Model is not NULL!\n" );
		m_ConvertNodes();
		printf( "Graph Model is not NULL!\n" );
		m_ConvertEdges();
		printf( "Graph Model is not NULL!\n" );
		CGraphDto dtoGraph(m_graphName, m_dtoNodes, m_dtoEdges);
		printf( "Graph Model is not NULL!\n" );
		return dtoGraph;
	}
	printf( "Graph Model is NULL!\n" );
	return ( CGraphDto() );
}