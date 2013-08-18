/*
 * This file is part of minotaur.
 *
 * File: SubGraphToGraphAdapterTest.h
 * Brief: Declaration of subgraph to graph adapter test class.
 *
 * Date: 15.08.2013
 * Author: Andrzej Korycinski
 * 
 * */
 
#ifndef _MINOTAUR_SUBGRAPHTOGRAPHADAPTERTEST_H_
#define _MINOTAUR_SUBGRAPHTOGRAPHADAPTERTEST_H_
 
#include "AbstractMinotaurModelTest.h"
#include "SubGraphModel.h"
#include "SubGraphToGraphAdapter.h"

namespace Minotaur
{
 
class CSubGraphToGraphAdapterTest : public AbstractMinotaurModelTest
{
	private:
		CSubGraphModel m_subGraphTest;
		CSubGraphToGraphAdapter m_adapterTest;
		
		void m_RunTest( void );
		void m_ContainsNodeTest( void );
		void m_GetGraphModelNodeTest( void );
		void m_GetGraphModelNodesTest( void );
		void m_GetNodesNumberTest( void );
		void m_GetNeighborsTest( void );
		void m_ContainsEdgeTest( void );
		void m_GetGraphModelEdgeTest( void );
		void m_GetGraphModelEdgesTest( void );
		void m_GetEdgesNumberTest( void );

	public:
		CSubGraphToGraphAdapterTest( void );
		virtual ~CSubGraphToGraphAdapterTest( void );
};
 
} // namespace Minotaur
 
#endif /* _MINOTAUR_SUBGRAPHTOGRAPHADAPTERTEST_H_ */