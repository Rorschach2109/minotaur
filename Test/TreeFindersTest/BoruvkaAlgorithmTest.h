/*
 * This file is part of minotaur.
 *
 * File: BoruvkaAlgorithmTest.h
 * Brief: Declaration of boruvka algorithm test class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */

#ifndef _MINOTAUR_BORUVKAALGORITHMTEST_H_
#define _MINOTAUR_BORUVKAALGORITHMTEST_H_

#include "BoruvkaAlgorithm.h"

namespace Minotaur
{
	
class CBoruvkaAlgorithmTest
{
	private:
		CBoruvkaAlgorithm m_boruvkaAlgorithmTest;
	
		void m_FindMSTTest( void );
	
	public:
		CBoruvkaAlgorithmTest( void );
		virtual ~CBoruvkaAlgorithmTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_BORUVKAALGORITHMTEST_H_ */