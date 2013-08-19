/*
 * This file is part of minotaur.
 *
 * File: GraphComparer.h
 * Brief: Declaration of graph comparer class.
 *
 * Date: 19.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_GRAPHCOMPARER_H_
#define _MINOTAUR_GRAPHCOMPARER_H_

#include "IGraphModel.h"

namespace Minotaur
{
	
class CGraphComparer
{
	private:
		bool m_CompareNodes( const IGraphModel& lGraph, const IGraphModel& rGraph );
		bool m_CompareEdges( const IGraphModel& lGraph, const IGraphModel& rGraph );
		
	public:
		CGraphComparer( void );
		~CGraphComparer( void );
		
		bool AreEqual( const IGraphModel& lGraph, const IGraphModel& rGraph );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_GRAPHCOMPARER_H_ */