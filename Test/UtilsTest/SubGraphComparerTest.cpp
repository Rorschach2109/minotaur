/*
 * This file is part of minotaur.
 *
 * File: SubGraphComparerTest.cpp
 * Brief: Implementation of subgraph comparer test class.
 *
 * Date: 19.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "SubGraphComparerTest.h"
#include "TreeModel.h"

#include "MinotaurTestDefines.h"

#include <memory>

using namespace Minotaur;

CSubGraphComparerTest::CSubGraphComparerTest( void ) : 
	AbstractMinotaurModelTest(), 
	m_subGraphComparer( CSubGraphComparer() )
{
	m_AreEqualTest();
}

CSubGraphComparerTest::~CSubGraphComparerTest( void )
{
	
}
		
void CSubGraphComparerTest::m_AreEqualTest( void )
{
	t_testNumber += 2;
	
	std::shared_ptr < CTreeModel > validTreeModel = t_subGraphModelFactory.spiderNetModelMSTKruskal;
	std::shared_ptr < CTreeModel > invalidTreeModel = t_subGraphModelFactory.doubleTriangleModelMSTKruskal;
	
	bool expectedValue = true;
	
	bool validActualValue = m_subGraphComparer.AreEqual( *validTreeModel, *validTreeModel );
	bool invalidActualValue = m_subGraphComparer.AreEqual( *validTreeModel, *invalidTreeModel );
	
	CHECK_EQUAL( expectedValue, validActualValue, t_failedTestNumber );
	CHECK_NOT_EQUAL( expectedValue, invalidActualValue, t_failedTestNumber );

	validTreeModel.reset();
	invalidTreeModel.reset();
}
