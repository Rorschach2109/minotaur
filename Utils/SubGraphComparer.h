/*
 * This file is part of minotaur.
 *
 * File: SubGraphComparer.h
 * Brief: Declaration of subgraph comparer class.
 *
 * Date: 19.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_SUBGRAPHCOMPARER_H_
#define _MINOTAUR_SUBGRAPHCOMPARER_H_

#include "GraphComparer.h"
#include "SubGraphModel.h"

namespace Minotaur
{
	
class CSubGraphComparer
{
	private:
		CGraphComparer m_graphComparer;
		
		bool m_CompareEdges( const CSubGraphModel& lSubGraph, const CSubGraphModel& rSubGraph );
		
	public:
		CSubGraphComparer( void );
		~CSubGraphComparer( void );
		
		bool AreEqual( const CSubGraphModel& lSubGraph, const CSubGraphModel& rSubGraph );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_SUBGRAPHCOMPARER_H_ */