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

#include "TreeModel.h"
#include "IGraphModel.h"
#include "NodeModel.h"

#include <utility>

namespace Minotaur
{

class ITreeFinder
{
	public:
		ITreeFinder( void );
		virtual ~ITreeFinder( void )
		{
			
		}
		
		virtual shared_ptr < CTreeModel > FindMST( const IGraphModel& graphModel, const CNodeModel& nodeRoot ) = 0;
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_ITREEFINDER_H_ */