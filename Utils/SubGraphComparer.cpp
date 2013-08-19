/*
 * This file is part of minotaur.
 *
 * File: SubGraphComparer.cpp
 * Brief: Implementation of subgraph comparer class.
 *
 * Date: 19.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "SubGraphComparer.h"

#include <vector>

using namespace Minotaur;

CSubGraphComparer::CSubGraphComparer( void ) : 
	m_graphComparer( CGraphComparer() )
{
	
}

CSubGraphComparer::~CSubGraphComparer( void )
{
	
}
		
bool CSubGraphComparer::AreEqual( const CSubGraphModel& lSubGraph, const CSubGraphModel& rSubGraph )
{
	const IGraphModel& lGraph = lSubGraph.GetParentGraph();
	const IGraphModel& rGraph = rSubGraph.GetParentGraph();
	
	return ( m_graphComparer.AreEqual(lGraph, rGraph) && m_CompareEdges(lSubGraph, rSubGraph) );
}

bool CSubGraphComparer::m_CompareEdges( const CSubGraphModel& lSubGraph, const CSubGraphModel& rSubGraph )
{
	std::vector < std::pair < unsigned int, unsigned int > > lSubGraphEdges = lSubGraph.GetSubGraphEdges();
	std::vector < std::pair < unsigned int, unsigned int > > rSubGraphEdges = rSubGraph.GetSubGraphEdges();
	bool equalEdges = ( ( lSubGraphEdges.size() ) && ( rSubGraphEdges.size() ) );
	
	if ( equalEdges )
	{
		for ( unsigned int edgeCounter = 0; edgeCounter < lSubGraphEdges.size(); ++edgeCounter )
		{
			equalEdges = ( ( lSubGraphEdges[edgeCounter].first == rSubGraphEdges[edgeCounter].first ) &&
							( lSubGraphEdges[edgeCounter].second == rSubGraphEdges[edgeCounter].second ) );
			if ( !equalEdges )
			{
				break;
			}
		}
	}
	
	return equalEdges;
}
