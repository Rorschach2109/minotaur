/*
 * This file is part of minotaur.
 *
 * File: SubGraphTest.h
 * Brief: Declaration of subgraph test class.
 *
 * Date: .08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_SUBGRAPHTEST_H_
#define _MINOTAUR_SUBGRAPHTEST_H_

#include "AbstractMinotaurModelTest.h"
#include "SubGraphModel.h"

namespace Minotaur
{
	
class CSubGraphModelTest : public AbstractMinotaurModelTest
{
	private:
		CSubGraphModel m_subGraphTest;
	
		void m_VerifySubGraphTopologyTest( void );
		void m_GetSubGraphEdgesTest( void );
		
	public:
		CSubGraphModelTest( void );
		virtual ~CSubGraphModelTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_SUBGRAPHTEST_H_ */