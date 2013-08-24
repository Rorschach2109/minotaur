/*
 * This file is part of minotaur.
 *
 * File: DijkstraAlgorithmTest.h
 * Brief: Declaration of dijkstra algorithm test class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_DIJKSTRAALGORITHMTEST_H_
#define _MINOTAUR_DIJKSTRAALGORITHMTEST_H_

#include "AbstractMinotaurModelTest.h"
#include "DijkstraAlgorithm.h"
#include "SubGraphComparer.h"

#include <memory>

namespace Minotaur
{

class CDijkstraAlgorithmTest : public AbstractMinotaurModelTest
{
	private:
		CDijkstraAlgorithm m_dijkstraAlgorithmTest;
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
		CDijkstraAlgorithmTest( void );
		virtual ~CDijkstraAlgorithmTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_DIJKSTRAALGORITHMTEST_H_ */