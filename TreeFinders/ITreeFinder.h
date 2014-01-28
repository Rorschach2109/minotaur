/*
 * This file is part of minotaur.
 *
 * File: ITreeFinder.h
 * Brief: Declaration of tree finder interface.
 *
 * Date: 18.07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_ITREEFINDER_H_
#define _MINOTAUR_ITREEFINDER_H_

#include "IGraphModel.h"
#include "NodeModel.h"
#include "MinotaurMemory.h"

#include <memory>

namespace Minotaur
{

class CTreeModel;

class ITreeFinder
{
	protected:
		virtual void t_ComputeHeapMemoryUsage( void ) = 0;

		unsigned long long t_executionTime;
		unsigned long long t_minotaurStackMemoryAllocated;
		unsigned long long t_minotaurStackMemoryFreed;
		unsigned long long t_minotaurHeapMemoryUsage;
		
	public:
		ITreeFinder( void ) : 
			t_executionTime ( 0 ),
			t_minotaurStackMemoryAllocated ( 0 ),
			t_minotaurStackMemoryFreed ( 0 ),
			t_minotaurHeapMemoryUsage ( 0 )
		{
				
		}

		virtual ~ITreeFinder( void )
		{
			
		}
		
		virtual std::shared_ptr < CTreeModel > FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot ) = 0;
		
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

#endif /* _MINOTAUR_ITREEFINDER_H_ */
