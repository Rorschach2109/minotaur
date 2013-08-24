/*
 * This file is part of minotaur.
 *
 * File: KruskalAlgorithmTest.cpp
 * Brief: Implementation of kruskal algorithm test class.
 *
 * Date: 21.08.2013
 * Author: Andrzej Korycinski
 *
 * */
 
#include "KruskalAlgorithmTest.h"
#include "NodeModel.h"

#include "MinotaurTestDefines.h"

using namespace Minotaur;

CKruskalAlgorithmTest::CKruskalAlgorithmTest( void ) : 
	m_kruskalAlgorithmTest( CKruskalAlgorithm() ),
	m_subGraphComparer( CSubGraphComparer() )
{
	m_FindSquareMSTTest();
	m_FindInfinityMSTTest();
	m_FindTurtleMSTTest();
	m_FindDoubleTriangleMSTTest();
	m_FindSpiderNetMSTTest();
	m_FindGrapeMSTTest();
}

CKruskalAlgorithmTest::~CKruskalAlgorithmTest( void )
{
	
}

bool CKruskalAlgorithmTest::m_CheckPtr( const std::shared_ptr < CTreeModel > actualTree )
{
	++t_testNumber;
	
	bool nullPtr = ( nullptr == actualTree );
	
	CHECK_NOT_EQUAL( nullptr, actualTree, t_failedTestNumber );
		
	return nullPtr;
}

void CKruskalAlgorithmTest::m_FindSquareMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.squareModelMSTKruskal;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.turtleModelMSTKruskal;
	
	std::shared_ptr < CTreeModel > actualTree = m_kruskalAlgorithmTest.FindMST( *( t_graphModelFactory.squareGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}

void CKruskalAlgorithmTest::m_FindInfinityMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 2 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.infinityModelMSTKruskal;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.turtleModelMSTKruskal;
	
	std::shared_ptr < CTreeModel > actualTree = m_kruskalAlgorithmTest.FindMST( *( t_graphModelFactory.infinityGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}

void CKruskalAlgorithmTest::m_FindTurtleMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.turtleModelMSTKruskal;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.squareModelMSTKruskal;
	
	std::shared_ptr < CTreeModel > actualTree = m_kruskalAlgorithmTest.FindMST( *( t_graphModelFactory.turtleGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;
		
		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}

void CKruskalAlgorithmTest::m_FindDoubleTriangleMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.doubleTriangleModelMSTKruskal;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.turtleModelMSTKruskal;
	
	std::shared_ptr < CTreeModel > actualTree = m_kruskalAlgorithmTest.FindMST( *( t_graphModelFactory.doubleTriangleGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}

void CKruskalAlgorithmTest::m_FindSpiderNetMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.spiderNetModelMSTKruskal;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.doubleTriangleModelMSTKruskal;
	
	std::shared_ptr < CTreeModel > actualTree = m_kruskalAlgorithmTest.FindMST( *( t_graphModelFactory.spiderNetGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}
	
	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}

void CKruskalAlgorithmTest::m_FindGrapeMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.grapeModelMSTKruskal;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.doubleTriangleModelMSTKruskal;
	
	std::shared_ptr < CTreeModel > actualTree = m_kruskalAlgorithmTest.FindMST( *( t_graphModelFactory.grapeGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
		t_testNumber += 2;

		bool expectedValue = true;
		
		bool actualValidValue = m_subGraphComparer.AreEqual(*expectedValidTree, *actualTree);
		bool actualInvalidValue = m_subGraphComparer.AreEqual(*invalidTree, *actualTree);
		
		CHECK_EQUAL( expectedValue, actualValidValue, t_failedTestNumber );
		CHECK_NOT_EQUAL( expectedValue, actualInvalidValue, t_failedTestNumber );
	}

	expectedValidTree.reset();
	invalidTree.reset();
	actualTree.reset();
}
