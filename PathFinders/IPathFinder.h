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
	protected:
		virtual void t_ComputeHeapMemoryUsage( void ) = 0;

		unsigned long long t_executionTime;
		unsigned long long t_minotaurStackMemoryAllocated;
		unsigned long long t_minotaurStackMemoryFreed;
		unsigned long long t_minotaurHeapMemoryUsage;

	public:
		IPathFinder( void ) = default;
		virtual ~IPathFinder( void )
		{
			
		}
		
		virtual std::shared_ptr < CPathModel > FindShortestPath( const IGraphModel& graphModel, const CNodeModel& nodeFrom, const CNodeModel& nodeTo ) = 0;
		
		unsigned long long GetExecutionTime( void ) const
		{
			return t_executionTime;
		}

		unsigned long long GetStackMemoryAllocated( void ) const
		{
			return t_minotaurStackMemoryAllocated;
		}
		
		unsigned long long GetStackMemoryFreed( void ) const
		{
			return t_minotaurStackMemoryFreed;
		}
		
		unsigned long long GetHeapMemoryUsage( void ) const
		{
			return t_minotaurHeapMemoryUsage;
		}
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_IPATHFINDER_H_ */
