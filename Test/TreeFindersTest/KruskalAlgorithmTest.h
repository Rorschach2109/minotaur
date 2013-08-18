/*
 * This file is part of minotaur.
 *
 * File: KruskalAlgorithmTest.h
 * Brief: Declaration of kruskal algorithm test class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_KRUSKALALGORITHMTEST_H_
#define _MINOTAUR_KRUSKALALGORITHMTEST_H_

#include "KruskalAlgorithm.h"

namespace Minotaur
{
	
class CKruskalAlgorithmTest
{
	private:
		CKruskalAlgorithm m_kruskalAlgorithmTest;
	
		void m_FindMSTTest( void );
	
	public:
		CKruskalAlgorithmTest( void );
		virtual ~CKruskalAlgorithmTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_KRUSKALALGORITHMTEST_H_ */