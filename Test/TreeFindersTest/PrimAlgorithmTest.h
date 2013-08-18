/*
 * This file is part of minotaur.
 *
 * File: PrimAlgorithmTest.h
 * Brief: Declaration of prim algorithm test class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_PRIMALGORITHMTEST_H_
#define _MINOTAUR_PRIMALGORITHMTEST_H_

#include "PrimAlgorithm.h"

namespace Minotaur
{
	
class CPrimAlgorithmTest
{
	private:
		CPrimAlgorithm m_primAlgorithmTest;
	
		void m_FindMSTTest( void );
	
	public:
		CPrimAlgorithmTest( void );
		virtual ~CPrimAlgorithmTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_PRIMALGORITHMTEST_H_ */