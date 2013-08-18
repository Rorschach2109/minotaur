/*
 * This file is part of minotaur.
 *
 * File: TreeModelTest.h
 * Brief: Declaration of tree model test class.
 *
 * Date: .08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#ifndef _MINOTAUR_TREEMODELTEST_H_
#define _MINOTAUR_TREEMODELTEST_H_

#include "AbstractMinotaurModelTest.h"
#include "TreeModel.h"

namespace Minotaur
{
	
class CTreeModelTest : public AbstractMinotaurModelTest
{
	private:
		CTreeModel m_treeModelTest;
	
		void m_VerifySubGraphTopologyTest( void );
		
	public:
		CTreeModelTest( void );
		virtual ~CTreeModelTest( void );
};
	
} // namespace Minotaur

#endif /* _MINOTAUR_TREEMODELTEST_H_ */