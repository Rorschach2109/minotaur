/*
 * This file is part of minotaur.
 *
 * File: KruskalAlgorithmTest.cpp
 * Brief: Implementation of kruskal algorithm test class.
 *
 * Date: .07.2013
 * Author: Andrzej Korycinski
 *
 * */
 
#include "KruskalAlgorithmTest.h"
#include "NodeModel.h"

#include "TestDefines.h"

using namespace Minotaur;

CKruskalAlgorithmTest::CKruskalAlgorithmTest( void ) : 
	m_kruskalAlgorithmTest( CKruskalAlgorithm() ),
	m_subGraphComparer( CSubGraphComparer() )
{
	m_FindMSTTest();
}

CKruskalAlgorithmTest::~CKruskalAlgorithmTest( void )
{
	
}

void CKruskalAlgorithmTest::m_FindMSTTest( void )
{
	++t_testNumber;

	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.largeModelMSTKruskal;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.doubleTriangleModelMSTKruskal;
	
	std::shared_ptr < CTreeModel > actualTree = m_kruskalAlgorithmTest.FindMST( *( t_graphModelFactory.largeGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue );
	}
	
	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}

bool CKruskalAlgorithmTest::m_CheckPtr( const std::shared_ptr < CTreeModel > actualTree )
{
	bool nullPtr = ( nullptr == actualTree );
	
	CHECK_NOT_EQUAL( nullptr, actualTree );
		
	return nullPtr;
}
