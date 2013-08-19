/*
 * This file is part of minotaur.
 *
 * File: SubGraphComparerTest.h
 * Brief: Declaration of subgraph comparer test class.
 *
 * Date: 19.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_SUBGRAPHCOMPARERTEST_H_
#define _MINOTAUR_SUBGRAPHCOMPARERTEST_H_

#include "SubGraphComparer.h"
#include "AbstractMinotaurModelTest.h"

namespace Minotaur
{
	
class CSubGraphComparerTest : public AbstractMinotaurModelTest
{
	private:
		CSubGraphComparer m_subGraphComparer;
	
		void m_AreEqualTest( void );
	
	public:
		CSubGraphComparerTest( void );
		virtual ~CSubGraphComparerTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_SUBGRAPHCOMPARERTEST_H_ */