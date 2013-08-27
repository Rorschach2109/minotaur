/*
 * This file is part of minotaur.
 *
 * File: PrimAlgorithmTest.cpp
 * Brief: Implementation of prim algorithm test class.
 *
 * Date: 23.08.2013
 * Author: Andrzej Korycinski
 *
 * */
 
#include "PrimAlgorithmTest.h"
#include "NodeModel.h"

#include "MinotaurTestDefines.h"

using namespace Minotaur;

CPrimAlgorithmTest::CPrimAlgorithmTest( void ) : 
	m_primAlgorithmTest( CPrimAlgorithm() ),
	m_subGraphComparer( CSubGraphComparer() )
{
	m_FindSquareMSTTest();
	m_FindInfinityMSTTest();
	m_FindTurtleMSTTest();
	m_FindDoubleTriangleMSTTest();
	m_FindSpiderNetMSTTest();
	m_FindGrapeMSTTest();
}

CPrimAlgorithmTest::~CPrimAlgorithmTest( void )
{
	
}

bool CPrimAlgorithmTest::m_CheckPtr( const std::shared_ptr < CTreeModel > actualTree )
{
	++t_testNumber;
	
	bool nullPtr = ( nullptr == actualTree );
	
	CHECK_NOT_EQUAL( nullptr, actualTree, t_failedTestNumber );
		
	return nullPtr;
}

void CPrimAlgorithmTest::m_FindSquareMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.squareModelMSTPrim;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.turtleModelMSTPrim;
	
	std::shared_ptr < CTreeModel > actualTree = m_primAlgorithmTest.FindMST( *( t_graphModelFactory.squareGraphModel ), rootNode);

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

void CPrimAlgorithmTest::m_FindInfinityMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 2 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.infinityModelMSTPrim;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.turtleModelMSTPrim;
	
	std::shared_ptr < CTreeModel > actualTree = m_primAlgorithmTest.FindMST( *( t_graphModelFactory.infinityGraphModel ), rootNode);
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

void CPrimAlgorithmTest::m_FindTurtleMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.turtleModelMSTPrim;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.squareModelMSTPrim;
	
	std::shared_ptr < CTreeModel > actualTree = m_primAlgorithmTest.FindMST( *( t_graphModelFactory.turtleGraphModel ), rootNode);
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

void CPrimAlgorithmTest::m_FindDoubleTriangleMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.doubleTriangleModelMSTPrim;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.turtleModelMSTPrim;
	
	std::shared_ptr < CTreeModel > actualTree = m_primAlgorithmTest.FindMST( *( t_graphModelFactory.doubleTriangleGraphModel ), rootNode);
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

void CPrimAlgorithmTest::m_FindSpiderNetMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 0, 2 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.spiderNetModelMSTPrim;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.spiderNetModelMSTKruskal;
	
	std::shared_ptr < CTreeModel > actualTree = m_primAlgorithmTest.FindMST( *( t_graphModelFactory.spiderNetGraphModel ), rootNode);
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

void CPrimAlgorithmTest::m_FindGrapeMSTTest( void )
{
	CNodeModel rootNode = CNodeModel( 0, 2, 0 );
	std::shared_ptr < CTreeModel > expectedValidTree = t_subGraphModelFactory.grapeModelMSTPrim;
	std::shared_ptr < CTreeModel > invalidTree = t_subGraphModelFactory.doubleTriangleModelMSTPrim;
	
	std::shared_ptr < CTreeModel > actualTree = m_primAlgorithmTest.FindMST( *( t_graphModelFactory.grapeGraphModel ), rootNode);
	if ( !m_CheckPtr(actualTree) )
	{
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
