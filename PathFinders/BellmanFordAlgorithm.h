/*
 * This file is part of minotaur.
 *
 * File: BellmanFordAlgorithm.h
 * Brief: Declaration of bellman-ford algorithm class.
 *
 * Date: 25.08.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_BELLMANFORDALGORITHM_H_
#define _MINOTAUR_BELLMANFORDALGORITHM_H_

#include "IPathFinder.h"
#include "RelaxationProvider.h"

namespace Minotaur
{
	
class CBellmanFordAlgorithm : public IPathFinder
{
	private:
		const CRelaxationProvider& m_relaxationProvider;
		
	public:
		CBellmanFordAlgorithm( void ) = delete;
		explicit CBellmanFordAlgorithm( const CRelaxationProvider& relaxationProvider );
		virtual ~CBellmanFordAlgorithm( void );
		
		virtual std::shared_ptr < CPathModel > FindShortestPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_BELLMANFORDALGORITHM_H_ */
