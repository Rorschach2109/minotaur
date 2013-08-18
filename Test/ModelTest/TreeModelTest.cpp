/*
 * This file is part of minotaur.
 *
 * File: TreeModelTest.cpp
 * Brief: Implementation of tree model test class.
 *
 * Date: 18.08.2013
 * Author: Andrzej Korycinski
 * 
 * */

#include "TreeModelTest.h"
#include "TestDefines.h"

using namespace Minotaur;

CTreeModelTest::CTreeModelTest( void ) : 
	AbstractMinotaurModelTest(),
	m_treeModelTest( CTreeModel( *t_graphModelFactory.infinityGraphModel, t_graphModelFactory.subGraphModelFactory.infinityModelEdgeDefinition ) )
{
	m_VerifySubGraphTopologyTest();
}

CTreeModelTest::~CTreeModelTest( void )
{
	
}

void CTreeModelTest::m_VerifySubGraphTopologyTest( void )
{
	bool expectedValue = true;
	
	bool actualValue = m_treeModelTest.VerifySubGraphTopology( );
	
	CHECK_EQUAL( expectedValue, actualValue );
}