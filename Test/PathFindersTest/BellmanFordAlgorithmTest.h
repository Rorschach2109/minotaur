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

#include "BellmanFordAlgorithm.h"

namespace Minotaur
{
	
class CBellmanFordAlgorithmTest
{
	private:
		CBellmanFordAlgorithm m_bellmanFordAlgorithmTest;
	
		void m_FindShortestPathTest( void );
	
	public:
		CBellmanFordAlgorithmTest( void );
		virtual ~CBellmanFordAlgorithmTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_BELLMANFORDALGORITHMTEST_H_ */