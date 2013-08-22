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

namespace Minotaur
{
	
class CDijkstraAlgorithmTest : public AbstractMinotaurModelTest
{
	private:
		CDijkstraAlgorithm m_dijkstraAlgorithmTest;
	
		void m_FindShortestPathTest( void );
	
	public:
		CDijkstraAlgorithmTest( void );
		virtual ~CDijkstraAlgorithmTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_DIJKSTRAALGORITHMTEST_H_ */