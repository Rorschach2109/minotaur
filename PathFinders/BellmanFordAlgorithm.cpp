/*
 * This file is part of minotaur.
 *
 * File: BellmanFordAlgorithm.cpp
 * Brief: Implementation of bellman-ford algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#include "BellmanFordAlgorithm.h"

using namespace Minotaur;

CBellmanFordAlgorithm::CBellmanFordAlgorithm( void ) : 
	IPathFinder()
{
	
}

CBellmanFordAlgorithm::~CBellmanFordAlgorithm( void )
{
	
}
		
std::shared_ptr < CPathModel > CBellmanFordAlgorithm::FindShortestPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo )
{
	return nullptr;
}
