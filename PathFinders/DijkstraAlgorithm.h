/*
 * This file is part of minotaur.
 *
 * File: DijkstraAlgorithm.h
 * Brief: Declaration of dijkstra algorithm class.
 *
 * Date: 25.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_DIJKSTRAALGORITHM_H_
#define _MINOTAUR_DIJKSTRAALGORITHM_H_

#include "IPathFinder.h"
#include "AbstractDijkstraRelaxation.h"

#include <set>

namespace Minotaur
{
	
class CDijkstraAlgorithm : public IPathFinder
{
	private:
		const AbstractDijkstraRelaxation& m_relaxationProvider;
		
		CNodeModel m_GetCheapestNode( const std::set < CNodeModel, CNodeModel::SNodeModelLess >& openNodes );
	
	public:
		CDijkstraAlgorithm( void ) = delete;
		explicit CDijkstraAlgorithm( const AbstractDijkstraRelaxation& relaxationProvider );
		virtual ~CDijkstraAlgorithm( void );
		
		virtual std::shared_ptr < CPathModel > FindShortestPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_DIJKSTRAALGORITHM_H_ */