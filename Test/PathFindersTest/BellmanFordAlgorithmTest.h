/*
 * This file is part of minotaur.
 *
 * File: BellmanFordAlgorithmTest.h
 * Brief: Declaration of bellman-ford algorithm test class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_BELLMANFORDALGORITHMTEST_H_
#define _MINOTAUR_BELLMANFORDALGORITHMTEST_H_

#include "AbstractMinotaurModelTest.h"
#include "BellmanFordAlgorithm.h"
#include "SubGraphComparer.h"
#include "RelaxationProvider.h"

#include <memory>

namespace Minotaur
{
	
class CBellmanFordAlgorithmTest : public AbstractMinotaurModelTest
{
	private:
		const CRelaxationProvider& m_relaxationProvider;
		CBellmanFordAlgorithm m_bellmanFordAlgorithmTest;
		CSubGraphComparer m_subGraphComparer;
		
		void m_FindSquareShortestPathTest( void );
		void m_FindInfinityShortestPathTest( void );
		void m_FindTurtleShortestPathTest( void );
		void m_FindDoubleTriangleShortest0To5PathTest( void );
		void m_FindDoubleTriangleShortest2To5PathTest( void );
		void m_FindSpiderNetShortest0To7PathTest( void );
		void m_FindSpiderNetShortest5To0PathTest( void );
		void m_FindGrapeShortest0To16PathTest( void );
		void m_FindGrapeShortest9To13PathTest( void );
		
		bool m_CheckPtr( const std::shared_ptr < CPathModel > actualTree );

	public:
		CBellmanFordAlgorithmTest( void );
		virtual ~CBellmanFordAlgorithmTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_BELLMANFORDALGORITHMTEST_H_ */