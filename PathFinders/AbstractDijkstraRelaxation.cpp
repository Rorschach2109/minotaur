/*
 * This file is part of minotaur.
 *
 * File: DijkstraRelaxation.cpp
 * Brief: Implementation of abstract dijkstra relaxation class.
 *
 * Date: 26.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "AbstractDijkstraRelaxation.h"
#include "PathModel.h"

#include <vector>

using namespace Minotaur;

AbstractDijkstraRelaxation::AbstractDijkstraRelaxation( void )
{
	
}

AbstractDijkstraRelaxation::~AbstractDijkstraRelaxation( void )
{
	
}

std::shared_ptr < CPathModel > AbstractDijkstraRelaxation::BuildPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo ) const
{
	std::vector < CNodeModel > pathNodes;
	
	CNodeModel currentNode = nodeTo;
	while ( !( currentNode.operator ==(nodeFrom) ) )
	{
		if ( ( t_predecesors[currentNode] == currentNode ) && 
			( !( currentNode.operator ==(nodeFrom) ) ) )
		{
			return nullptr;
		}	
		
		pathNodes.push_back(currentNode);
		currentNode = t_predecesors[currentNode];
	}
	
	pathNodes.push_back(nodeFrom);
	std::reverse( pathNodes.begin(), pathNodes.end() );

	std::shared_ptr < CPathModel > shortestPath( new CPathModel( graphModel, pathNodes ) );
	return shortestPath;
}
