/*
 * This file is part of minotaur.
 *
 * File: PathModelTest.h
 * Brief: Declaration of path model test class.
 *
 * Date: .08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_PATHMODELTEST_H_
#define _MINOTAUR_PATHMODELTEST_H_

#include "AbstractMinotaurModelTest.h"
#include "PathModel.h"

namespace Minotaur
{
	
class CPathModelTest : public AbstractMinotaurModelTest
{
	private:
		CPathModel m_pathModelTest;
		
		void m_VerifySubGraphTopology( void );
		
	public:
		CPathModelTest( void );
		virtual ~CPathModelTest( void );
	
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_PATHMODELTEST_H_ */