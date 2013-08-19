/*
 * This file is part of minotaur.
 *
 * File: GraphComparer.cpp
 * Brief: Implementation of graph comparer class.
 *
 * Date: 19.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "GraphComparer.h"
#include "NodeModel.h"
#include "EdgeModel.h"

#include <vector>

using namespace Minotaur;

CGraphComparer::CGraphComparer( void )
{
	
}

CGraphComparer::~CGraphComparer( void )
{
	
}
		
bool CGraphComparer::AreEqual( const IGraphModel& lGraph, const IGraphModel& rGraph )
{
	bool areEqual = m_CompareNodes(lGraph, rGraph) && m_CompareEdges(lGraph, rGraph);
	return areEqual;
}

bool CGraphComparer::m_CompareNodes( const IGraphModel& lGraph, const IGraphModel& rGraph )
{
	std::vector < CNodeModel > lGraphNodes = lGraph.GetGraphModelNodes();
	std::vector < CNodeModel > rGraphNodes = rGraph.GetGraphModelNodes();
	bool equalNodes = ( ( lGraphNodes.size() ) == ( rGraphNodes.size() ) );
	
	if ( equalNodes )
	{
		for ( unsigned int nodeCounter = 0; nodeCounter < lGraphNodes.size(); ++nodeCounter )
		{
			equalNodes = ( lGraphNodes[nodeCounter] == rGraphNodes[nodeCounter] );
			if ( !equalNodes )
			{
				break;
			}
		}
	}
	
	return equalNodes;
}
		
bool CGraphComparer::m_CompareEdges( const IGraphModel& lGraph, const IGraphModel& rGraph )
{
	std::vector < CEdgeModel > lGraphEdges = lGraph.GetGraphModelEdges();
	std::vector < CEdgeModel > rGraphEdges = rGraph.GetGraphModelEdges();
	bool equalEdges = ( ( lGraphEdges.size() ) == ( rGraphEdges.size() ) );
	
	if ( equalEdges )
	{
		for ( unsigned int edgeCounter = 0; edgeCounter < lGraphEdges.size(); ++edgeCounter )
		{
			equalEdges = ( lGraphEdges[edgeCounter] == rGraphEdges[edgeCounter] );
			if ( !equalEdges )
			{
				break;
			}
		}
	}
	
	return equalEdges;
}
