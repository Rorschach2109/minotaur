/*
 * This file is part of minotaur.
 *
 * File: IPathFinder.h
 * Brief: Declaration of path finder interface.
 *
 * Date: 18.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_IPATHFINDER_H_
#define _MINOTAUR_IPATHFINDER_H_

#include "PathModel.h"
#include "IGraphModel.h"
#include "NodeModel.h"

#include <memory>

namespace Minotaur
{

class IPathFinder
{
	public:
		IPathFinder( void ) = default;
		virtual ~IPathFinder( void )
		{
			
		}
		
		virtual std::shared_ptr < CPathModel > FindShortestPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo ) = 0;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_IPATHFINDER_H_ */