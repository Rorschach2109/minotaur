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

#include <memory>

namespace Minotaur
{

class CTreeModel;

class ITreeFinder
{
	public:
		ITreeFinder( void ) = default;
		virtual ~ITreeFinder( void )
		{
			
		}
		
		virtual std::shared_ptr < CTreeModel > FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot ) = 0;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ITREEFINDER_H_ */