/*
 * This file is part of minotaur.
 *
 * File: DijkstraAlgorithm.cpp
 * Brief: Implementation of dijkstra algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "DijkstraAlgorithm.h"

using namespace Minotaur;

CDijkstraAlgorithm::CDijkstraAlgorithm( void ) : 
	IPathFinder()
{
	
}

CDijkstraAlgorithm::~CDijkstraAlgorithm( void )
{
	
}
		
std::shared_ptr < CPathModel > CDijkstraAlgorithm::FindShortestPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo )
{
	return nullptr;
}
