/*
 * This file is part of minotaur.
 *
 * File: GraphComparerTest.h
 * Brief: Declaration of graph comparer test class.
 *
 * Date: 19.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_GRAPHCOMPARERTEST_H_
#define _MINOTAUR_GRAPHCOMPARERTEST_H_

#include "GraphComparer.h"
#include "AbstractMinotaurModelTest.h"

namespace Minotaur
{
	
class CGraphComparerTest : public AbstractMinotaurModelTest
{
	private:
		CGraphComparer m_graphComparer;
	
		void m_AreEqualTest( void );
	
	public:
		CGraphComparerTest( void );
		virtual ~CGraphComparerTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_GRAPHCOMPARERTEST_H_ */