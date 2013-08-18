/*
 * This file is part of minotaur.
 *
 * File: DijkstraAlgorithm.h
 * Brief: Declaration of dijkstra algorithm class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_DIJKSTRAALGORITHM_H_
#define _MINOTAUR_DIJKSTRAALGORITHM_H_

#include "IPathFinder.h"

namespace Minotaur
{
	
class CDijkstraAlgorithm : public IPathFinder
{
	public:
		CDijkstraAlgorithm( void );
		virtual ~CDijkstraAlgorithm( void );
		
		virtual std::shared_ptr < CPathModel > FindShortestPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_DIJKSTRAALGORITHM_H_ */