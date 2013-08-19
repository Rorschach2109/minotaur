/*
 * This file is part of minotaur.
 *
 * File: GraphComparerTest.cpp
 * Brief: Implementation of graph comparer test class.
 *
 * Date: 19.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "GraphComparerTest.h"
#include "TreeModel.h"

#include "TestDefines.h"

#include <memory>

using namespace Minotaur;

CGraphComparerTest::CGraphComparerTest( void ) : 
	AbstractMinotaurModelTest(), 
	m_graphComparer( CGraphComparer() )
{
	m_AreEqualTest();
}

CGraphComparerTest::~CGraphComparerTest( void )
{
	
}
		
void CGraphComparerTest::m_AreEqualTest( void )
{
	++t_testNumber;
	
	std::shared_ptr < IGraphModel > validGraphModel = t_graphModelFactory.infinityGraphModel;
	std::shared_ptr < IGraphModel > invalidGraphModel = t_graphModelFactory.turtleGraphModel;
	
	bool expectedValue = true;
	
	bool validActualValue = m_graphComparer.AreEqual( *validGraphModel, *validGraphModel );
	bool invalidActualValue = m_graphComparer.AreEqual( *validGraphModel, *invalidGraphModel );
	
	CHECK_EQUAL( expectedValue, validActualValue );
	CHECK_NOT_EQUAL( expectedValue, invalidActualValue );

	validGraphModel.reset();
	invalidGraphModel.reset();
}
